#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char mot[30]="";

void Saisir_mot() {
    cout << "Veuillez saisir le mot secret : ";
    fflush(stdin);
    fgets(mot, 29, stdin);
    system("CLS");
}
void Initialiser(){
    for(int i=0;i<29;i++){
        mot[i]='\0';
    }
}
void Saisir_lettre() {
    char lettre[3];
    int taille = strlen(mot) - 1;
    bool ok = 0;
    int compteur = 0;
    int chance = 10;
    while (ok != 1 && chance > 0) {
        if (compteur == taille) {
            ok = 1;
        } else {
            cout << chance << " chances ";
            cout << "Lettre " << compteur + 1 <<" : ";
            fflush(stdin);
            fgets(lettre, 2, stdin);
           
            if (lettre[0] == mot[compteur]) {
                cout << "Bon";
                compteur++;
            } else {
                cout << "Mauvais";
                chance--;
            }
            cout<<endl;
        }
    }
    if (chance == 0) {
        cout<<"Solution : "<<mot<<endl;
        cout <<endl<< "********************GAME OVER********************" << endl;
    } else {
        cout <<endl<< " ~~~~~~~~~~~~~~~~~~~BRAVO !~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

int main(int argc, char** argv) {
    char rejouer='n';
    do{
        Initialiser();
        Saisir_mot();
        Saisir_lettre();
        cout<<"Rejouer ? (y/n)"<<endl;
        fflush(stdin);
        rejouer=fgetc(stdin);
    }while(rejouer == 'y');
    
    return 0;
}