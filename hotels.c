#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "hotels.h"
enum
{   nb_etoile,
    emplacement,
    nom,
    e_mail,
    tel,
    COLUMNS
};
int verifier_ajouter(hotel h)
{
	if(strcmp(h.nb_etoile,"")==0 || strcmp(h.emplacement,"")==0|| strcmp(h.nom,"")==0|| strcmp(h.e_mail,"")==0|| strcmp(h.tel,"")==0) return (0);
else return (1);
}
void ajouter_hotel(hotel h)
{
FILE* f;
f=fopen("hotels.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s \n",h.nb_etoile,h.emplacement,h.nom,h.e_mail,h.tel);
   }
fclose(f);
}

void afficher_hotel(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nb_etoile1[30] ; 
char emplacement1 [30] ; 
char nom1 [30] ;
char e_mail1[30] ; 
char tel1[30] ;
store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("nb_etoile1",renderer,"text",nb_etoile,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("emplacement1",renderer,"text",emplacement,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("nom1",renderer,"text",nom,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("e_mail1",renderer,"text",e_mail,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("tel1",renderer,"text",tel,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   
   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("hotels.txt","r");

     if(f!=NULL)
        {
         while(fscanf(f,"%s %s %s %s %s\n",nb_etoile1,emplacement1,nom1,e_mail1,tel1)!=EOF)
          {
           gtk_list_store_append(store,&iter);
     gtk_list_store_set(store,&iter,nb_etoile,nb_etoile1,emplacement,emplacement1,nom,nom1,e_mail,e_mail1,tel,tel1,-1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}

void supprimer_hotel (hotel x)
{
	hotel h;
FILE *f;
FILE *g;
f=fopen("hotels.txt","r");
g=fopen("hotels2.txt","a+");
while (fscanf(f,"%s %s %s %s %s \n",h.nb_etoile,h.emplacement,h.nom,h.e_mail,h.tel)!=EOF)
{
if(strcmp(x.nom,h.nom)!=0) 
fprintf(g,"%s %s %s %s %s \n",h.nb_etoile,h.emplacement,h.nom,h.e_mail,h.tel);
}
fclose(f);
fclose(g);
remove("hotels.txt");
rename("hotels2.txt","hotels.txt");
}

void modifier_hotel(hotel h1)
{
hotel v;
FILE *f;
FILE *aux;
aux=NULL;
f=fopen("hotels.txt","r+");
aux=fopen("hotels2.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s  \n",v.nb_etoile,v.emplacement,v.nom,v.e_mail,v.tel)!=EOF)
 {
	if(strcmp(h1.nom,v.nom)==0) v=h1;
                fprintf(aux,"%s %s %s %s %s  \n",v.nb_etoile,v.emplacement,v.nom,v.e_mail,v.tel);
}
 fclose(aux);
    fclose(f);
	remove("hotels.txt");
      rename("hotels2.txt","hotels.txt");
}
}

