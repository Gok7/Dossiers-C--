#include <cstdlib> // fait le dimanche 9 dec 2012
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char mot_secret[30];
int masque[30];

void Saisir_mot() {
    system("CLS");
    cout << "Veuillez saisir le mot secret : ";
    fflush(stdin);
    fgets(mot_secret, 29, stdin);
    system("CLS");
}

void Initialiser() {
    for (int i = 0; i < 29; i++) {
        mot_secret[i] = '\0';
        masque[i] = 0;
    }
}

void Saisir_lettre() {

    int chance = 11;
    char lettre[3];
    int taille_du_secret = strlen(mot_secret) - 1;
    bool ok = 0;
    int compteur_de_lettre_bonne = 0;
    int i = 0;
    while (ok != 1 && chance > 0) {
        if (compteur_de_lettre_bonne == taille_du_secret) {
            ok = 1;
        } else {
            cout << endl << chance-1 << " chances " << endl;
            cout << " : ";
            fflush(stdin);
            fgets(lettre, 2, stdin);
            for (i = 0; i < taille_du_secret; i++) {//cherche
                if (mot_secret[i] == lettre[0] && masque[i] == 0) {
                    masque[i] = 1;
                    compteur_de_lettre_bonne++;
                }
            }
            chance--;
            for (i = 0; i < taille_du_secret; i++) {//affiche
                if (masque[i] == 1) {
                    cout << mot_secret[i];
                } else {
                    cout << "_";
                }
            }
        }
    }
    if (chance == 0) {
        cout <<endl<< "Solution : " << mot_secret << endl;
        cout << endl << "********************GAME OVER********************" << endl;
    } else {
        cout << endl << " ~~~~~~~~~~~~~~~~~~~BRAVO !~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

int main(int argc, char** argv) {
    char rejouer = 'n';
    do {
        Initialiser();
        Saisir_mot();
        Saisir_lettre();
        cout << "Rejouer ? (y/n)" << endl;
        fflush(stdin);
        rejouer = fgetc(stdin);
    } while (rejouer == 'y');

    return 0;
}