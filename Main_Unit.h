//---------------------------------------------------------------------------

#ifndef Main_UnitH
#define Main_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <Registry.hpp>
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TSpeedButton *Cracker_SpeedButton;
        TSpeedButton *Restaurer_SpeedButton;
        TSpeedButton *Femer_SpeedButton;
        TSpeedButton *Minimise_SpeedButton;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TOpenDialog *OpenDialog1;
        TLabel *Label3;
        void __fastcall Femer_SpeedButtonClick(TObject *Sender);
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Minimise_SpeedButtonClick(TObject *Sender);
        void __fastcall Cracker_SpeedButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Restaurer_SpeedButtonClick(TObject *Sender);
        void __fastcall GroupBox2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall GroupBox1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Label5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

        __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
