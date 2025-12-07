#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definition du type pour simplifier et gerer les grands nombres */
/* unsigned long long permet d'aller jusqu'a 18,446,744,073,709,551,615 */
typedef unsigned long long ull;

/* 1. Fonction Puissance Recursive Naive */
ull puissance_recursif_naif(int base, int exposant) {
    /* Cas de base */
    if (exposant == 0) {
        return 1;
    }
    /* Appel recursif : x * x^(n-1) */
    return base * puissance_recursif_naif(base, exposant - 1);
}

/* 2. Fonction Puissance Iterative Naive (O(n)) */
ull puissance_iteratif_naif(int base, int exposant) {
    if (exposant == 0) return 1;

    ull resultat = 1;
    /* Boucle simple qui multiplie 'base' par elle-meme 'exposant' fois */
    for (int i = 0; i < exposant; i++) {
        resultat = resultat * base;
    }
    return resultat;
}

/* 3. Fonction Puissance Recursive Optimisee (Exponentiation Binaire) (O(log n)) */
ull puissance_recursif_optimise(int base, int exposant) {
    
    if (exposant == 0) return 1;
    if (exposant == 1) return base;

    /* Appel recursif : on calcule la moitie de la puissance UNE SEULE FOIS */
    ull temp = puissance_recursif_optimise(base, exposant / 2);

    if (exposant % 2 == 0) {
        /* Si pair : (x^(n/2))^2 */
        return temp * temp;
    } else {
        /* Si impair : x * (x^((n-1)/2))^2 */
        /* Note : en C, exposant/2 fait deja la division entiere (n-1)/2 */
        return base * temp * temp;
    }
}

int main() {
    int base, exposant;
    clock_t debut, fin;
    double temps_ecoule;
    ull resultat;

    printf("=== TEST DE PERFORMANCE DES ALGORITHMES DE PUISSANCE ===\n");
    printf("Entrez la base (entier) : ");
    /* (void) permet d'ignorer le retour de scanf sans warning */
    (void)scanf("%d", &base);
    
    printf("Entrez l'exposant (entier positif) : ");
    (void)scanf("%d", &exposant);
    
    printf("\nCalcul de %d^%d :\n", base, exposant);
    printf("------------------------------------------------------\n");

    /* --- Test 1 : Recursif Naif --- */
    debut = clock();
    resultat = puissance_recursif_naif(base, exposant);
    fin = clock();
    temps_ecoule = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("[Recursif Naif]    Resultat: %llu | Temps: %f sec\n", resultat, temps_ecoule);

    /* --- Test 2 : Iteratif Naif --- */
    debut = clock();
    resultat = puissance_iteratif_naif(base, exposant);
    fin = clock();
    temps_ecoule = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("[Iteratif Naif]    Resultat: %llu | Temps: %f sec\n", resultat, temps_ecoule);

    /* --- Test 3 : Recursif Optimise --- */
    debut = clock();
    resultat = puissance_recursif_optimise(base, exposant);
    fin = clock();
    temps_ecoule = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("[Recursif Opti]    Resultat: %llu | Temps: %f sec\n", resultat, temps_ecoule);

    printf("------------------------------------------------------\n");

    return 0;
}