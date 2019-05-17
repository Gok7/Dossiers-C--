#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <math.h>
#define Valeur_Max 100
using namespace std;

char texte_source[Valeur_Max];
char texte_crypte[Valeur_Max];
char texte_decrypte[Valeur_Max];
int longueur_texte_source =0;

int Saisi() {
    int L_cle = 0;
    cout << "Veuillez saisir le texte a crypter" << endl;
    fgets(texte_source, Valeur_Max, stdin);
    cout << "Veuillez saisir la cle : " << endl;
    cin >> L_cle;
    longueur_texte_source = strlen(texte_source);
    return L_cle;
}

void Initialisation() {
    int compteur = 0;
    for (compteur = 0; compteur < longueur_texte_source; compteur++) {
        texte_crypte[compteur] = '\0';
    }
    for (compteur = 0; compteur < longueur_texte_source; compteur++) {
        texte_decrypte[compteur] = '\0';
    }
}

void Cryptage(int P_cle) {
    for (int compteur = 0; compteur < longueur_texte_source; compteur++) {
        if(texte_source[compteur]!=' '){
            texte_crypte[compteur] = texte_source[compteur] + P_cle;
        }
    }
}

void Decryptage() {
    int L_cle=0;
    cout<<"Veuillez saisir la cle pour decrypter : ";
    cin>>L_cle;
    for (int compteur = 0; compteur < longueur_texte_source; compteur++) {
       if(texte_crypte[compteur]!=' '){
           texte_decrypte[compteur] = texte_crypte[compteur] - L_cle;       
       }   
    }
}

void Affiche() {
    cout << "Texte Cryptee : ";
    for (int compteur = 0; compteur < longueur_texte_source-1; compteur++) {
        cout << texte_crypte[compteur];
    }
    cout << endl;
    cout << "Texte Decryptee : ";
    for (int compteur = 0; compteur < longueur_texte_source; compteur++) {
        cout << texte_decrypte[compteur];
    }
    cout << endl;
}


int main(int argc, char** argv) {
    int Cle=0;
    Cle=Saisi();
    Initialisation();
    Cryptage(Cle);
    Decryptage();
    Affiche();
    return 0;
}

