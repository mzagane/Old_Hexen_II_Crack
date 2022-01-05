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
*-----Déscription: Cette fonction permet d'écrir la valeur 'valeur' à          *
*     l'offset 'offset' dans le  fichier dont le chemin est                    *
*     'Chemin_Fichier_a_Cracker'                                               *
*                                                                              *
*-----Pramètres:                                                               *
*              - char *Chemin_Fichier_a_Cracker : chemin complet du fichier à  *
*                cracker                                                       *
*              - long offset : l'emplacement de l'ecriture (en hexadécimale)   *
*              - long valeur : la valeur à ecrir (en hexadécimale)             *
*                                                                              *
*-----valeurs retournées :                                                     *
*              0 : la fonction réussi                                          *
*              1 : problème d'ouverture du fichier                             *
*              2 : problème d'écriture dans le fichier                         *
*              3 : problème du positionnement du curseur d'écriture            *
*                                                                              *
*******************************************************************************/
int Cracker(char *Chemin_Fichier_a_Cracker,long offset,long valeur)
{

             FILE * Pointeur_Fichier_a_Cracker;// pointeur vers le fichier a cracker

             //  ouverture du fichier "Chemin_Fichier_a_Cracker" en mode lecture
             // binaire (read/binary).
             if((Pointeur_Fichier_a_Cracker = fopen(Chemin_Fichier_a_Cracker,"rb+"))!=NULL)
             {
                     // positionnement du curseur d'écriture a l'offset 'offset'
                     if(fseek (Pointeur_Fichier_a_Cracker,offset,SEEK_SET)==0)
                     // si le positionnement du curseur d'écriture est réussi
                     {
                               // écriture dans le fichier pointé par
                               //"Pointeur_Fichier_a_Cracker" à la position 'offset'
                               // de la valeur 'valeur'
                               if(fputc(valeur,Pointeur_Fichier_a_Cracker)!=EOF)
                               {
                                       fclose(Pointeur_Fichier_a_Cracker);
                                       return 0; // la fonction réussi
                               }
                               else //s'il y a un problème d'écriture dans le fichier
                               {
                                       fclose(Pointeur_Fichier_a_Cracker);
                                       return 2;
                               }
                     }
                     else// s'il y a un problème de positionnement du curseur d'écriture
                     {
                               fclose(Pointeur_Fichier_a_Cracker);
                               return 3;
                     }

             }
             else // s'il y a un problème avec l'ouverture du fichier
             {
                     fclose(Pointeur_Fichier_a_Cracker);
                     return 1;
             }
}
//------------------------------------------------------------------------------
