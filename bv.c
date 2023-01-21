#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "bv.h"
#include <stdio.h>
#include <string.h>

enum
{
BIDBV,
BIDAGENT,
BCAPACITE,
BCAPOBS,
BADRESSE,
BSALLE,
BGOUVERNERAT,
COLUMNS,
};
/*
int ajouter(char * filename, bv p )
{
    FILE* f=fopen("bv.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s  %s %s %d %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat);
        fclose(f);
        return 1;
    }
    else return 0;
}*/
void modifier( char * filename, char id[], bv nouv )
{
    int tr=0;
    bv p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s  %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat)!=EOF)
        {
            if(strcmp(p.idbv,id)==0)
            {
                fprintf(f2,"%s %s  %s %s %s %s %s\n",nouv.idbv,nouv.idagent,nouv.capacite,nouv.capobs,nouv.adresse,nouv.salle,nouv.gouvernerat);
                tr=1;
            }
            else
                fprintf(f2,"%s %s  %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat);

        }
    }
    fclose(f);
    fclose(f2);
    remove("bv.txt");
    rename("nouv.txt", "bv.txt");
    

}
void supprimer(char * filename, char id[])
{
    int tr=0;
    bv p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s  %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat)!=EOF)
        {
            if(strcmp(p.idbv,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s  %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", "bv.txt");
    return tr;
}
int chercher(char * filename, char id[])
{
    bv p;
    int tr=0;
    FILE * f=fopen("bv.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat)!=EOF)
        {
            if(strcmp(p.idbv,id)==0)
                tr=1;
        }
    }
    fclose(f);
    return tr;

}

/*void bureau (int salle , char msg[])
{
if (salle==1)
    strcpy(msg,"1");
if (salle==2)
    strcpy(msg,"2");
if (salle==3)
    strcpy(msg,"3");
if (salle==4)
    strcpy(msg,"4");
}*/

////////////////////////////////////////////////////////
void ajouter_bv( bv p )
{
    FILE* f=fopen("bv.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat);
        fclose(f);
    }
   
}
////////////////////////////////////////////////////////

void afficher_bv(GtkWidget *liste,char* filename)
{
     GtkCellRenderer *renderer ;
     GtkTreeViewColumn *column;
     GtkTreeIter   iter;
     GtkListStore *store;
     bv b;
    /* char idbv[20];
     char idagent[20];
     char capacite[20];
     char capobs[20];
     char adresse[20];
     char salle[20];
     char gouvernerat[20];*/
     store=gtk_tree_view_get_model(liste);
     store=NULL;
FILE *f;
store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));

if (store==NULL)
{	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("idbv",renderer, "text" ,BIDBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("idagent",renderer, "text" ,BIDAGENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capacite",renderer, "text" ,BCAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);  

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capobs",renderer, "text" ,BCAPOBS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);      
    

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adresse",renderer, "text" ,BADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("salle",renderer, "text" ,BSALLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("gouvernerat",renderer, "text" ,BGOUVERNERAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen(filename,"r");
	if (f==NULL)
	{
		return;
	}
	else
	{
	f=fopen(filename,"a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",b.idbv,b.idagent,b.capacite,b.capobs,b.adresse,b.salle,b.gouvernerat)!=EOF)
			{
         			gtk_list_store_append(store, &iter);
	 				gtk_list_store_set(store,&iter,
                           			BIDBV,b.idbv,
						BIDAGENT,b.idagent,
						BCAPACITE,b.capacite,
						BCAPOBS,b.capobs,
						BADRESSE,b.adresse,
						BSALLE,b.salle,
						BGOUVERNERAT,b.gouvernerat,
                            			-1);}
        fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
	

}
}
//////////////////////////////////////////////////////////////////////////////////////

/*void supprimer_bv(bv p)
{   
    char strcapobs[20];
    char idbv[20];
    char idagent[20];
    char capacite[20];
    char capobs[20] ;
    char adresse[20];
    char salle[20];
    char gouvernerat[20];
    bv p1;
    FILE * f=fopen("bv.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
		return ;
    else
    {
        while(fscanf(f,"%s %s  %s %d %s %s %s\n",p1.idbv,p1.idagent,p1.capacite,&p1.capobs,p1.adresse,p1.salle,p1.gouvernerat)!=EOF)
        
        {
            sprintf(strcapobs,"%d",p1.capobs);
            if(strcmp(p1.idbv,idbv)==0 ||strcmp(p1.idagent,idagent)==0 ||strcmp(p1.capacite,capacite)==0 || strcmp(p1.capobs,strcapobs)==0 ||strcmp(p1.adresse,adresse)==0 ||strcmp(p1.salle,salle)==0 ||strcmp(p1.gouvernerat,gouvernerat)==0 )
            fprintf(f2,"%s %s  %s %d %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat);
        }
    }
    fclose(f);
    fclose(f2);
    remove("bv.txt");
    rename("nouv.txt", "bv.txt");
    
}*/
/////////////////////////////////////////////////////////////////////
/*void modifier_bv(  bv p, char id[] )
{
    
    bv p1 , nouv;

    int tr ;
     char idbv[20];
     char idagent[20];
     char capacite[20];
    char capobs[20] ;
     char adresse[20];
     char salle[20];
     char gouvernerat[20];
     char idbv1[20];
     char idagent1[20];
     char capacite1[20];
    char capobs1[20] ;
     char adresse1[20];
     char salle1[20];
     char gouvernerat1[20];
    FILE * f=fopen("bv.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s  %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,&p.capobs,p.adresse,p.salle,p.gouvernerat)!=EOF)
        {
            if(strcmp(p.idbv,id)==0)
            {
                fprintf(f2,"%s %s  %s %s %s %s %s\n",nouv.idbv,nouv.idagent,nouv.capacite,nouv.capobs,nouv.adresse,nouv.salle,nouv.gouvernerat);
                tr=1;
            }
            else
                fprintf(f2,"%s %s  %s %s %s %s %s\n",p.idbv,p.idagent,p.capacite,p.capobs,p.adresse,p.salle,p.gouvernerat);

        }
    }
    fclose(f);
    fclose(f2);
    remove("bv.txt");
    rename("nouv.txt", "bv.txt");
    

}
*/
bv rechercher_bv(char id[])
{
FILE *f=NULL;
  bv b;
  bv b2;
f = fopen ("bv.txt", "r");


  if (f!=NULL)
 {


    while(fscanf(f,"%s %s %s %s %s %s %s\n",b2.idbv,b2.idagent,b2.capacite,b2.capobs,b2.adresse,b2.salle,b2.gouvernerat)!=EOF)
    if (strcmp (b2.idbv, id) == 0)
	{
        
	strcpy(b.idagent,b2.idagent);
        strcpy(b.capacite,b2.capacite);
        strcpy(b.capobs,b2.capobs);
	strcpy(b.capacite,b2.capacite);
 	strcpy(b.adresse,b2.adresse);
	strcpy(b.gouvernerat,b2.gouvernerat);
        strcpy(b.salle,b2.salle);
        
    }
    
  fclose (f);
 }
return b;
}

void chercher_bv(GtkWidget *liste, char Id[])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    bv b;
store=NULL;
    FILE *f;
    store = gtk_tree_view_get_model(liste);

    if (store==NULL)
    {

    renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("idbv",renderer, "text" ,BIDBV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("idagent",renderer, "text" ,BIDAGENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capacite",renderer, "text" ,BCAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);  

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("capobs",renderer, "text" ,BCAPOBS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);      
    

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adresse",renderer, "text" ,BADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("salle",renderer, "text" ,BSALLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("gouvernerat",renderer, "text" ,BGOUVERNERAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    f=fopen("bv.txt", "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %s %s %s\n",b.idbv,b.idagent,b.capacite,b.capobs,b.adresse,b.salle,b.gouvernerat)!=EOF)
        {
            if(substringbureau(Id,b.idbv))
	{
	gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,
                           			BIDBV,b.idbv,
						BIDAGENT,b.idagent,
						BCAPACITE,b.capacite,
						BCAPOBS,b.capobs,
						BADRESSE,b.adresse,
						BSALLE,b.salle,
						BGOUVERNERAT,b.gouvernerat,
                            			-1);
	}
	}
	fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int substringbureau(char str1[], char str2[])
{
	int n1,n2,i,cmp = 0;
	n1 = strlen(str1);
	n2= strlen(str2);
	if (n1<=n2)
		{
			for (i=0;i<n1;i++)
				{
					if (str1[i] == str2[i])
						{
							cmp +=1;			
						}
				}
			if (cmp == n1)
				
					return 1;
						
			else
				
					return 0;
				
		}
			else
				
					return 0;
				
}

int TPH(char *filename)
{ user u ;
  int nbtotal ,nbhomme;
  nbtotal=0;
  nbhomme=0;

     FILE* F=fopen(filename, "r");
     while(fscanf(F,"%s %s %s   \n",u.prenom,u.role,u.genre)!=EOF)
     {
         if (strcmp(u.role,"electeur")==0)
         {
             nbtotal++;
             if(strcmp(u.genre,"homme")==0)
             {
                 nbhomme++;
             }
         }

     }
return nbhomme;
}


int TPF(char *filename)
{ user u ;
  int nbtotal ,nbfemme;
  nbtotal=0;
  nbfemme=0;

     FILE* F=fopen(filename, "r");
     while(fscanf(F,"%s %s %s   \n",u.prenom,u.role,u.genre)!=EOF)
     {
         if (strcmp(u.role,"electeur")==0)
         {
             nbtotal++;
             if(strcmp(u.genre,"femme")==0)
             {
                 nbfemme++;
             }
         }

     }
return nbfemme;
}




int nbo(char *filename)
{ bv b ;
int s=0,a;
  
     FILE* f=fopen(filename, "r");
     while( fscanf(f,"%s %s %s %s %s %s %s\n",b.idbv,b.idagent,b.capacite,b.capobs,b.adresse,b.salle,b.gouvernerat)!=EOF)
     {
         a=atoi(b.capobs);
         s= s+a;
     }
         return s;
}
























