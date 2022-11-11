#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


typedef struct date_de_naissance 
{
int jour ;
int mois ;
int annee ;
}DATE ;
typedef struct parametres_de_connexion 
{
char identifiant[20] ;
char mot_de_passe[20] ;
}pdc;


typedef struct user
{ char cin[20] ;
  char nom[20] ;
  char prenom[20] ;
  char genre[30] ;
  DATE  date ;
  pdc pcx ;
  char role[20] ;
  char num_tel[100] ;
  char ville [100] ;
  int vote ;
  int num_bv ;

 }user ;
int ajouter_user(char * filename, user u);


void modifier_user(char * filename,user nouv ,char cin[]) ;
int supprimer_user(char cin[]) ;
int chercher_user(char cin[]) ;



#endif
