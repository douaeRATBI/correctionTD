#include <stdio.h>
#include <stdlib.h>

int hasard(int max) {
    return rand() % max;
}

int main() {
    char mer[10][10];
    char car;
    int nbateaux;
    int i, j;
    int ncoups;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            mer[i][j] = ' ';
    nbateaux = 10;

    while (nbateaux > 0) {
        i = hasard(10); // Génère un indice de ligne aléatoire entre 0 et 9
        j = hasard(10); // Génère un indice de colonne aléatoire entre 0 et 9
        if (mer[i][j] == ' ') {
            mer[i][j] = 'B';
            nbateaux -= 1;
        }
    }

    ncoups = 0;
    
    // Afficher les numéros de colonne
    printf("  0 1 2 3 4 5 6 7 8 9 \n");
    
    for (i = 0; i < 10; i++) {
        printf("%d ", i); // Afficher le numéro de ligne
        
        for (j = 0; j < 10; j++) {
            if (mer[i][j] == 'B')
                car = ' ';
            else if (mer[i][j] == 'x')
                car = 'x';
            else
                car = ' ';
            printf("%c ", car);
        }
        
        printf("%d\n", i);
    }
    
    // Afficher les numéros de colonne
    printf("  0 1 2 3 4 5 6 7 8 9 \n");

    while (nbateaux > 0) {
        printf("Entrez les coordonnées ligne et colonne : ");
        if (scanf("%d %d", &i, &j) != 2)
            exit(0);
        ncoups += 1;
        switch (mer[i][j]) {
            case ' ':
                printf("Dans l'eau\n");
                mer[i][j] = 'x';
                nbateaux -= 1;
                break;

            case 'x':
                printf("Cas déjà joué\n");
                break;

            default:
                printf("Vous avez déjà tiré ici.\n");
        }
    }
    printf("Vous avez gagné en %d coups... Bravo\n", ncoups);
    return 0;
}
