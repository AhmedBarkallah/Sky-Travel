#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include"reclamation.h"

enum
{
NOM,
PRENOM,
ADRESSE,
MESSAGE,
ETAT,
COLUMNS
};

void ajouter_reclamation(Reclamation r)
{
FILE* f;

f=fopen("/home/poca/Projects/projectc/reclamation.txt","a");
  if(f!=NULL)
   { 
    
   fprintf(f," %s :%s : %s :%s : %s  \n",r.nom,r.prenom,r.adresse,r.message,r.etat);
 
   } 
fclose(f);

}



   void afficher_reclamation(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char nom[30];
char prenom[30];
char adresse[30];
char message[600] ;
char etat[30] ;
store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Adresse",renderer,"text",ADRESSE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Reclamation",renderer,"text",MESSAGE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
 renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  

   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

   f=fopen("/home/poca/Projects/projectc/reclamation.txt","r");

     if(f!=NULL)
        {
         f=fopen("/home/poca/Projects/projectc/reclamation.txt","a+");
         while(fscanf(f,"%[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %s ",nom,prenom,adresse,message,etat)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,ADRESSE,adresse,MESSAGE,message,ETAT,etat,-1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}

void supprimerligne(Reclamation re)
{ 
    Reclamation r ;
    FILE *f ;
    FILE *g;
    f=fopen("/home/poca/Projects/projectc/reclamation.txt","r");
    g=fopen("/home/poca/Projects/projectc/fich.txt","a+");
    while(fscanf(f,"%[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %s \n",r.nom,r.prenom,r.adresse,r.message,r.etat)!=EOF)
{
        if(strcmp(re.adresse,r.adresse)!=0)
fprintf(g,"%s : %s : %s : %s : %s \n",r.nom,r.prenom,r.adresse,r.message,r.etat);
}
fclose(f);
fclose(g);
remove("/home/poca/Projects/projectc/reclamation.txt");
rename("/home/poca/Projects/projectc/fich.txt","/home/poca/Projects/projectc/reclamation.txt");
} 
void modifier_etat(Reclamation re)
{
 Reclamation r ;
FILE *f;
FILE *t;
t=NULL;
f=fopen("/home/poca/Projects/projectc/reclamation.txt","r+");
t=fopen("/home/poca/Projects/projectc/reclamation1.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %s \n",r.nom,r.prenom,r.adresse,r.message,r.etat)!=EOF)
 {
	if(strcmp(re.adresse,r.adresse)==0) r=re;
                fprintf(t," %s : %s : %s : %s : %s \n",r.nom,r.prenom,r.adresse,r.message,r.etat);
   
            }
    fclose(t);
    fclose(f);
	remove("/home/poca/Projects/projectc/reclamation.txt");
      rename("/home/poca/Projects/projectc/reclamation1.txt","/home/poca/Projects/projectc/reclamation.txt");
}
}

