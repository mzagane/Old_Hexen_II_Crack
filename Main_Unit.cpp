/*******************************************************************************
*      Fichier            : Main_Unit.cpp                                      *
*      Programmeur        : Arbman                                             *
*      Email              : arbman84@yahoo.fr                                  *
*      site web           : http://arbman.ifrance.com                          *
*      Date source        : vendredi 25 janvier 2008                           *
*      Version source     : 1.24.01.2008                                       *
*      Langage            : Borland C++ Builder version 6                      *
*      Type licence       : libre.                                             *
*      Modification       : /                                                  *
*******************************************************************************/

//------------------------------------------------------------------------------
#include <vcl.h>
#include "Cracker.h"// contient la fonction du crackage
#pragma hdrstop

#include "Main_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

# define Taille_Reelle 674816

TMain_Form *Main_Form;
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
}
/*-----------------------------------------------------------------------------*
*        click sur le bouton "X" (pour fermer l'application)                   *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Femer_SpeedButtonClick(TObject *Sender)
{
          Application->Terminate();// Fermer l'application
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        l'evenement OnMouseDown de Panel1                                     *
*        pour déplacer notre fenêtre principale                                *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

          // code pour déplacer notre fenêtre principale -----------------------
          ReleaseCapture();
          Panel1->Cursor=crSizeAll;
          SendMessage(Handle, WM_SYSCOMMAND, 0xF012, 0);
          Panel1->Cursor=crDefault;
          //--------------------------------------------------------------------
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur le bouton "--" (pour minimiser l'application)               *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Minimise_SpeedButtonClick(TObject *Sender)
{
          Application->Minimize();
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*           click sur le bouton "Cracker"                                      *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Cracker_SpeedButtonClick(TObject *Sender)
{

             int Taille_Calculer;// la taille calculer du fichier à cracker.

             OpenDialog1->Title="ouvrir le fichier h2.exe";// titre de la boite "opendialog"

             if(OpenDialog1->Execute())
             {
                      // calculer la taille du fichier--------------------------
                      HANDLE hFichie_A_Cracker;
                      hFichie_A_Cracker = CreateFile(OpenDialog1->FileName.c_str(), 0, 0, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);
                      Taille_Calculer=GetFileSize(hFichie_A_Cracker,0);
                      CloseHandle(hFichie_A_Cracker);
                      //--------------------------------------------------------
                      if(Taille_Reelle==Taille_Calculer)
                      {
                                SetFileAttributes(OpenDialog1->FileName.c_str(), FILE_ATTRIBUTE_NORMAL);// éliminer les protection(read only,system file,...)
                                switch (Cracker(OpenDialog1->FileName.c_str(),0x8E3,0x0F))
                                {
                                       case 0 : // la fonction est réussi pour le premier octet
                                       {
                                               MessageDlg("fichier cracké avec succè, vous pouvez maintenant jouez sans CD!!",mtInformation,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;

                                       case 1 :
                                       {
                                               MessageDlg("Impossible d'ouvrir le fichier, vérifier que le programme n'est pas en cours d'exécution",mtError,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;

                                       case 2 :
                                       {
                                               MessageDlg("Impossible d'écrire dans le fichier, vérifier que le programme n'est pas en cours d'exécution",mtError,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;

                                       case 3 :
                                       {
                                               MessageDlg("Impossible de positioner le cursur de l'écriture dans l'emplacement aproprie, vérifier que le programme n'est pas en cours d'exécution",mtError,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;
                                }
                      }
                      else
                      {
                                MessageDlg("La taille du fichier est incorrecte, probablement pas le bon fichier ou pas la bonne version veuillez vérifier que le fichier est :'h2.exe' et la version est : 'II'",mtError,TMsgDlgButtons() << mbOK,0);
                      }
             }
}
/*-----------------------------------------------------------------------------*
*          l'evenement OnCreate de La Form : Main_Form                         *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
             OpenDialog1->Filter="Hexen II|h2.exe|Tout les fichiers(*.*)|*.*";
             OpenDialog1->InitialDir="C:\\Hexen II";
             Label5->Hint="Clicker ici pour visiter mon site web où vous\ntrouvez le code source de ce crack\net autres crack avec leurs codes\nsources et autres open source software.";
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*                   click sur le bouton "Restaurer"                            *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Restaurer_SpeedButtonClick(TObject *Sender)
{
             int Taille_Calculer;// la taille calculer du fichier à cracker.
             OpenDialog1->Title="ouvrir le fichier h2.exe";// titre de la boite "opendialog"

             if(OpenDialog1->Execute())
             {
                      // calculer la taille du fichier--------------------------
                      HANDLE hFile;
                      hFile = CreateFile(OpenDialog1->FileName.c_str(), 0, 0, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);
                      Taille_Calculer=GetFileSize(hFile,0);
                      CloseHandle(hFile);
                      //--------------------------------------------------------
                      if(Taille_Reelle==Taille_Calculer)
                      {
                                SetFileAttributes(OpenDialog1->FileName.c_str(), FILE_ATTRIBUTE_NORMAL);// éliminer les protection(read only,system file)
                                switch (Cracker(OpenDialog1->FileName.c_str(),0x8E3,0x0A))
                                {
                                       case 0 : // la fonction est réussi pour le premier octet
                                       {
                                               MessageDlg("fichier restauré avec succè, Maintenant il faut le CD pour jouez!!!",mtInformation,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;

                                       case 1 :
                                       {
                                               MessageDlg("Impossible d'ouvrir le fichier, vérifier que le programme n'est pas en cours d'exécution",mtError,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;

                                       case 2 :
                                       {
                                               MessageDlg("Impossible d'écrire dans le fichier, vérifier que le programme n'est pas en cours d'exécution",mtError,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;

                                       case 3 :
                                       {
                                               MessageDlg("Impossible de positioner le cursur de l'écriture dans l'emplacement aproprie, vérifier que le programme n'est pas en cours d'exécution",mtError,TMsgDlgButtons() << mbOK,0);
                                       }
                                       break;
                                }
                      }
                      else
                      {
                                MessageDlg("La taille du fichier est incorrecte, probablement pas le bon fichier ou pas la bonne version veuillez vérifier que le fichier est :'h2.exe' et la version est : 'II'",mtError,TMsgDlgButtons() << mbOK,0);
                      }
             }

}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        l'evenement OnMouseDown de GroupBox2                                  *
*        pour déplacer notre fenêtre principale                                *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::GroupBox2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
          ReleaseCapture();
          GroupBox2->Cursor=crSizeAll;
          SendMessage(Handle, WM_SYSCOMMAND, 0xF012, 0);
          GroupBox2->Cursor=crDefault;
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        l'evenement OnMouseDown de GroupBox1                                  *
*        pour déplacer notre fenêtre principale                                *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::GroupBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
          ReleaseCapture();
          GroupBox1->Cursor=crSizeAll;
          SendMessage(Handle, WM_SYSCOMMAND, 0xF012, 0);
          GroupBox1->Cursor=crDefault;
}
//------------------------------------------------------------------------------


/*-----------------------------------------------------------------------------*
*        click sur le label1 "http://zaa.." (pour visiter mon site web)        *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Label5Click(TObject *Sender)
{
          ShellExecute(0, "open","http://arbman.ifrance.com",0,0,SW_SHOWDEFAULT);                
}
//---------------------------------------------------------------------------
