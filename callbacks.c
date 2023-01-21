#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "bv.h"

int salle=1;
void
on_button_confirmerbv_clicked          (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*input2, *input3, *input4, *input5, *input6 ,*output7;
GtkWidget *page1bv ,*page0bv;
bv b ,b1;


int a , tr;
page1bv= lookup_widget(objet_graphique,"page1bv");
page0bv= lookup_widget(objet_graphique,"page0bv");

input1=lookup_widget(objet_graphique,"entry_idbv");
input2=lookup_widget(objet_graphique,"spinbutton_capobs");
input3=lookup_widget(objet_graphique,"entry_capbv");
input4=lookup_widget(objet_graphique,"entry_adressebv");

input5=lookup_widget(objet_graphique,"entry_idagentbv");
input6=lookup_widget(objet_graphique,"comboboxentry_gouvbv");



strcpy(b.idbv,gtk_entry_get_text(GTK_ENTRY(input1)));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2)) ;
strcpy(b.capacite,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(b.idagent,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(b.gouvernerat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));

output7= lookup_widget(objet_graphique,"labelajoutbv");
sprintf(b.capobs,"%d",a);
if (salle==1)
{
	strcpy(b.salle,"1");
}
else if (salle==2)
{
	strcpy(b.salle,"2");
}
else if (salle==3)
{
	strcpy(b.salle,"3");
}    
else if (salle==4)
{
	strcpy(b.salle,"4");
}




/*page0bv=lookup_widget(objet_graphique,"page0bv");
page0bv=create_page0bv();
gtk_widget_show(page0bv);*/

ajouter_bv(b);
gtk_label_set_text(GTK_LABEL(output7),"bureau de vote ajouter");

}


void
on_radiobuttonsalle4_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle = 4;
}


void
on_radiobuttonsalle3_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle = 3;

}


void
on_radiobuttonsalle2_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle = 2;
}


void
on_treeviewbv_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* idbv;
gchar* idagent;
gchar* capacite;
gchar* capobs;
gchar* adresse;
gchar* salle;
gchar* gouvernerat;
bv b ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&idbv, 1 ,&idagent, 2 , &capacite, 3 ,&capobs, 4 ,&adresse, 5 ,&salle, 6 ,&gouvernerat, -1);
strcpy(b.idbv,idbv);
strcpy(b.idagent,idagent);
strcpy(b.capacite,capacite);
strcpy(b.capobs,capobs);
strcpy(b.adresse,adresse);
strcpy(b.salle,salle);
strcpy(b.gouvernerat,gouvernerat);
afficher_bv(treeview,"bv.txt");
}
}


void
on_button_ajoutbv_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *page1bv,*page0bv;
page0bv=lookup_widget(objet_graphique,"page0bv");
gtk_widget_destroy(page0bv);
page1bv=create_page1bv();
gtk_widget_show(page1bv);

}


void
on_button_modifbv_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *pagemodif,*page0bv;
page0bv=lookup_widget(objet_graphique,"page0bv");
gtk_widget_destroy(page0bv);
pagemodif=create_pagemodif();
gtk_widget_show(pagemodif);

}


void
on_button_suppbv_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *page2bv_supprimer_,*page0bv;
page0bv=lookup_widget(objet_graphique,"page0bv");
//gtk_widget_destroy(page0bv);
page2bv_supprimer_=create_page2bv_supprimer_();
gtk_widget_show(page2bv_supprimer_);
}


void
on_button_confsupp_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ;
GtkWidget *windowsupp , *windowaffichage;
GtkWidget *output7;
bv b;

char str[20];

windowsupp= lookup_widget(objet_graphique,"page2bv");
windowaffichage= lookup_widget(objet_graphique,"page0bv");

input1=lookup_widget(objet_graphique,"entrychercherbv");

//output7= lookup_widget(objet_graphique,"labelchercherbvsupp");
strcpy(str,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer("bv.txt", str);
gtk_widget_destroy(windowsupp);
}


void
on_checkbutton_suppbv_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonsalle1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle = 1;
}


void
on_buttonretourajout_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonactualiser_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeviewbv;
GtkWidget *page0bv;
page0bv=lookup_widget(objet_graphique,"page0bv");
treeviewbv=lookup_widget(page0bv,"treeviewbv");
afficher_bv(GTK_TREE_VIEW(treeviewbv),"bv.txt");
afficher_bv(treeviewbv,"bv.txt");
}


void
on_buttoncherchersupp_clicked          (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ;
GtkWidget *windowsupp , *windowaffichage;
GtkWidget *output7;
bv b;

char str[20];
int tr =0;
windowsupp= lookup_widget(objet_graphique,"page2bv");
windowaffichage= lookup_widget(objet_graphique,"page0bv");

input1=lookup_widget(objet_graphique,"entrychercherbv");

output7= lookup_widget(objet_graphique,"labelchercherbvsupp");
strcpy(str,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE * f=fopen("bv.txt", "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %s %s %s\n",b.idbv,b.idagent,b.capacite,b.capobs,b.adresse,b.salle,b.gouvernerat)!=EOF)
        {
            if(strcmp(str,b.idbv)==0)
                tr=1;
        }
    fclose (f);
    }
if (tr==1)
{

	gtk_label_set_text(GTK_LABEL(output7),"bureau de vote trouver");


}
else
{
gtk_label_set_text(GTK_LABEL(output7),"bureau de vote non trouver");
}

}




void
on_buttonmodiferbv2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*input2, *input3, *input4, *input5, *input6,*input7 , *input0,*output7;
GtkWidget *pagemodif ,*pageafficher;
bv b;
int tr,a;


pagemodif= lookup_widget(objet_graphique,"pagemodif");
pageafficher= lookup_widget(objet_graphique,"page0bv");

input0=lookup_widget(objet_graphique,"entrymodifidbv");
input1= lookup_widget(objet_graphique,"spinbuttonmodifbv");
input2= lookup_widget(objet_graphique,"entrymodifcapobs");
input3= lookup_widget(objet_graphique,"entryadressemodif");
input4= lookup_widget(objet_graphique,"entrymodifsalle");
input5= lookup_widget(objet_graphique,"comboboxmodifbv");
input6= lookup_widget(objet_graphique,"entryidagentmodif");
output7= lookup_widget(objet_graphique,"labelchercherbvsupp");



strcpy(b.idbv,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(b.capobs,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(b.capacite,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(b.salle,gtk_entry_get_text(GTK_ENTRY(input4)));

strcpy(b.idagent,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(b.gouvernerat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2)) ;
sprintf(b.capobs,"%d",a);
//modifier("bv.txt", b.idbv,b );


modifier("bv.txt", b.idbv,b );
gtk_label_set_text(GTK_LABEL(output7),"bureau de vote modifier");




}


void
on_buttonchercherbv2_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ;
GtkWidget *windowmodif , *windowaffichage;
GtkWidget *output1 ,*output2 , *output3,*output4 ,*output5 , *output6,*output7;
bv b;
int tr=0 ,a,i;
 char str[20] ,gouv[20][20]={"Gabes","Tataouine","Ariana","Tunis","Sfax","Mednine","Manouba","Jendouba","Beja","Kassrine","Gafsa","Gebili","Tozeur","Monastir","Sousse","Bizerte","Nabeul","Siliana","Mahdia"};
windowmodif= lookup_widget(objet_graphique,"pagemodif");
windowaffichage= lookup_widget(objet_graphique,"page0bv");

input1=lookup_widget(objet_graphique,"entrymodifidbv");
output1= lookup_widget(objet_graphique,"spinbuttonmodifbv");
output2= lookup_widget(objet_graphique,"entrymodifcapobs");
output3= lookup_widget(objet_graphique,"entryadressemodif");
output4= lookup_widget(objet_graphique,"entrymodifsalle");
output5= lookup_widget(objet_graphique,"comboboxmodifbv");
output6= lookup_widget(objet_graphique,"entryidagentmodif");
output7= lookup_widget(objet_graphique,"labelbvmodifier");
strcpy(str,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE * f=fopen("bv.txt", "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %s %s %s\n",b.idbv,b.idagent,b.capacite,b.capobs,b.adresse,b.salle,b.gouvernerat)!=EOF)
        {
            if(strcmp(str,b.idbv)==0)
                tr=1;
        }
    fclose (f);
    }
if (tr==1)
{
bv p=rechercher_bv(str);
	gtk_label_set_text(GTK_LABEL(output7),"bureau de vote trouver");
        a=atoi(b.capobs);
	
	gtk_spin_button_set_value(output1,a);
	gtk_entry_set_text(GTK_ENTRY(output2),p.capacite);
	gtk_entry_set_text(GTK_ENTRY(output3),p.adresse);
	gtk_entry_set_text(GTK_ENTRY(output4),p.salle);

	gtk_entry_set_text(GTK_ENTRY(output6),p.idagent);
while (i>24 && strcmp(gouv[i],p.gouvernerat)!=0)
{
i++;
}
	gtk_combo_box_set_active(GTK_COMBO_BOX(output5),i);


}
else
{
gtk_label_set_text(GTK_LABEL(output7),"bureau de vote non trouver");
}
}


void
on_buttonretourmodif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonretourajoutbv_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *page1bv,*page0bv;
page0bv=lookup_widget(objet_graphique,"page0bv");

gtk_widget_hide(page1bv);
page0bv=create_page0bv();
gtk_widget_show(page0bv);

}


void
on_buttonretourmodifbv_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *pagemodif,*page0bv;
pagemodif=lookup_widget(objet_graphique,"pagemodif");
pagemodif=lookup_widget(objet_graphique,"page0bv");

gtk_widget_hide(pagemodif);
page0bv=create_page0bv();
gtk_widget_show(page0bv);

}


gboolean
on_page0bv_focus_in_event              (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)

{
if (affichage_tree==0)
{
strcpy(Id,"");
GtkWidget *treeview;

treeview =  lookup_widget(widget,"treeview1");

afficher_bv(treeview,"bv.txt");
}
affichage_tree = 1;
  return FALSE;
}





void
on_entrybvname_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)

{
GtkWidget *casechercher;
char Id[20]= "", fich[20]="bureau.txt";

GtkWidget *treeview;
treeview =  lookup_widget(editable,"treeviewbv");

casechercher = lookup_widget(GTK_WIDGET(editable),"entrybvname");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(casechercher)));

chercher_bv(treeview, Id);
}


void
on_buttonstatbv_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *pagestatbv,*page0bv;
page0bv=lookup_widget(objet_graphique,"page0bv");

//gtk_widget_hide(page1bv);
pagestatbv=create_pagestatbv();
gtk_widget_show(pagestatbv);

}


void
on_buttonstatbv3_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *output7;
char str[20],str1[20];
int a,b;
a=TPH("user.txt");
b=TPF("user.txt");
sprintf(str,"%d",a);
sprintf(str1,"%d",b);
strcat(str1, " femme et ");
strcat(str ," homme");
strcat(str1,str);

output7= lookup_widget(objet_graphique,"labeltphfbv");
gtk_label_set_text(GTK_LABEL(output7),str1);
}


void
on_buttonstatbv1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *output7;
char str[20];
int n;
n=nbo("bv.txt");
sprintf(str,"%d",n);

output7= lookup_widget(objet_graphique,"labelnbobsbv");
gtk_label_set_text(GTK_LABEL(output7),str);
}

