#include <stdio.h>
#include <string.h>
#include"point.h"


int main()
{
     char cin[20] ;
     user u , nouv ;
     strcpy(u.cin,"13281236");
     strcpy(u.nom,"nour");
     strcpy(u.prenom,"aboussaoud");
     strcpy(u.genre,"femme");
     u.date.jour=15 ;
     u.date.mois=7 ;
     u.date.annee=2001 ;
     strcpy(u.pcx.identifiant,"nourab");
     strcpy(u.pcx.mot_de_passe,"123456");
     strcpy(u.num_tel,"27596886") ;
     strcpy(u.ville,"gabes") ;
     u.vote=0 ;
     u.num_bv=1 ;

    strcpy(u.cin,"13281436");
     strcpy(u.nom,"nouuur");
     strcpy(u.prenom,"aboussaoud");
     strcpy(u.genre,"femme");
     u.date.jour=18 ;
     u.date.mois=9 ;
     u.date.annee=2001 ;
     strcpy(u.pcx.identifiant,"nourb");
     strcpy(u.pcx.mot_de_passe,"12456");
     strcpy(u.num_tel,"27596887") ;
     strcpy(u.ville,"tunis") ;
     u.vote=0 ;
     u.num_bv=1 ;

   ajouter_user("text.txt",  u) ;
   ajouter_user("text.txt",  nouv) ;
  

return 0 ;
}
