#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#define Valeur 20
using namespace std;

char Source[20];

typedef struct {
    int Nb_Lettre;
    char Lettre;
} Lettre_Compresse;
Lettre_Compresse Compresse[Valeur];
char Decompresse[Valeur];

void Saisir_Caractere() {
    cout << "Veuillez entrer votre texte: ";
    gets(Source);
}

void Compression() {
    int L_index_Compresse = 0;
    int L_index = 0;
    int L_Compteur = 0;
    char L_Caractere = Source[L_index];

    while (L_index <= Valeur-1) {
        if (Source[L_index] == L_Caractere) {
            L_Compteur++;
        } else {
            Compresse[L_index_Compresse].Nb_Lettre = L_Compteur;
            Compresse[L_index_Compresse].Lettre = L_Caractere;
            L_Compteur = 1;
            L_index_Compresse++;
            L_Caractere = Source[L_index];
        }
        L_index++;
    }
    cout << "Compression: ";
    for (int L_index = 0; L_index < L_index_Compresse; L_index++) {
        cout << Compresse[L_index].Nb_Lettre;
        cout << Compresse[L_index].Lettre;
    }
    cout << endl;
}

void Decompression() {
    int L_Index_Decompresse = 0;
    int L_Index = 0;
    int L_compteur;

    do {
        L_compteur = 0;
        do {
            Decompresse[L_Index_Decompresse] = Compresse[L_Index].Lettre;
            L_Index_Decompresse++;
            L_compteur++;
        } while (L_compteur < Compresse[L_Index].Nb_Lettre);
        L_Index++;
    } while (L_Index < Valeur-1);

    cout << "Decompression: " << Decompresse << endl;
}

int main(int argc, char** argv) {

    Saisir_Caractere();
    Compression();
    Decompression();

    return 0;
}

