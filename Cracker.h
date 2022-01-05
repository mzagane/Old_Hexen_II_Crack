/*******************************************************************************
*      Fichier            : Cracker.h                                          *
*      Auteur             : Arbman                                             *
*      Email              : arbman84@yahoo.fr                                  *
*      site web           : http://arbman.ifrance.com                          *
*      Date source        : jeudi 24 janvier 2008                              *
*      Version source     : 1.24.01.2008                                       *
*      Langage            : C++                                                *
*      Type licence       : libre.                                             *
*      Modification       : vendredi 25 janvier 2008                           *
*******************************************************************************/


#include <stdio.h>


/*******************************************************************************
*-----Fonction: Cracker(char *Chemin_Fichier_a_Cracker,long offset,long valeur)*
*                                                                              *
*-----D�scription: Cette fonction permet d'�crir la valeur 'valeur' �          *
*     l'offset 'offset' dans le  fichier dont le chemin est                    *
*     'Chemin_Fichier_a_Cracker'                                               *
*                                                                              *
*-----Pram�tres:                                                               *
*              - char *Chemin_Fichier_a_Cracker : chemin complet du fichier �  *
*                cracker                                                       *
*              - long offset : l'emplacement de l'ecriture (en hexad�cimale)   *
*              - long valeur : la valeur � ecrir (en hexad�cimale)             *
*                                                                              *
*-----valeurs retourn�es :                                                     *
*              0 : la fonction r�ussi                                          *
*              1 : probl�me d'ouverture du fichier                             *
*              2 : probl�me d'�criture dans le fichier                         *
*              3 : probl�me du positionnement du curseur d'�criture            *
*                                                                              *
*******************************************************************************/
int Cracker(char *Chemin_Fichier_a_Cracker,long offset,long valeur)
{

             FILE * Pointeur_Fichier_a_Cracker;// pointeur vers le fichier a cracker

             //  ouverture du fichier "Chemin_Fichier_a_Cracker" en mode lecture
             // binaire (read/binary).
             if((Pointeur_Fichier_a_Cracker = fopen(Chemin_Fichier_a_Cracker,"rb+"))!=NULL)
             {
                     // positionnement du curseur d'�criture a l'offset 'offset'
                     if(fseek (Pointeur_Fichier_a_Cracker,offset,SEEK_SET)==0)
                     // si le positionnement du curseur d'�criture est r�ussi
                     {
                               // �criture dans le fichier point� par
                               //"Pointeur_Fichier_a_Cracker" � la position 'offset'
                               // de la valeur 'valeur'
                               if(fputc(valeur,Pointeur_Fichier_a_Cracker)!=EOF)
                               {
                                       fclose(Pointeur_Fichier_a_Cracker);
                                       return 0; // la fonction r�ussi
                               }
                               else //s'il y a un probl�me d'�criture dans le fichier
                               {
                                       fclose(Pointeur_Fichier_a_Cracker);
                                       return 2;
                               }
                     }
                     else// s'il y a un probl�me de positionnement du curseur d'�criture
                     {
                               fclose(Pointeur_Fichier_a_Cracker);
                               return 3;
                     }

             }
             else // s'il y a un probl�me avec l'ouverture du fichier
             {
                     fclose(Pointeur_Fichier_a_Cracker);
                     return 1;
             }
}
//------------------------------------------------------------------------------
