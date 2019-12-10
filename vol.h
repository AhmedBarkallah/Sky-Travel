#include <gtk/gtk.h>
typedef struct
{
char numerovol[30];
char aeroportdepart[30];
char aeroportarrivee[30];
char datedepart[30];
char dateretour[30];
char nombresiege[30];
char heuredepart[30];
char heurearrivee[30];
}vol;

void afficher_vol(GtkWidget *liste);
void ajouter_vol(vol v);
int verifier_ajout(vol v);
void supprimervol (vol v);
void modifier_vol(vol v);
