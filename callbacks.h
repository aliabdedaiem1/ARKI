#include <gtk/gtk.h>


void
on_button_confirmerbv_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonsalle4_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonsalle3_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonsalle2_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewbv_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_ajoutbv_clicked              (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_modifbv_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_suppbv_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_confsupp_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton_suppbv_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonsalle1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonretourajout_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonactualiser_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_buttoncherchersupp_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodiferbv2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonchercherbv2_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_buttonretourmodif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretourajoutbv_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonretourmodifbv_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

gboolean
on_page0bv_focus_in_event              (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_entrybvname_changed                 (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_buttonstatbv_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonstatbv3_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonstatbv1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
