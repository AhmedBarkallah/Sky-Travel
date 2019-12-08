#include<gtk/gtk.h>
typedef struct
{
char nomr[30];
char prenom[30];
char adresse[30];
char message[600];
char etat[30]; 


} Reclamation ;


void ajouter_reclamation(Reclamation r) ;

void afficher_reclamation(GtkWidget *liste);
void supprimerligne(Reclamation re) ;
void modifier_etat(Reclamation re) ;
