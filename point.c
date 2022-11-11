#include <stdio.h>
#include <string.h>
#include"point.h"
int ajouter_user(char * filename, user u)
{
FILE *f;
f=fopen(filename,"a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,u.date.jour,u.date.mois,u.date.annee,u.pcx.identifiant,u.pcx.mot_de_passe,u.num_tel,u.ville,u.role,u.vote,u.num_bv);
fclose(f);
return 1 ;
}
else return 0 ;

}

void modifier_user(char * filename,user nouv ,char cin[])
{

    FILE*f,*fich;
    user u ;
             f=fopen(filename,"r");
             fich=fopen("temputil.txt","a");
            do
            {
                fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",&u.cin,u.nom,u.prenom,u.genre,&u.date.jour,&u.date.mois,&u.date.annee,u.pcx.identifiant,u.pcx.mot_de_passe,u.role,u.num_tel,u.ville,u.vote,u.num_bv);
            if(strcmp(cin,u.cin)==0)
            {

            fprintf(fich,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",nouv.cin,nouv.nom,nouv.prenom,nouv.genre,nouv.date.jour,nouv.date.mois,nouv.date.annee,nouv.pcx.identifiant,nouv.pcx.mot_de_passe,nouv.role,nouv.num_tel,nouv.ville,nouv.vote,nouv.num_bv);
            }
else
    fprintf(fich,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,u.date.jour,u.date.mois,u.date.annee,u.pcx.identifiant,u.pcx.mot_de_passe,u.role,u.num_tel,u.ville,u.vote,u.num_bv);

            }while(!feof(f));
            fclose(f);
            fclose(fich);
            remove("user.txt");
            rename("temputil.txt","user.txt");

    }



int supprimer_user(char cin[])
{



 FILE*f,*fich;
    int tr ;
    user u ;
             f=fopen("user.txt","r");
             fich=fopen("temputil.txt","a");
            do
            {
                fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",&u.cin,u.nom,u.prenom,u.genre,&u.date.jour,&u.date.mois,&u.date.annee,u.pcx.identifiant,u.pcx.mot_de_passe,u.role,&u.num_tel,u.ville,&u.vote,&u.num_bv);
            if(strcmp(cin,u.cin)==0)
            {
               tr=1 ;
            }
else
    fprintf(fich,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,u.date.jour,u.date.mois,u.date.annee,u.pcx.identifiant,u.pcx.mot_de_passe,u.role,u.num_tel,u.ville,u.vote,u.num_bv);

            }while(!feof(f));
            fclose(f);
            fclose(fich);
            remove("user.txt");
            rename("temputil.txt","user.txt");
            return tr ;

    }


    int chercher_user(char cin[])
{
int x=0;
user u;
FILE* f;
f=fopen("user.txt","r");
 do
            {
                fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d %d \n",&u.cin,u.nom,u.prenom,u.genre,&u.date.jour,&u.date.mois,&u.date.annee,u.pcx.identifiant,u.pcx.mot_de_passe,u.role,&u.num_tel,u.ville,&u.vote,&u.num_bv);

	if(strcmp(u.cin,cin)==0)
	{
		x=1;
		}


            }while(!feof(f));

fclose(f);
return x;
}
