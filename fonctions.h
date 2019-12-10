#include <gtk/gtk.h>

typedef struct
{
char jour[10];
char mois[10];
char annee[10];
}Date;
typedef struct
{

char nom_e[30];
char prenom_e[30];
char date_naissance_e[30];
char matricule_e[30];
char username_e[30];
char adresse_e[30];
char password_e[30];
char email_e[30];
}Employe;

typedef struct
{
char nom_c[30];
char prenom_c[30];
char date_naissance_c[30];
char cin[30];
char n_passport[30];
char adresse_c[30];
char username_c[30];
char password_c[30];
char email_c[30];
}Client;

typedef struct
{

char nom_a[30];
char prenom_a[30];
char date_naissance_a[30];
char matricule_a[30];
char adresse_a[30];
char username_a[30];
char password_a[30];
char email_a[30];
}Admin;

void ajouter_Employe(Employe e);
void afficher_Employe(GtkWidget *liste);
void Supprimer_Employe (Employe e);
void Modifier_Employe(Employe e);

void ajouter_Client(Client c);
void afficher_Client(GtkWidget *liste);
void Supprimer_Client(Client c);
void Modifier_Client(Client c);

void ajouter_Admin(Admin a);
void afficher_Admin(GtkWidget *liste);
void Supprimer_Admin (Admin a);
void Modifier_Admin(Admin a);
