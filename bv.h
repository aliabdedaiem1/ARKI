
#include <stdio.h>


typedef struct bv{
char idbv[20];
char idagent[20];
char capacite[20];
char capobs[20] ;
char adresse[20];
char salle[20];
char gouvernerat[20];}bv;

typedef struct user
{
  char prenom[20] ;
  char role[20];
  char genre[30] ;


 }user ;


int ajouter(char *filename, bv p );
void modifier( char *filename, char id[], bv p );
void supprimer(char *filename, char id[] );
int chercher(char *filename, char *);
void supprimer_bv( bv p);
void afficher_bv(GtkWidget *liste,char*);
void ajouter_bv(  bv p );
bv rechercher_bv(char id[]);
void modifier_bv(  bv p, char id[] );
char Id[20];
int affichage_tree;
int substringbureau(char str1[], char str2[]);
void chercher_bv(GtkWidget *liste, char Id[]);
int TPF(char *filename);
int TPH(char *filename);
int nbo(char *filename);


