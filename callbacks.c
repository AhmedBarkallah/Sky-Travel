#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "fonctions.h"
#include "hotels.h"
#include "vol.h"
#include "login.h"
#include "reclamation.h"


void
on_buttonGCClients_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Admin;
GtkWidget *fenetre_Client;
fenetre_Admin=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_destroy(fenetre_Admin);
fenetre_Client=create_windowGCClient();
gtk_widget_show(fenetre_Client);
}


void
on_buttonGCAdmin_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Admin;
GtkWidget *fenetre_CAdmin;
fenetre_Admin=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_destroy(fenetre_Admin);
fenetre_CAdmin=create_windowGCAdmin();
gtk_widget_show(fenetre_CAdmin);
}



void
on_buttonGProduits_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Admin;
GtkWidget *fenetre_Produits;
fenetre_Admin=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_destroy(fenetre_Admin);
fenetre_Produits=create_windowGProduits();
gtk_widget_show(fenetre_Produits);
}


void
on_buttonGCEmploye_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Admin;
GtkWidget *fenetre_Employe;
fenetre_Admin=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_destroy(fenetre_Admin);
fenetre_Employe=create_windowGCEmploye();
gtk_widget_show(fenetre_Employe);
}


void
on_buttonConsulterE_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_employe;
GtkWidget *fenetre_Consulter;
GtkWidget *treeview1;
fenetre_employe=lookup_widget(objet_graphique,"windowGCEmploye");
gtk_widget_destroy(fenetre_employe);
fenetre_Consulter=create_windowConsulterEmploye();
gtk_widget_show(fenetre_Consulter);
treeview1=lookup_widget(fenetre_Consulter,"treeview1");
afficher_Employe(treeview1);
}


void
on_buttonRetour1_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Employe;
GtkWidget *fenetre_admin;
fenetre_Employe=lookup_widget(objet_graphique,"windowGCEmploye");
gtk_widget_destroy(fenetre_Employe);
fenetre_admin=create_windowAdmin();
gtk_widget_show(fenetre_admin);
}


void
on_buttonAjouterE_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_employe;
fenetre_employe=lookup_widget(objet_graphique,"windowGCEmploye");
gtk_widget_destroy(fenetre_employe);
fenetre_ajout=create_windowAjouterEmploye();
gtk_widget_show(fenetre_ajout);
}


void
on_buttonRetour2_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Employe;
GtkWidget *fenetre_ajouter;
fenetre_ajouter=lookup_widget(objet_graphique,"windowAjouterEmploye");
gtk_widget_destroy(fenetre_ajouter);
fenetre_Employe=create_windowGCEmploye();
gtk_widget_show(fenetre_Employe);
}


void
on_buttonConfirmerE_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
Employe e;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;

input1=lookup_widget(objet_graphique,"entryNom_e");
input2=lookup_widget(objet_graphique,"entryPrenom_e");
input3=lookup_widget(objet_graphique,"entryDate_e");
input4=lookup_widget(objet_graphique,"entryMatricule_e");
input5=lookup_widget(objet_graphique,"entryAdresse_e");
input6=lookup_widget(objet_graphique,"entryUsername_e");
input7=lookup_widget(objet_graphique,"entryPassword_e");
input8=lookup_widget(objet_graphique,"entryEmail_e");
strcpy(e.nom_e,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenom_e,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.date_naissance_e,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.matricule_e,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.adresse_e,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(e.username_e,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(e.password_e,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(e.email_e,gtk_entry_get_text(GTK_ENTRY(input8)));
ajouter_Employe(e);
}



void
on_buttonRetour3_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_Employe;
GtkWidget *fenetre_consulter;
fenetre_consulter=lookup_widget(objet_graphique,"windowConsulterEmploye");
gtk_widget_destroy(fenetre_consulter);
fenetre_Employe=create_windowGCEmploye();
gtk_widget_show(fenetre_Employe);
}





void
on_buttonConsulterC_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_client;
GtkWidget *fenetre_Consulter;
GtkWidget *treeview2;
fenetre_client=lookup_widget(objet_graphique,"windowGCClient");
gtk_widget_destroy(fenetre_client);
fenetre_Consulter=create_windowConsulterClient();
gtk_widget_show(fenetre_Consulter);
treeview2=lookup_widget(fenetre_Consulter,"treeview2");
afficher_Client(treeview2);
}


void
on_buttonAjouterC_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_Client;
fenetre_Client=lookup_widget(objet_graphique,"windowGCClient");
gtk_widget_destroy(fenetre_Client);
fenetre_ajout=create_windowAjouterClient();
gtk_widget_show(fenetre_ajout);
}


void
on_buttonRetour4_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_admin;
GtkWidget *fenetre_client;
fenetre_client=lookup_widget(objet_graphique,"windowGCClient");
gtk_widget_destroy(fenetre_client);
fenetre_admin=create_windowAdmin();
gtk_widget_show(fenetre_admin);
}


void
on_buttonRetour5_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_client;
GtkWidget *fenetre_ajouter;
fenetre_ajouter=lookup_widget(objet_graphique,"windowAjouterClient");
gtk_widget_destroy(fenetre_ajouter);
fenetre_client=create_windowGCClient();
gtk_widget_show(fenetre_client);
}


void
on_buttonConfirmerC_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
Client c;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;

input1=lookup_widget(objet_graphique,"entryNom_c");
input2=lookup_widget(objet_graphique,"entryPrenom_c");
input3=lookup_widget(objet_graphique,"entryDate_c");
input4=lookup_widget(objet_graphique,"entryCin");
input5=lookup_widget(objet_graphique,"entryNpassport");
input6=lookup_widget(objet_graphique,"entryAdresse_c");
input7=lookup_widget(objet_graphique,"entryUsername_c");
input8=lookup_widget(objet_graphique,"entryPassword_c");
input9=lookup_widget(objet_graphique,"entryEmail_c");
strcpy(c.nom_c,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom_c,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.date_naissance_c,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.n_passport,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.adresse_c,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.username_c,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(c.password_c,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(c.email_c,gtk_entry_get_text(GTK_ENTRY(input9)));
ajouter_Client(c);
}


void
on_treeview2_row_activated             (GtkTreeView     *objet,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *nom,*prenom,*date,*cin,*n_passport,*adresse,*username,*password,*email;
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *nom1,*prenom1,*date1,*cin1,*n_passport1,*adresse1,*username1,*password1,*email1;
	window1=lookup_widget(objet,"windowConsulterClient");
	treeview=lookup_widget(objet,"treeview2");
	window2=create_windowMClient();
	nom1=lookup_widget(window2,"entryMNom_c");
	prenom1=lookup_widget(window2,"entryMPrenom_c");
	date1=lookup_widget(window2,"entryMDate_c");
	cin1=lookup_widget(window2,"entryMCin");
        n_passport1=lookup_widget(window2,"entryMN_passport");
	adresse1=lookup_widget(window2,"entryMAdresse_c");
	username1=lookup_widget(window2,"entryMUsername_c");
	password1=lookup_widget(window2,"entryMPassword_c");
	email1=lookup_widget(window2,"entryMEmail_c");
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&date,3,&cin,4,&n_passport,5,&adresse,6,&username,7,&password,8,&email,-1);
	printf("%s %s %s %s %s %s %s %s %s\n",nom,prenom,date,cin,n_passport,adresse,username,password,email);
	gtk_entry_set_text(GTK_LABEL (nom1),(nom));
	gtk_entry_set_text(GTK_LABEL (prenom1),(prenom));
	gtk_entry_set_text(GTK_LABEL (date1),(date));
	gtk_entry_set_text(GTK_LABEL (cin1),(cin));
        gtk_entry_set_text(GTK_LABEL (n_passport1),(n_passport));
	gtk_entry_set_text(GTK_LABEL (adresse1),(adresse));
	gtk_entry_set_text(GTK_LABEL (username1),(username));
	gtk_entry_set_text(GTK_LABEL (password1),(password));
	gtk_entry_set_text(GTK_LABEL (email1),(email));

	gtk_widget_hide(window1);
	gtk_widget_show(window2);
}


void
on_buttonRetour6_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_consulter;
GtkWidget *fenetre_client;
fenetre_consulter=lookup_widget(objet_graphique,"windowConsulterClient");
gtk_widget_destroy(fenetre_consulter);
fenetre_client=create_windowGCClient();
gtk_widget_show(fenetre_client);
}





void
on_buttonConsulterA_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_admin;
GtkWidget *fenetre_Consulter;
GtkWidget *treeview3;
fenetre_admin=lookup_widget(objet_graphique,"windowGCAdmin");
gtk_widget_destroy(fenetre_admin);
fenetre_Consulter=create_windowConsulterAdmin();
gtk_widget_show(fenetre_Consulter);
treeview3=lookup_widget(fenetre_Consulter,"treeview3");
afficher_Admin(treeview3);
}


void
on_buttonAjouterA_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_admin;
fenetre_admin=lookup_widget(objet_graphique,"windowGCAdmin");
gtk_widget_destroy(fenetre_admin);
fenetre_ajout=create_windowAjouterAdmin();
gtk_widget_show(fenetre_ajout);
}


void
on_buttonRetour7_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_cadmin;
GtkWidget *fenetre_admin;
fenetre_cadmin=lookup_widget(objet_graphique,"windowGCAdmin");
gtk_widget_destroy(fenetre_cadmin);
fenetre_admin=create_windowAdmin();
gtk_widget_show(fenetre_admin);
}


void
on_buttonConfirmerA_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
Admin a;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;

input1=lookup_widget(objet_graphique,"entryNom_a");
input2=lookup_widget(objet_graphique,"entryPrenom_a");
input3=lookup_widget(objet_graphique,"entryDate_a");
input4=lookup_widget(objet_graphique,"entryMatricule_a");
input5=lookup_widget(objet_graphique,"entryAdresse_a");
input6=lookup_widget(objet_graphique,"entryUsername_a");
input7=lookup_widget(objet_graphique,"entryPassword_a");
input8=lookup_widget(objet_graphique,"entryEmail_a");
strcpy(a.nom_a,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.prenom_a,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.date_naissance_a,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.matricule_a,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(a.adresse_a,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.username_a,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.password_a,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(a.email_a,gtk_entry_get_text(GTK_ENTRY(input8)));
ajouter_Admin(a);
}


void
on_buttonRetour8_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_admin;
GtkWidget *fenetre_ajouter;
fenetre_ajouter=lookup_widget(objet_graphique,"windowAjouterAdmin");
gtk_widget_destroy(fenetre_ajouter);
fenetre_admin=create_windowGCAdmin();
gtk_widget_show(fenetre_admin);
}


void
on_treeview3_row_activated             (GtkTreeView     *objet,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *nom,*prenom,*date,*matricule,*adresse,*username,*password,*email;
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *nom1,*prenom1,*date1,*matricule1,*adresse1,*username1,*password1,*email1;
	window1=lookup_widget(objet,"windowConsulterAdmin");
	treeview=lookup_widget(objet,"treeview3");
	window2=create_windowMCAdmin();
	nom1=lookup_widget(window2,"entryNom_ma");
	prenom1=lookup_widget(window2,"entryPrenom_ma");
	date1=lookup_widget(window2,"entryDate_ma");
	matricule1=lookup_widget(window2,"entryMatricule_ma");
	adresse1=lookup_widget(window2,"entryAdresse_ma");
	username1=lookup_widget(window2,"entryUsername_ma");
	password1=lookup_widget(window2,"entryPassword_ma");
	email1=lookup_widget(window2,"entryEmail_ma");
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&date,3,&matricule,4,&adresse,5,&username,6,&password,7,&email,-1);
	printf("%s %s %s %s %s %s %s %s \n",nom,prenom,date,matricule,adresse,username,password,email);
	gtk_entry_set_text(GTK_LABEL (nom1),(nom));
	gtk_entry_set_text(GTK_LABEL (prenom1),(prenom));
	gtk_entry_set_text(GTK_LABEL (date1),(date));
	gtk_entry_set_text(GTK_LABEL (matricule1),(matricule));
	gtk_entry_set_text(GTK_LABEL (adresse1),(adresse));
	gtk_entry_set_text(GTK_LABEL (username1),(username));
	gtk_entry_set_text(GTK_LABEL (password1),(password));
	gtk_entry_set_text(GTK_LABEL (email1),(email));

	gtk_widget_hide(window1);
	gtk_widget_show(window2);
}


void
on_buttonRetour9_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
GtkWidget *fenetre_consulter;
GtkWidget *fenetre_admin;
fenetre_consulter=lookup_widget(objet_graphique,"windowConsulterAdmin");
gtk_widget_destroy(fenetre_consulter);
fenetre_admin=create_windowGCAdmin();
gtk_widget_show(fenetre_admin);
}


void
on_buttonRetour10_clicked (GtkWidget *objet_graphique,  gpointer         user_data)
{
GtkWidget *fenetre_madmin;
GtkWidget *fenetre_admin;
GtkWidget *treeview3;
fenetre_madmin=lookup_widget(objet_graphique,"windowMCAdmin");
gtk_widget_destroy(fenetre_madmin);
fenetre_admin=create_windowConsulterAdmin();
gtk_widget_show(fenetre_admin);
treeview3=lookup_widget(fenetre_admin,"treeview3");
afficher_Admin(treeview3);
}


void
on_buttonConfirmerMA_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
 Admin a;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output1;
	char succes[30];
	input1=lookup_widget(objet_graphique,"entryNom_ma");
	input2=lookup_widget(objet_graphique,"entryPrenom_ma");
	input3=lookup_widget(objet_graphique,"entryDate_ma");
	input4=lookup_widget(objet_graphique,"entryMatricule_ma");
        input5=lookup_widget(objet_graphique,"entryAdresse_ma");
	input6=lookup_widget(objet_graphique,"entryUsername_ma");
	input7=lookup_widget(objet_graphique,"entryPassword_ma");
	input8=lookup_widget(objet_graphique,"entryEmail_ma");
	
	output1=lookup_widget(objet_graphique,"labelSortieSA");
	strcpy(a.nom_a,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(a.prenom_a,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(a.date_naissance_a,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(a.matricule_a,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(a.adresse_a,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(a.username_a,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(a.password_a,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(a.email_a,gtk_entry_get_text(GTK_ENTRY(input8)));
	strcpy(succes,"Modification avec succés");
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), succes);
	Modifier_Admin(a);    
}


void
on_buttonRetour11_clicked (GtkWidget *objet_graphique, gpointer   user_data)
{
GtkWidget *fenetre_produit;
GtkWidget *fenetre_admin;
fenetre_produit=lookup_widget(objet_graphique,"windowGProduits");
gtk_widget_destroy(fenetre_produit);
fenetre_admin=create_windowAdmin();
gtk_widget_show(fenetre_admin);
}


void
on_buttonGVol_clicked  (GtkWidget *objet_graphique, gpointer user_data)

{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview4;
	window1=lookup_widget(objet_graphique,"windowGProduits");
	window2=create_windowAffichagevol();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
	treeview4=lookup_widget(window2,"treeview4");
	afficher_vol(treeview4);
	
}


void
on_buttonGHotel_clicked (GtkWidget *objet, gpointer user_data)
{
 	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview1;
	window1=lookup_widget(objet,"windowGProduits");
        gtk_widget_destroy(window1);
	window2=create_windowListes_Hotels();
	
	gtk_widget_show(window2);
	treeview1=lookup_widget(window2,"treeviewHotel");
	afficher_hotel(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *objet,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *nom,*prenom,*date,*matricule,*adresse,*username,*password,*email;
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *nom1,*prenom1,*date1,*matricule1,*adresse1,*username1,*password1,*email1;
	window1=lookup_widget(objet,"windowConsulterEmploye");
	treeview=lookup_widget(objet,"treeview1");
	window2=create_windowModifierEmploye();
	nom1=lookup_widget(window2,"entryMNom_e");
	prenom1=lookup_widget(window2,"entryMPrenom_e");
	date1=lookup_widget(window2,"entryMDate_e");
	matricule1=lookup_widget(window2,"entryMMatricule_e");
	adresse1=lookup_widget(window2,"entryMAdresse_e");
	username1=lookup_widget(window2,"entryMUsername_e");
	password1=lookup_widget(window2,"entryMPassword_e");
	email1=lookup_widget(window2,"entryMEmail_e");
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&date,3,&matricule,4,&adresse,5,&username,6,&password,7,&email,-1);
	printf("%s %s %s %s %s %s %s %s \n",nom,prenom,date,matricule,adresse,username,password,email);
	gtk_entry_set_text(GTK_LABEL (nom1),(nom));
	gtk_entry_set_text(GTK_LABEL (prenom1),(prenom));
	gtk_entry_set_text(GTK_LABEL (date1),(date));
	gtk_entry_set_text(GTK_LABEL (matricule1),(matricule));
	gtk_entry_set_text(GTK_LABEL (adresse1),(adresse));
	gtk_entry_set_text(GTK_LABEL (username1),(username));
	gtk_entry_set_text(GTK_LABEL (password1),(password));
	gtk_entry_set_text(GTK_LABEL (email1),(email));

	gtk_widget_hide(window1);
	gtk_widget_show(window2);
}



void
on_buttonSupprimerAdmin_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	char confirmation[50];
	Admin a;
	window1=lookup_widget(objet_graphique,"windowMCAdmin");
	GtkWidget *input1;
	GtkWidget *output1;
	input1=lookup_widget(objet_graphique,"entryNom_ma");
	output1=lookup_widget(objet_graphique,"labelSortieSA");
	strcpy(a.nom_a,gtk_entry_get_text(GTK_ENTRY(input1)));
	Supprimer_Admin(a);
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), confirmation);
	strcpy(confirmation,"Suppression avec succes");
	gtk_label_set_text(GTK_LABEL(output1),confirmation);        
}





void
on_buttonConfirmerMC_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
        Client c;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
        GtkWidget *input9;
	GtkWidget *output1;
	char succes[30];
	input1=lookup_widget(objet_graphique,"entryMNom_c");
	input2=lookup_widget(objet_graphique,"entryMPrenom_c");
	input3=lookup_widget(objet_graphique,"entryMDate_c");
	input4=lookup_widget(objet_graphique,"entryMCin");
        input5=lookup_widget(objet_graphique,"entryMN_passport");
        input6=lookup_widget(objet_graphique,"entryMAdresse_c");
	input7=lookup_widget(objet_graphique,"entryMUsername_c");
	input8=lookup_widget(objet_graphique,"entryMPassword_c");
	input9=lookup_widget(objet_graphique,"entryMEmail_c");
	
	output1=lookup_widget(objet_graphique,"labelSupprimerC");
	strcpy(c.nom_c,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(c.prenom_c,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(c.date_naissance_c,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
        strcpy(c.n_passport,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(c.adresse_c,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(c.username_c,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(c.password_c,gtk_entry_get_text(GTK_ENTRY(input8)));
	strcpy(c.email_c,gtk_entry_get_text(GTK_ENTRY(input9)));
	strcpy(succes,"Modification avec succés");
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), succes);
	Modifier_Client(c);
}


void
on_buttonSupprimerC_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
 GtkWidget *window1;
	GtkWidget *window2;
	char confirmation[50];
	Client c;
	window1=lookup_widget(objet_graphique,"windowModifierClient");
	GtkWidget *input1;
	GtkWidget *output1;
	input1=lookup_widget(objet_graphique,"entryMNom_c");
	output1=lookup_widget(objet_graphique,"labelSupprimerC");
	strcpy(c.nom_c,gtk_entry_get_text(GTK_ENTRY(input1)));
	Supprimer_Client(c);
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), confirmation);
	strcpy(confirmation,"Suppression avec succes");
	gtk_label_set_text(GTK_LABEL(output1),confirmation); 
}


void
on_buttonRetourME_clicked  (GtkWidget  *objet_graphique, gpointer  user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	window1=lookup_widget(objet_graphique,"windowModifierEmploye");
        gtk_widget_destroy(window1);
	window2=create_windowConsulterEmploye();
         gtk_widget_show(window2);
	
	treeview=lookup_widget(window2,"treeview1");
         afficher_Employe(treeview);
}


void
on_buttonSupprimerE_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
	char confirmation[50];
	Employe e;
	window1=lookup_widget(objet_graphique,"windowModifierEmploye");
	GtkWidget *input1;
	GtkWidget *output1;
	input1=lookup_widget(objet_graphique,"entryMNom_e");
	output1=lookup_widget(objet_graphique,"labelSortieSE");
	strcpy(e.nom_e,gtk_entry_get_text(GTK_ENTRY(input1)));
	Supprimer_Employe(e);
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), confirmation);
	strcpy(confirmation,"Suppression avec succes");
	gtk_label_set_text(GTK_LABEL(output1),confirmation);   
}


void
on_buttonConfirmerME_clicked (GtkWidget  *objet_graphique, gpointer  user_data)
{
        Employe e;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output1;
	char succes[30];
	input1=lookup_widget(objet_graphique,"entryMNom_e");
	input2=lookup_widget(objet_graphique,"entryMPrenom_e");
	input3=lookup_widget(objet_graphique,"entryMDate_e");
	input4=lookup_widget(objet_graphique,"entryMMatricule_e");
        input5=lookup_widget(objet_graphique,"entryMAdresse_e");
	input6=lookup_widget(objet_graphique,"entryMUsername_e");
	input7=lookup_widget(objet_graphique,"entryMPassword_e");
	input8=lookup_widget(objet_graphique,"entryMEmail_e");
	
	output1=lookup_widget(objet_graphique,"labelSortieSE");
	strcpy(e.nom_e,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(e.prenom_e,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(e.date_naissance_e,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(e.matricule_e,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(e.adresse_e,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(e.username_e,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(e.password_e,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(e.email_e,gtk_entry_get_text(GTK_ENTRY(input8)));
	strcpy(succes,"Modification avec succés");
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), succes);
	Modifier_Employe(e);

}



void
on_buttonAjoutervol_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(objet,"windowAffichagevol");
	window2=create_windowAjoutvol();

	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}


void
on_buttonRetourgclient_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;

	window1=lookup_widget(objet,"windowAffichagevol");
	window2=create_windowGProduits();

	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}


void
on_buttonConfirmervol_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
	vol v;
	char confirmation[50];
	GtkWidget *output1;
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;
	GtkWidget *Ajouter;
	input1=lookup_widget(objet,"entryAeroportdepart");
	input2=lookup_widget(objet,"entryAeroportarrivee");
	input3=lookup_widget(objet,"entryDatedepart");
	input4=lookup_widget(objet,"entryDateretour");
	input5=lookup_widget(objet,"entryHeuredepart");
	input6=lookup_widget(objet,"entryHeurearrivee");
	input7=lookup_widget(objet,"entryNumerovol");
	input8=lookup_widget(objet,"entryNombresiege");
	output1=lookup_widget(objet,"labelConfirmationvol");

	strcpy(v.aeroportdepart,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(v.aeroportarrivee,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(v.datedepart,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(v.dateretour,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(v.heuredepart,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(v.heurearrivee,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(v.numerovol,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(v.nombresiege,gtk_entry_get_text(GTK_ENTRY(input8)));
if (verifier_ajout(v)==1)
{	GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), confirmation);
	strcpy(confirmation,"Vol ajouté");
	gtk_label_set_text(GTK_LABEL(output1),confirmation);
ajouter_vol(v);}
}


void
on_buttonRetourvol_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Ajoutvol;
	GtkWidget *Admin;
		GtkWidget *treeview;

Ajoutvol=lookup_widget(objet,"windowAjoutvol");
Admin=create_windowAffichagevol();
gtk_widget_destroy(Ajoutvol);
gtk_widget_show(Admin);
	treeview=lookup_widget(Admin,"treeview4");
	afficher_vol(treeview);

}


void
on_buttonSupprimervol_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	char confirmation[50];
	vol v;
	window1=lookup_widget(objet,"windowModifvol");
	GtkWidget *input1;
	GtkWidget *output1;
	input1=lookup_widget(objet,"entryNumerovol1");
	output1=lookup_widget(objet,"labelConfirmation1");
	strcpy(v.numerovol,gtk_entry_get_text(GTK_ENTRY(input1)));
	supprimervol(v);
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), confirmation);
	strcpy(confirmation,"Suppression avec succes");
	gtk_label_set_text(GTK_LABEL(output1),confirmation);
}


void
on_buttonRetourmodifvol_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	window1=lookup_widget(objet,"windowModifvol");

	window2=create_windowAffichagevol();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
	
	treeview=lookup_widget(window2,"treeview4");
	afficher_vol(treeview);
}


void
on_buttonConfirmmodifvol_clicked       (GtkWidget      *objet,
                                        gpointer         user_data)
{
	vol v;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *output1;
	char succes[30];
	input1=lookup_widget(objet,"entryAeroportdepart1");
	input2=lookup_widget(objet,"entryAeroportarrivee1");
	input3=lookup_widget(objet,"entryDatedepart1");
	input4=lookup_widget(objet,"entryDateretour1");
	input5=lookup_widget(objet,"entryHeuredepart1");
	input6=lookup_widget(objet,"entryHeurearrivee1");
	input7=lookup_widget(objet,"entryNombresiege1");
	input8=lookup_widget(objet,"entryNumerovol1");
	output1=lookup_widget(objet,"labelConfirmation1");
	strcpy(v.aeroportdepart,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(v.aeroportarrivee,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(v.datedepart,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(v.dateretour,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(v.heuredepart,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(v.heurearrivee,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(v.nombresiege,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(v.numerovol,gtk_entry_get_text(GTK_ENTRY(input8)));
	strcpy(succes,"Modification avec succés");
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), succes);
	modifier_vol(v);
}


void
on_treeview4_row_activated             (GtkWidget    *objet,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gchar *aeroportdepart,*aeroportarrivee,*datedepart,*dateretour,*heuredepart,*heurearrivee,*numerovol,*nombresiege;
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *aeroportdepart1,*aeroportarrivee1,*datedepart1,*dateretour1,*heuredepart1,*heurearrivee1,*numerovol1,*nombresiege1;
	window1=lookup_widget(objet,"windowAffichagevol");
	treeview=lookup_widget(objet,"treeview4");
	window2=create_windowModifvol();
	aeroportdepart1=lookup_widget(window2,"entryAeroportdepart1");
	aeroportarrivee1=lookup_widget(window2,"entryAeroportarrivee1");
	datedepart1=lookup_widget(window2,"entryDatedepart1");
	dateretour1=lookup_widget(window2,"entryDateretour1");
	heuredepart1=lookup_widget(window2,"entryHeuredepart1");
	heurearrivee1=lookup_widget(window2,"entryHeurearrivee1");
	numerovol1=lookup_widget(window2,"entryNumerovol1");
	nombresiege1=lookup_widget(window2,"entryNombresiege1");
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&aeroportdepart,1,&aeroportarrivee,2,&datedepart,3,&dateretour,4,&heuredepart,5,&heurearrivee,6,&numerovol,7,&nombresiege,-1);
	printf("%s %s %s %s %s %s %s %s %s\n",aeroportdepart,aeroportarrivee,datedepart,dateretour,heuredepart,heurearrivee,numerovol,nombresiege);
	gtk_entry_set_text(GTK_LABEL (aeroportdepart1),(aeroportdepart));
	gtk_entry_set_text(GTK_LABEL (aeroportarrivee1),(aeroportarrivee));
	gtk_entry_set_text(GTK_LABEL (datedepart1),(datedepart));
	gtk_entry_set_text(GTK_LABEL (dateretour1),(dateretour));
	gtk_entry_set_text(GTK_LABEL (heuredepart1),(heuredepart));
	gtk_entry_set_text(GTK_LABEL (heurearrivee1),(heurearrivee));
	gtk_entry_set_text(GTK_LABEL (numerovol1),(numerovol));
	gtk_entry_set_text(GTK_LABEL (nombresiege1),(nombresiege));

	gtk_widget_hide(window1);
	gtk_widget_show(window2);
}


void
on_buttonAjouter_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkWidget *window1;
	GtkWidget *window2;
	window1=lookup_widget(objet,"windowListes_Hotels");
        gtk_widget_destroy(window1);
	window2=create_windowFiche_Hotel();
	gtk_widget_show(window2);

}





void
on_treeviewHotel_row_activated         (GtkWidget     *objet,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *nb_etoile,*nom,*e_mail,*tel,*emplacement;
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *nb_etoile1,*nom1,*e_mail1,*tel1,*emplacement1;
	window1=lookup_widget(objet,"windowListes_Hotels");
	treeview=lookup_widget(objet,"treeviewHotel");
	window2=create_windowModifierhotel();
	nb_etoile1=lookup_widget(window2,"entryMEtoile");
	nom1=lookup_widget(window2,"entryMNom");
	e_mail1=lookup_widget(window2,"entryMEmail");
	tel1=lookup_widget(window2,"entryMTel");
	emplacement1=lookup_widget(window2,"entryMEmplacement");
	
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&nb_etoile,1,&emplacement,2,&nom,3,&e_mail,4,&tel,-1);
	printf("%s %s %s %s  %s\n",nb_etoile,emplacement,nom,e_mail,tel);
	gtk_entry_set_text(GTK_LABEL (nb_etoile1),(nb_etoile));
	gtk_entry_set_text(GTK_LABEL (emplacement1),(emplacement));
	gtk_entry_set_text(GTK_LABEL (nom1),(nom));
	gtk_entry_set_text(GTK_LABEL (e_mail1),(e_mail));
	gtk_entry_set_text(GTK_LABEL (tel1),(tel));
	
        gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}


void
on_buttonConfirmer_Fiche_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
hotel h;
char confirmation[50];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *output1;
input1=lookup_widget(objet,"entryNom_hotel");
input2=lookup_widget(objet,"entryTel");
input3=lookup_widget(objet,"entryEmplacement");
input4=lookup_widget(objet,"entryE_mail");
input5=lookup_widget(objet,"entryEtoiles");
output1=lookup_widget(objet,"labelConfirm");
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.tel,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.emplacement,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h.e_mail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(h.nb_etoile,gtk_entry_get_text(GTK_ENTRY(input5)));
if (verifier_ajouter(h)==1)
{GdkColor color;
 gdk_color_parse("green",&color);
 gtk_widget_modify_fg(output1,GTK_STATE_NORMAL,&color);
 gtk_label_set_text(GTK_LABEL(output1),confirmation);
 strcpy(confirmation,"Hotel ajouté");
 gtk_label_set_text(GTK_LABEL(output1),confirmation);
 ajouter_hotel(h);
}
else 
 {strcpy(confirmation,"Erreur d'ajout");
  gtk_label_set_text(GTK_LABEL(output1),confirmation);
 }

}


void
on_buttonRetour_Fiche_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;

	window1=lookup_widget(objet,"windowFiche_Hotel");
	window2=create_windowListes_Hotels();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
	treeview=lookup_widget(window2,"treeviewHotel");
	afficher_hotel(treeview);

}


void
on_buttonSupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkWidget *window1;
	GtkWidget *window2;
	char confirmation[50];
	hotel h;
	window1=lookup_widget(objet,"windowModifierHotel");
	GtkWidget *input1;
	GtkWidget *output1;
	input1=lookup_widget(objet,"entryMNom");
	output1=lookup_widget(objet,"labelConfirm1");
	strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	supprimer_hotel(h);
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), confirmation);
	strcpy(confirmation,"Suppression avec succes");
	gtk_label_set_text(GTK_LABEL(output1),confirmation);


}


void
on_buttonConfirmerM_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{  
        hotel h;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *output1;
	char succes[30];
	input1=lookup_widget(objet,"entryMNom");
	input2=lookup_widget(objet,"entryMTel");
	input3=lookup_widget(objet,"entryMEmplacement");
	input4=lookup_widget(objet,"entryMEmail");
        input5=lookup_widget(objet,"entryMEtoile");
	
	
	output1=lookup_widget(objet,"labelConfirm1");
	strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(h.tel,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(h.emplacement,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(h.e_mail,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(h.nb_etoile,gtk_entry_get_text(GTK_ENTRY(input5)));
	
	strcpy(succes,"Modification avec succés");
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), succes);
	modifier_hotel(h); 
}


void
on_button22_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	window1=lookup_widget(objet,"windowModifierhotel");

	window2=create_windowListes_Hotels();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
	
	treeview=lookup_widget(window2,"treeviewHotel");
            afficher_hotel(treeview);

}


void
on_buttonRetourL11_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{  GtkWidget *Ajouthotel;
	GtkWidget *Admin;
	

Ajouthotel=lookup_widget(objet_graphique,"windowListes_Hotels");
Admin=create_windowGProduits();
gtk_widget_destroy(Ajouthotel);

gtk_widget_show(Admin);

}



void
on_buttonMC_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview;
window1=lookup_widget(objet_graphique,"windowMClient");
gtk_widget_destroy(window1);
window2=create_windowConsulterClient();
gtk_widget_show(window2);
treeview=lookup_widget(window2,"treeview2");
afficher_Client(treeview);
}


void
on_buttonLogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Window1;
GtkWidget *Window2;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output1;

char username[50];
char password[50];
int  r=0;
char erreure[50];

Window1=lookup_widget(objet,"windowAuthentification");
input1=lookup_widget(objet,"entryUsername");
input2=lookup_widget(objet,"entryPassword");
output1= lookup_widget(objet, "labelConfirmerlogin");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
r=verifier(username,password);

  if(r==-1)
    {
        strcpy(erreure,"id et/ou mot de passe incorret !");
        GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), erreure);
    }

  else if(r==1)
    {
        Window2=create_windowAdmin();	
        gtk_widget_hide(Window1);		
	gtk_widget_show (Window2); 
    }
  else if(r==2)
    {
        Window2=create_windowAdmin();	/***** add window employe */
        gtk_widget_hide(Window1);		
	gtk_widget_show (Window2); 
    }
  else 
    {
        Window2=create_acceuil_client();	/* add window client */
        gtk_widget_hide(Window1);		
	gtk_widget_show (Window2); 
    }
}



void
on_buttonaddreclamation_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char envoye[30];
Reclamation r ;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *reclamationclient ;
GtkWidget *output1;
reclamationclient=lookup_widget(objet_graphique,"reclamationclient");

input1=lookup_widget(objet_graphique,"entrynom");
input2=lookup_widget(objet_graphique,"entryprenom");
input3=lookup_widget(objet_graphique,"entryemailclient");
input4=lookup_widget(objet_graphique,"entryreclamation");
input5=lookup_widget(objet_graphique,"labelnontraitee");
output1=lookup_widget(objet_graphique,"labelsortieenvoye");

strcpy(r.nomr,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.message,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(r.etat,gtk_label_get_text(GTK_LABEL(input5)));

ajouter_reclamation(r) ; 
GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1),envoye);
	strcpy(envoye,"Reclamation envoyée");
	gtk_label_set_text(GTK_LABEL(output1),envoye);
}


void
on_treeviewreclamation_row_activated   (GtkWidget    *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *nomr,*prenom,*adresse,*message,*etat;
	GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *nom1,*prenom1,*adresse1,*message1,*etat1;
	window1=lookup_widget(objet_graphique,"affichagereclamationadmin");
	treeview=lookup_widget(objet_graphique,"treeviewreclamation");
	window2=create_windowsupp();
	nom1=lookup_widget(window2,"labelnom1");
	prenom1=lookup_widget(window2,"labelprenom1");
	adresse1=lookup_widget(window2,"labeladresse1");
        message1=lookup_widget(window2,"labelmessage1");
        etat1=lookup_widget(window2,"entrycommentaire");
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&nomr,1,&prenom,2,&adresse,3,&message,4,&etat,-1);
	printf("%s %s %s %s%s\n",nomr,prenom,adresse,message,etat);
	gtk_label_set_text(GTK_LABEL (nom1),(nomr));
	gtk_label_set_text(GTK_LABEL (prenom1),(prenom));
	gtk_label_set_text(GTK_LABEL (adresse1),(adresse));
	gtk_label_set_text(GTK_LABEL (message1),(message));
	gtk_entry_set_text(GTK_ENTRY (etat1),(etat));
	gtk_widget_hide(window1);
	gtk_widget_show(window2);
}


void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

        Reclamation r ;
   
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *output1;
	char modifie[30];
	input1=lookup_widget(objet_graphique,"labelnom1");
	input2=lookup_widget(objet_graphique,"labelprenom1");
        input3=lookup_widget(objet_graphique,"labeladresse1");
        input4=lookup_widget(objet_graphique,"labelmessage1");
        input5=lookup_widget(objet_graphique,"entrycommentaire");
        output1=lookup_widget(objet_graphique,"labelsortiemodifie");
	
	strcpy(r.nomr,gtk_label_get_text(GTK_LABEL(input1)));
	strcpy(r.prenom,gtk_label_get_text(GTK_LABEL(input2)));
        strcpy(r.adresse,gtk_label_get_text(GTK_LABEL(input3)));
        strcpy(r.message,gtk_label_get_text(GTK_LABEL(input4)));
	strcpy(r.etat,gtk_entry_get_text(GTK_ENTRY(input5)));
        modifier_etat(r) ;
	strcpy(modifie,"Modification faite");
        GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), modifie);
	
}


void
on_buttondeleter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1,*window2,*treeview;

 GtkWidget  *adresse1 , *output1 ;
    Reclamation r ;
 char supprime[30] ;

    
	
	adresse1=lookup_widget(objet_graphique, "labeladresse1");

	output1=lookup_widget(objet_graphique,"labelsortiesupprime");
 strcpy(r.adresse,gtk_label_get_text(GTK_LABEL(adresse1)));


    supprimerligne(r);
  
        GdkColor color;
	gdk_color_parse ("blue", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), supprime);
	strcpy(supprime,"Suppression avec succés");
	gtk_label_set_text(GTK_LABEL(output1),supprime);

}





void
on_buttonretourreclamationcl_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
	GtkWidget *window2 ;
	window1=lookup_widget(objet_graphique,"reclamationclient");
	
        window2=lookup_widget(objet_graphique,"acceuil_client"); 
        window2=create_acceuil_client();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}




void
on_buttonretourreclamation_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{  GtkWidget *window1;
	GtkWidget *window2;
	GtkWidget *treeview;
	window1=lookup_widget(objet_graphique,"windowsupp");

	window2=create_affichagereclamationadmin();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
	
	treeview=lookup_widget(window2,"treeviewreclamation");
		afficher_reclamation(treeview);
	

}


void
on_buttondepotreclamation_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *window1;
	GtkWidget *window2;
	window1=lookup_widget(objet_graphique,"acceuil_client") ;
	window2=create_reclamationclient() ;
	gtk_widget_destroy(window1);
	gtk_widget_show(window2) ;
}


void
on_buttonReclamation_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowAdmin;
GtkWidget *affichagereclamationadmin;
GtkWidget *treeviewreclamation;
windowAdmin=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_destroy(windowAdmin);
affichagereclamationadmin=lookup_widget(objet_graphique,"affichagereclamationadmin");
affichagereclamationadmin = create_affichagereclamationadmin ();
gtk_widget_show(affichagereclamationadmin);
treeviewreclamation=lookup_widget(affichagereclamationadmin,"treeviewreclamation");
afficher_reclamation(treeviewreclamation);
}


void
on_buttonretour_hotel_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *acceuil_client;
GtkWidget *choix_hotel;

choix_hotel=lookup_widget(objet,"choix_hotel");
gtk_widget_destroy(choix_hotel);
acceuil_client=create_acceuil_client();
gtk_widget_show(acceuil_client);
}


void
on_buttonhotel_reserve_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *choix_hotel;
GtkWidget *window2;
GtkWidget *treeview1;

choix_hotel=lookup_widget(objet,"choix_hotel");
window2=create_panier_hotel();
gtk_widget_destroy(choix_hotel);

gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeview_hotel");
afficher_hotel1(treeview1);
}


void
on_buttonreserver_hotel_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *Nom;
GtkWidget *Emplacement;
GtkWidget *Date_arrive;
GtkWidget *Date_retour;
GtkWidget *sortie;

char emplacement[30];
char d_arrive[30];
char d_retour[30];
char nom[30];
int i,n;
reservation_hotel h;
hotel a;
Nom=lookup_widget(objet,"comboboxnom_hotel");
Emplacement=lookup_widget(objet,"comboboxemplacement");
Date_arrive=lookup_widget(objet,"entrydate_arrive");
Date_retour=lookup_widget(objet,"entrydate_retour");
sortie=lookup_widget(objet,"labelconfirmationR");
strcpy(h.a.nom,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Nom)));
strcpy(h.a.emplacement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Emplacement)));
strcpy(h.d_arrive,gtk_entry_get_text(GTK_ENTRY(Date_arrive)));
strcpy(h.d_retour,gtk_entry_get_text(GTK_ENTRY(Date_retour)));
if (verifier1(h.a.nom,h.a.emplacement))
{
ajouter_hotel1(h);
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (sortie, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(sortie),"reservation réussite");}
else 
{GdkColor color;
gdk_color_parse ("red", &color);
gtk_widget_modify_fg (sortie, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(sortie),"verifier les donnees");}

}


void
on_buttonhotel_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *acceuil_client;
GtkWidget *choix_hotel;

acceuil_client=lookup_widget(objet,"acceuil_client");
gtk_widget_destroy(acceuil_client);
choix_hotel=create_choix_hotel();
gtk_widget_show(choix_hotel);
}


void
on_treeview_hotel_row_activated        (GtkWidget       *objet,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *emplacement,*nom,*d_arrive,*d_retour;
	GtkWidget *hotel_panier;
	GtkWidget *window2;
	GtkWidget *treeview;
	GtkWidget *emplacement1,*nom1,*d_arrive1,*d_retour1;
	hotel_panier=lookup_widget(objet,"panier_hotel");
	treeview=lookup_widget(objet,"treeview_hotel");
        
	window2=create_modifie();
	emplacement1=lookup_widget(window2,"labelemplacementr1");
        nom1=lookup_widget(window2,"labelnomr1");
	d_arrive1=lookup_widget(window2,"entryarrive_modif");
	d_retour1=lookup_widget(window2,"entryetour_modif");
	
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&emplacement,1,&nom,2,&d_arrive,3,&d_retour,-1);
	printf("%s %s %s %s \n",emplacement,nom,d_arrive,d_retour);
        gtk_label_set_text(GTK_LABEL (emplacement1),(emplacement));	
        gtk_label_set_text(GTK_LABEL (nom1),(nom));
	gtk_entry_set_text(GTK_ENTRY (d_arrive1),(d_arrive));
	gtk_entry_set_text(GTK_ENTRY (d_retour1),(d_retour));
        gtk_widget_destroy(hotel_panier);
	gtk_widget_show(window2);
}


void
on_buttonretour_panier_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *panier_hotel;
GtkWidget *choix_hotel;

panier_hotel=lookup_widget(objet,"panier_hotel");
gtk_widget_destroy(panier_hotel);
choix_hotel=create_choix_hotel();
gtk_widget_show(choix_hotel);
}


void
on_buttonretour_modifierh_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
        GtkWidget *window1;
	GtkWidget *window2;
        GtkWidget *treeview1;
	window1=lookup_widget(objet,"modifie");
	window2=create_panier_hotel();
	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
	treeview1=lookup_widget(window2,"treeview_hotel");
	afficher_hotel1(treeview1);
}


void
on_buttonmodifierp_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
reservation_hotel h ;
	GtkWidget *input1;
	GtkWidget *input2;

        GtkWidget *output3;
        GtkWidget *output4;
        GtkWidget *output1;
        char succes[30];
	input1=lookup_widget(objet,"entryarrive_modif");
	input2=lookup_widget(objet,"entryetour_modif");
	output3=lookup_widget(objet,"labelnomr1");
	output4=lookup_widget(objet,"labelemplacementr1");
       
	output1=lookup_widget(objet,"confirmationR");


	strcpy(h.d_arrive,gtk_entry_get_text(GTK_ENTRY(input1)));

	strcpy(h.d_retour,gtk_entry_get_text(GTK_ENTRY(input2)));

        strcpy(h.a.nom,gtk_label_get_text(GTK_LABEL(output3)));
	strcpy(h.a.emplacement,gtk_label_get_text(GTK_LABEL(output4)));


	strcpy(succes,"Modification avec succés");
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), succes);

	modifier_hotelp(h);
}


void
on_buttonsupprimerp_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	char Confirmation[50];
	reservation_hotel h;
	window1=lookup_widget(objet,"modifie");
	GtkWidget *input1;
	GtkWidget *output1;
	input1=lookup_widget(objet,"labelnomr1");
	output1=lookup_widget(objet,"confirmationR");
	strcpy(h.a.nom,gtk_label_get_text(GTK_LABEL(input1)));
	supprimerhotelp(h);
	GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), Confirmation);
	strcpy(Confirmation,"Suppression avec succes");
	gtk_label_set_text(GTK_LABEL(output1),Confirmation);
}


void
on_buttonretourgestion_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *affichagereclamationadmin ;
	GtkWidget *windowAdmin;
	affichagereclamationadmin=lookup_widget(objet_graphique,"affichagereclamationadmin");
	
        windowAdmin=lookup_widget(objet_graphique,"windowAdmin"); 
        windowAdmin=create_windowAdmin();
	gtk_widget_destroy(affichagereclamationadmin);
	gtk_widget_show(windowAdmin);
}

