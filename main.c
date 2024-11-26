#include <stdio.h>
#define MAX_TACHES 50

typedef struct {
    int jours;
    int mois;
    int annee;
} Date;

typedef struct {
    int Priorite;
    char titre[70];
    char Description[80];
    Date date;
} Tache;
Tache ListeTaches[MAX_TACHES];
int countTaches = 0;

void AjouterTache() {
    if (countTaches < MAX_TACHES) {
        Tache nouvelleTache;
        printf("Donner le titre de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.titre);

        printf("Donner la description de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.Description);


            printf("Donner la Date de la tache : \n");
            printf(" Date jours: ");
            scanf("%d", &nouvelleTache.date.jours);
            printf(" Date mois: ");
            scanf("%d", &nouvelleTache.date.mois);
            printf(" Date annee: ");
            scanf("%d", &nouvelleTache.date.annee);
            printf("Donner la prioritee de la tache (0: low / 1: high) : ");
            scanf("%d", &nouvelleTache.Priorite);
        ListeTaches[countTaches++] = nouvelleTache;
        printf("Tache ajoutee avec succes!\n");
    } else {
        printf("La liste de taches est pleine. Impossible d'ajouter plus de taches.\n");
    }
}

void AfficherListeTaches() {
    if (countTaches > 0) {
        printf("----------------Liste des taches :------------------\n");
        for (int i = 0; i < countTaches; i++) {
            printf("----Tache %d :\n", i + 1);
            printf("Titre : %s\n", ListeTaches[i].titre);
            printf("Description : %s\n", ListeTaches[i].Description);
            printf("Date : %d-%d-%d\n", ListeTaches[i].date.jours, ListeTaches[i].date.mois, ListeTaches[i].date.annee);
            printf("Priorite : %s\n", (ListeTaches[i].Priorite == 0) ? "low" : "high");
            printf("\n");
        }
    } else {
        printf("Aucune tache a afficher!\n");
    }
}
void SupprimerTache() {
    if (countTaches > 0) {
        int indexSuppression;
        printf("Entrez l'index de la tache a supprimer (1-%d) : ", countTaches);
        scanf("%d", &indexSuppression);

        if (indexSuppression >= 1 && indexSuppression <= countTaches) {

            for (int i = indexSuppression - 1; i < countTaches - 1; i++) {
                ListeTaches[i] = ListeTaches[i + 1];
            }
            countTaches--;
            printf("Tache supprimee avec succes!\n");
        } else {
            printf("Index invalide. Veuillez entrer un index compris entre 1 et %d.\n", countTaches);
        }
    } else {
        printf("Aucune tache a supprimer.\n");
    }
}
void ModifierTache() {
    if (countTaches > 0) {
        int indexModification;
        printf("Entrez l'index de la tache a modifier (1-%d) : ", countTaches);
        scanf("%d", &indexModification);

        if (indexModification >= 1 && indexModification <= countTaches) {
            Tache *tacheAModifier = &ListeTaches[indexModification - 1];

            printf("Nouvelle description (laisser vide pour ne pas modifier) : ");
            scanf(" %[^\n]s", tacheAModifier->Description);

            printf("Nouvelle date (jours mois annee) : ");
            scanf("%d %d %d", &tacheAModifier->date.jours, &tacheAModifier->date.mois, &tacheAModifier->date.annee);

            printf("Nouvelle priorite (0 ou 1) : ");
            scanf("%d", &tacheAModifier->Priorite);

            printf("Tache modifiee avec succes!\n");
        } else {
            printf("Index invalide. Veuillez entrer un index compris entre 1 et %d.\n", countTaches);
        }
    } else {
        printf("Aucune tache a modifier.\n");
    }
}

int main() {
    int choix;
    do {
        printf("\n Menu:\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la liste des taches\n");
        printf("3. Suprimer une tache\n");
        printf("4. Modifier une tache\n");
        printf("Choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                AjouterTache();
                break;
            case 2:
                AfficherListeTaches();
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 2.\n");
            case 3:
                SupprimerTache();
                break;
            case 4:
                ModifierTache();
                break;
        }
    } while (choix != 0);
    return 0;
}
