#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "hotels.h"
#include <gtk/gtk.h>


enum
{

  EMPLACEMENT,
  NOM,
  ARRIVE,
  RETOUR,
  COLUMNS
};

void ajouter_hotel1(reservation_hotel h )
{
FILE* f;

f=fopen("hotel_reserve.txt","a");
     
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s \n",h.a.emplacement,h.a.nom,h.d_arrive,h.d_retour);
   }

fclose(f);
}
void afficher_hotel1(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char emplacement[30];
char nom[30];
char d_arrive[30];
char d_retour[30];
store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EMPLACEMENT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("d_arrive",renderer,"text",ARRIVE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("d_retour",renderer,"text",RETOUR,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

   f=fopen("hotel_reserve.txt","r");

     if(f!=NULL)
        {
         f=fopen("hotel_reserve.txt","a+");
         while(fscanf(f,"%s %s %s %s  ",emplacement,nom,d_arrive,d_retour)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,EMPLACEMENT,emplacement,NOM,nom,ARRIVE,d_arrive,RETOUR,d_retour,-1);
          }
        }
   fclose(f);


   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}


int verifier1(char nom [30],char emplacement[30])
{
int v=0;
reservation_hotel h;
FILE* f=fopen("hotels.txt","r");
 if(f!=NULL)
  {
   while(v!=1 && fscanf(f,"%s %s %s %s %s",h.a.nb_etoile,h.a.emplacement,h.a.nom,h.a.e_mail,h.a.tel)!=EOF)
     {
       if(strcmp(nom,h.a.nom)==0 && strcmp(emplacement,h.a.emplacement)==0 )

               {
                v=1;
               }
      }
   }
return(v);
fclose(f);
}

void supprimerhotelp (reservation_hotel Rh1)

{

reservation_hotel Rh;
FILE *f;
FILE *g;
f=fopen("hotel_reserve.txt","r");
g=fopen("hotel_reserve2.txt","a+");

while (fscanf(f,"%s %s %s %s  \n",Rh.a.emplacement,Rh.a.nom,Rh.d_arrive,Rh.d_retour)!=EOF)
{
if(strcmp(Rh1.a.nom,Rh.a.nom)!=0  ) 
fprintf(g,"%s %s %s %s \n",Rh.a.emplacement,Rh.a.nom,Rh.d_arrive,Rh.d_retour);
}
fclose(f);
fclose(g);
remove("hotel_reserve.txt");
rename("hotel_reserve2.txt","hotel_reserve.txt");
}



void modifier_hotelp(reservation_hotel h)
{
reservation_hotel v ;
FILE* f;
FILE* aux;
aux=NULL;
f=fopen("hotel_reserve.txt","r");
aux=fopen("hotel_reserve1.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s \n ",v.a.emplacement,v.a.nom,v.d_arrive,v.d_retour)!=EOF)
 {
	if(strcmp(h.a.nom,v.a.nom)==0 )
                fprintf(aux,"%s %s %s %s \n ",h.a.emplacement,h.a.nom,h.d_arrive,h.d_retour);
         else
                fprintf(aux,"%s %s %s %s \n ",v.a.emplacement,v.a.nom,v.d_arrive,v.d_retour);
   }}         
    fclose(aux);
    fclose(f);
    

	remove("hotel_reserve.txt");
      rename("hotel_reserve1.txt","hotel_reserve.txt");

}
   





