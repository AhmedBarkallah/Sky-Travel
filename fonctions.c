#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "fonctions.h"
enum
{ NOM_E,
  PRENOM_E,
  DATE_E,
  MATRICULE_E,
  ADRESSE_E,
  USERNAME_E,
  PASSWORD_E,
  EMAIL_E,
  COLUMNS1
};
enum
{ NOM_A,
  PRENOM_A,
  DATE_A,
  MATRICULE_A,
  ADRESSE_A,
  USERNAME_A,
  PASSWORD_A,
  EMAIL_A,
  COLUMNS2
};
enum
{ NOM_C,
  PRENOM_C,
  DATE_C,
  CIN,
  N_PASSPORT,
  ADRESSE_C,
  USERNAME_C,
  PASSWORD_C,
  EMAIL_C,
  COLUMNS3
};
void ajouter_Employe(Employe e)
{
FILE* f;
FILE* g;
f=fopen("Employe.txt","a");
g=fopen("Users.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s %s %s %d \n",e.nom_e,e.prenom_e,e.date_naissance_e,e.matricule_e,e.adresse_e,e.username_e,e.password_e,e.email_e,2);
fprintf(f,"%s %s  %d \n",e.username_e,e.password_e,2);
   }
fclose(f);
fclose(g);
}


void afficher_Employe(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom_e[30];
char prenom_e[30];
char date_naissance_e[30];
char matricule_e[30];
char adresse_e[30];
char username_e[30];
char password_e[30];
char email_e[30];

store=NULL;
FILE  *f;

store=gtk_tree_view_get_model(liste);
  if(store==NULL)
  { renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom_e",renderer,"text",NOM_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("prenom_e",renderer,"text",PRENOM_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("date_naissance_e",renderer,"text",DATE_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("matricule_e",renderer,"text",MATRICULE_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("adresse_e",renderer,"text",ADRESSE_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("username_e",renderer,"text",USERNAME_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
     column=gtk_tree_view_column_new_with_attributes("password_e",renderer,"text",PASSWORD_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("email_e",renderer,"text",EMAIL_E,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("Employe.txt","r");
    if(f!=NULL)
        {
         f=fopen("Employe.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %s %s",nom_e,prenom_e,date_naissance_e,matricule_e,adresse_e,username_e,password_e,email_e)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,NOM_E,nom_e,PRENOM_E,prenom_e,DATE_E,date_naissance_e,MATRICULE_E,matricule_e,ADRESSE_E,adresse_e,USERNAME_E,username_e,PASSWORD_E,password_e,EMAIL_E,email_e,-1);
          }
        }
   fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}

void Supprimer_Employe (Employe e1)
{
Employe e;	
FILE *f;
FILE *g;
f=fopen("Employe.txt","r");
g=fopen("Employe2.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",e.nom_e,e.prenom_e,e.date_naissance_e,e.matricule_e,e.adresse_e,e.username_e,e.password_e,e.email_e)!=EOF)
{if (strcmp(e1.nom_e,e.nom_e)!=0)
 fprintf(g,"%s %s %s %s %s %s %s %s \n",e.nom_e,e.prenom_e,e.date_naissance_e,e.matricule_e,e.adresse_e,e.username_e,e.password_e,e.email_e);
}
fclose(f);
fclose(g);
remove("Employe.txt");
rename("Employe2.txt","Employe.txt");
}
void Modifier_Employe(Employe y)
{
Employe v;
FILE *f;
FILE *aux;
aux=NULL;
f=fopen("Employe.txt","r+");
aux=fopen("Employe2.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",v.nom_e,v.prenom_e,v.date_naissance_e,v.matricule_e,v.adresse_e,v.username_e,v.password_e,
v.email_e)!=EOF)
 {
	if(strcmp(y.nom_e,v.nom_e)==0) v=y;
                fprintf(aux,"%s %s %s %s %s %s %s %s \n",v.nom_e,v.prenom_e,v.date_naissance_e,v.matricule_e,v.adresse_e,v.username_e,v.password_e,
v.email_e);
}
 fclose(aux);
    fclose(f);
	remove("Employe.txt");
      rename("Employe2.txt","Employe.txt");
}
}


void ajouter_Admin(Admin a)
{
FILE* f;
f=fopen("Admin.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s %s %s \n",a.nom_a,a.prenom_a,a.date_naissance_a,a.matricule_a,a.adresse_a,a.username_a,a.password_a,a.email_a);
   }
fclose(f);
}

void afficher_Admin(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom_a[30];
char prenom_a[30];
char date_naissance_a[30];
char matricule_a[30];
char adresse_a[30];
char username_a[30];
char password_a[30];
char email_a[30];

store=NULL;
FILE  *f;

store=gtk_tree_view_get_model(liste);
  if(store==NULL)
  { renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom_a",renderer,"text",NOM_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("prenom_a",renderer,"text",PRENOM_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("date_naissance_a",renderer,"text",DATE_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("matricule_a",renderer,"text",MATRICULE_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("adresse_a",renderer,"text",ADRESSE_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("username_a",renderer,"text",USERNAME_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("password_a",renderer,"text",PASSWORD_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("email_a",renderer,"text",EMAIL_A,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("Admin.txt","r");
    if(f!=NULL)
        {
         f=fopen("Admin.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %s %s",nom_a,prenom_a,date_naissance_a,matricule_a,adresse_a,username_a,password_a,email_a)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,NOM_A,nom_a,PRENOM_A,prenom_a,DATE_A,date_naissance_a,MATRICULE_A,matricule_a,ADRESSE_A,adresse_a,USERNAME_A,username_a,PASSWORD_A,password_a,EMAIL_A,email_a,-1);
          }
        }
   fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}
void Supprimer_Admin (Admin e1)
{
Admin e;	
FILE *f;
FILE *g;
f=fopen("Admin.txt","r");
g=fopen("Admin2.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",e.nom_a,e.prenom_a,e.date_naissance_a,e.matricule_a,e.adresse_a,e.username_a,e.password_a,e.email_a)!=EOF)
{if (strcmp(e1.nom_a,e.nom_a)!=0)
 fprintf(g,"%s %s %s %s %s %s %s %s \n",e.nom_a,e.prenom_a,e.date_naissance_a,e.matricule_a,e.adresse_a,e.username_a,e.password_a,e.email_a);
}
fclose(f);
fclose(g);
remove("Admin.txt");
rename("Admin2.txt","Admin.txt");
}

void ajouter_Client(Client c)
{
FILE* f;
f=fopen("Client.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s %s %s %s \n",c.nom_c,c.prenom_c ,c.date_naissance_c,c.cin,c.n_passport,c.adresse_c,c.username_c,c.password_c,c.email_c);
   }
fclose(f);
}
void Modifier_Admin(Admin y)
{
Admin v;
FILE *f;
FILE *aux;
aux=NULL;
f=fopen("Admin.txt","r+");
aux=fopen("Admin2.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",v.nom_a,v.prenom_a,v.date_naissance_a,v.matricule_a,v.adresse_a,v.username_a,v.password_a,
v.email_a)!=EOF)
 {
	if(strcmp(y.nom_a,v.nom_a)==0) v=y;
                fprintf(aux,"%s %s %s %s %s %s %s %s \n",v.nom_a,v.prenom_a,v.date_naissance_a,v.matricule_a,v.adresse_a,v.username_a,v.password_a,
v.email_a);
}
 fclose(aux);
    fclose(f);
	remove("Admin.txt");
      rename("Admin2.txt","Admin.txt");
}
}

void afficher_Client(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom_c[30];
char prenom_c[30];
char date_naissance_c[30];
char cin[30];
char n_passport[30];
char adresse_c[30];
char username_c[30];
char password_c[30];
char email_c[30];
store=NULL;
FILE  *f;

store=gtk_tree_view_get_model(liste);
  if(store==NULL)
  { renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom_c",renderer,"text",NOM_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("prenom_c",renderer,"text",PRENOM_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("date_naissance_c",renderer,"text",DATE_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("n_passport",renderer,"text",N_PASSPORT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("adresse_c",renderer,"text",ADRESSE_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("username_c",renderer,"text",USERNAME_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("password_c",renderer,"text",PASSWORD_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("email_c",renderer,"text",EMAIL_C,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    store=gtk_list_store_new(COLUMNS3,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("Client.txt","r");
    if(f!=NULL)
        {
         f=fopen("Client.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %s %s %s",nom_c,prenom_c,date_naissance_c,cin,n_passport,adresse_c,username_c,password_c,email_c)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,NOM_C,nom_c,PRENOM_C,prenom_c,DATE_C,date_naissance_c,CIN,cin,N_PASSPORT,n_passport,ADRESSE_C,adresse_c,USERNAME_C,username_c,PASSWORD_C,password_c,EMAIL_C,email_c, -1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}void Supprimer_Client (Client c1)
{
Client c;	
FILE *f;
FILE *g;
f=fopen("Client.txt","r");
g=fopen("Client2.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",c.nom_c,c.prenom_c,c.date_naissance_c,c.cin,c.n_passport,c.adresse_c,c.username_c,c.password_c,c.email_c)!=EOF)
{if (strcmp(c1.nom_c,c.nom_c)!=0)
 fprintf(g,"%s %s %s %s %s %s %s %s %s \n",c.nom_c,c.prenom_c,c.date_naissance_c,c.cin,c.n_passport,c.adresse_c,c.username_c,c.password_c,c.email_c);
}

fclose(f);
fclose(g);
remove("Client.txt");
rename("Client2.txt","Client.txt");
}
void Modifier_Client(Client c1)
{
Client c;
FILE *f;
FILE *aux;
aux=NULL;
f=fopen("Client.txt","r+");
aux=fopen("Client2.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",c.nom_c,c.prenom_c,c.date_naissance_c,c.cin,c.n_passport,c.adresse_c,c.username_c,
c.password_c,c.email_c)!=EOF)
 {if(strcmp(c.nom_c,c1.nom_c)==0) c=c1;
	
                fprintf(aux,"%s %s %s %s %s %s %s %s %s \n",c.nom_c,c.prenom_c,c.date_naissance_c,c.cin,c.n_passport,c.adresse_c,c.username_c,
c.password_c,c.email_c);
   
            }
    fclose(aux);
    fclose(f);
	remove("client.txt");
      rename("Client2.txt","Client.txt");
}
}

