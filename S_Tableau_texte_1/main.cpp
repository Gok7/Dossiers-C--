#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <math.h>
#define Valeur 10

using namespace std;

typedef struct {
    char lettre;
    int poids;
} T_ELEMENTS;

T_ELEMENTS les_codes[Valeur];
char texte[]="ABACABA";
int longueur_texte=strlen(texte);

void Initialisation() {
    for (int compteur = 0; compteur < Valeur; compteur++) {
        les_codes[compteur].poids = compteur + 1;
        les_codes[compteur].lettre= 'a' + compteur;
    }
}

int Donne_poids(char P_lettre) {
    int L_poids;
    int fin = 0;
    int L_compteur = 0;
    while (fin != 0 || L_compteur < Valeur) {
        if (les_codes[L_compteur].lettre == P_lettre) {
            fin = 1;
            L_poids = les_codes[L_compteur].lettre;
        }
        L_compteur++;
    }
    return L_poids;
}

void Calcul_poids_texte() {
    int L_somme = 0;
    for (int L_compteur = 0; L_compteur < longueur_texte; L_compteur++) {
        L_somme += Donne_poids(texte[L_compteur]);
    }
    cout << "poids total:" << L_somme << endl;
}

void Affiche() {
    for (int L_compteur = 0; L_compteur < Valeur; L_compteur++) {
        cout << les_codes[L_compteur].poids << endl;
    }
}

int main(int argc, char** argv) {
    Initialisation();
    Calcul_poids_texte();
    Affiche();
    return 0;
}

