#include <stdio.h>
#include <stdlib.h>

#define RIEN ' '
#define BATEAU 'B'
#define DEJA_JOUE '*'
#define BATEAU_COULE 'X'

int hasard() {
    return rand() % 10; // Génère un nombre aléatoire entre 0 et 9 inclus.
}

int main() {
    char mer[10][10];
    char car;
    int nbateaux;
    int i, j;
    int ncoups;

    /*
     * Placer des bateaux dans la mer
     */

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            mer[i][j] = RIEN;
    nbateaux = 10;

    while (nbateaux > 0) {
        i = hasard();
        j = hasard();
        if (mer[i][j] == RIEN) {
            mer[i][j] = BATEAU;
            nbateaux -= 1;
        }
    }
    nbateaux = 10;

    /*
     * Boucle principale
     */

    ncoups = 0;
    while (nbateaux > 0) {
        /*
         * Afficher la mer
         */

        printf("  0 1 2 3 4 5 6 7 8 9 \n");
        for (i = 0; i < 10; i++) {
            printf("%d ", i);
            for (j = 0; j < 10; j++) {
                if (mer[i][j] == BATEAU)
                    car = RIEN;
                else
                    car = mer[i][j];
                printf("%c ", car);
            }
            printf("%d\n", i);
        }
        printf("  0 1 2 3 4 5 6 7 8 9 \n");

        /*
         * Attendre le coup de l'utilisateur
         */

        printf(" Entrez les coordonnées (ligne colonne) : ");
        if (scanf("%d %d", &i, &j) != 2)
            exit(0);

        if (i < 0 || i > 9 || j < 0 || j > 9) {
            printf("Coordonnées invalides. Veuillez entrer des coordonnées entre 0 et 9.\n");
            continue;
        }

        /*
         * Tester la réponse
         */

        ncoups += 1;
        switch (mer[i][j]) {
            case RIEN:
                printf("Dans l'eau\n");
                mer[i][j] = DEJA_JOUE;
                break;
            case DEJA_JOUE:
            case BATEAU_COULE:
                printf("Case déjà jouée\n");
                break;
            case BATEAU:
                printf("Touché !\n");
                mer[i][j] = BATEAU_COULE;
                nbateaux -= 1;
                break;
        }
    }

    /*
     * Afficher le résultat et sortir
     */

    printf("Vous avez gagné en %d coups... Bravo\n", ncoups);
    return 0;
}
