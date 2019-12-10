#include <gtk/gtk.h> 

typedef struct 
{ 
char nb_etoile[30] ; 
char emplacement [30] ; 
char nom [30] ;
char e_mail[30] ; 
char tel[30] ;
} hotel; 

void ajouter_hotel(hotel h); 
void modifier_hotel(hotel h); 
void supprimer_hotel(hotel h); 
void afficher_hotel(GtkWidget *liste); 
int verifier_ajouter(hotel h) ;
typedef struct
{
hotel a;
char d_arrive[30];
char d_retour[30];
}reservation_hotel;
int verifier1 (char nom[30],char emplacement[30]);
void ajouter_hotel1(reservation_hotel h );
void afficher_hotel1(GtkWidget *liste);
void modifier_hotelp(reservation_hotel h);
void supprimerhotelp (reservation_hotel h);


