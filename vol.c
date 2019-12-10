#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "vol.h"
enum
{
	aerodepart,
	aeroarrivee,
	
	dd,
	dr,
	hd,
	ha,
	numvol,
	numsiege,
COLUMNS
};
int verifier_ajout(vol v)
{
	if(strcmp(v.aeroportdepart,"")==0 || strcmp(v.aeroportarrivee,"")==0|| strcmp(v.datedepart,"")==0|| strcmp(v.dateretour,"")==0|| strcmp(v.heuredepart,"")==0|| strcmp(v.heurearrivee,"")==0|| strcmp(v.numerovol,"")==0|| strcmp(v.nombresiege,"")==0) return 0;
else return 1;
}
void ajouter_vol(vol v)
{
FILE* f;
f=fopen("vol.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s %s %s \n",v.aeroportdepart,v.aeroportarrivee,v.datedepart,v.dateretour,v.heuredepart,v.heurearrivee,v.numerovol,v.nombresiege);
   }
fclose(f);
}

void afficher_vol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char AeroDepart[30];
char AeroArrivee[30];
char Numvol[30];
char DD[30];
char DR[30];
char HD[30];
char HA[30];
char Numsiege[30];
store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("AeroDepart",renderer,"text",aerodepart,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("AeroArrivee",renderer,"text",aeroarrivee,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("DD",renderer,"text",dd,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("DR",renderer,"text",dr,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("HD",renderer,"text",hd,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("HA",renderer,"text",ha,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("NUMVOL",renderer,"text",numvol,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Numsiege",renderer,"text",numsiege,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("vol.txt","r");

     if(f!=NULL)
        {
         while(fscanf(f,"%s %s %s %s %s %s %s %s \n",AeroDepart,AeroArrivee,DD,DR,HD,HA,Numvol,Numsiege)!=EOF)
          {
           gtk_list_store_append(store,&iter);
     gtk_list_store_set(store,&iter,aerodepart,AeroDepart,aeroarrivee,AeroArrivee,dd,DD,dr,DR,hd,HD,ha,HA,numvol,Numvol,numsiege,Numsiege,-1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}

void supprimervol (vol y)
{
	vol v;
FILE *f;
FILE *g;
f=fopen("vol.txt","r");
g=fopen("vol2.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",v.aeroportdepart,v.aeroportarrivee,v.datedepart,v.dateretour,v.heuredepart,v.heurearrivee,v.numerovol,v.nombresiege)!=EOF)
{
if(strcmp(y.numerovol,v.numerovol)!=0) fprintf(g,"%s %s %s %s %s %s %s %s \n",v.aeroportdepart,v.aeroportarrivee,v.datedepart,v.dateretour,v.heuredepart,v.heurearrivee,v.numerovol,v.nombresiege);
}
fclose(f);
fclose(g);
remove("vol.txt");
rename("vol2.txt","vol.txt");
}

void modifier_vol(vol y)
{
vol v;
FILE *f;
FILE *aux;
aux=NULL;
f=fopen("vol.txt","r+");
aux=fopen("vol2.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",v.aeroportdepart,v.aeroportarrivee,v.datedepart,v.dateretour,v.heuredepart,v.heurearrivee,v.numerovol,
v.nombresiege)!=EOF)
 {
	if(strcmp(y.numerovol,v.numerovol)==0) v=y;
                fprintf(aux,"%s %s %s %s %s %s %s %s \n",v.aeroportdepart,v.aeroportarrivee,v.datedepart,v.dateretour,v.heuredepart,v.heurearrivee,v.numerovol,
v.nombresiege);
   
            }
    fclose(aux);
    fclose(f);
	remove("vol.txt");
      rename("vol2.txt","vol.txt");
}
}
