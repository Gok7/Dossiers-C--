#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct T_NOEUD {
    int Data;
    T_NOEUD* Gauche;
    T_NOEUD* Droite;
} T_NOEUD;

T_NOEUD* Racine = NULL;

void Affiche_Noeuds(T_NOEUD* P_Noeud) {

    if (P_Noeud != NULL) {
        cout << P_Noeud->Data << endl;
        Affiche_Noeuds(P_Noeud->Droite);
        Affiche_Noeuds(P_Noeud->Gauche);
    }
}

T_NOEUD* Creation_Feuille(int P_Data) {

    T_NOEUD* L_Noeud = new T_NOEUD;
    L_Noeud->Data = P_Data;
    L_Noeud->Droite = NULL;
    L_Noeud->Gauche = NULL;
    return L_Noeud;
}

void Ajout_Ordonne(T_NOEUD* P_Noeud, int P_Data) {
    if (P_Noeud != NULL) {
        if (P_Data > P_Noeud->Data) {
            if (P_Noeud->Droite == NULL) {//s'il nya pas de feuille dans la branche droite
                P_Noeud->Droite = Creation_Feuille(P_Data);// on créer la feuille
            } else {
                if (P_Noeud->Gauche == NULL) {//s'il nya pas de feuille dans la branche gauche
                    P_Noeud->Gauche = Creation_Feuille(P_Data);//on créer la feuille
                } else {
                    Ajout_Ordonne(P_Noeud->Gauche, P_Data);
                }
            }
        }
    }
}

bool Recherche_Valeur(T_NOEUD* P_Noeud, int P_Data) {
    int L_valeur = 0;
    bool L_Trouve = false;

    if (P_Noeud != NULL) {
        if (P_Data == P_Noeud->Data) {
            L_Trouve = true;
        } else {
            if (P_Data > P_Noeud->Data) {
                L_Trouve = Recherche_Valeur(P_Noeud->Droite, P_Data);
            } else {
                L_Trouve = Recherche_Valeur(P_Noeud->Gauche, P_Data);
            }
        }
    }
    return L_Trouve;
}

void Saisir_valeur() {
    bool recherche = 0;
    int Valeur = 0;
    cout<<"Saisir la Valeur a rechercher : "<<endl;
    fflush(stdin);
    cin>>Valeur;
    recherche = Recherche_Valeur(Racine,Valeur);
    if (recherche) {
        cout << " Valeur trouvee" << endl;
    } else {
        cout << " Valeur non trouvee" << endl;
    }
}

int main(int argc, char** argv) {
   
    Racine = Creation_Feuille(0);
    Ajout_Ordonne(Racine,10);
    Ajout_Ordonne(Racine,40);
    Ajout_Ordonne(Racine,1000);
    Ajout_Ordonne(Racine,20);
    Ajout_Ordonne(Racine, 2310);
    Ajout_Ordonne(Racine, 40);
    Affiche_Noeuds(Racine);

    /*
    Racine->Data = 10;

    Racine->Gauche = new T_NOEUD;
    Racine->Gauche->Data = 5;

    Racine->Droite = new T_NOEUD;
    Racine->Droite->Data = 20;

    Racine->Gauche->Gauche = new T_NOEUD;
    Racine->Gauche->Gauche->Data = 4;
    Racine->Gauche->Gauche->Gauche=NULL;
    Racine->Gauche->Gauche->Droite=NULL;    

    Racine->Gauche->Droite = new T_NOEUD;
    Racine->Gauche->Droite->Data = 6;
    Racine->Gauche->Droite->Droite = NULL;
    Racine->Gauche->Droite->Gauche = NULL;

    Racine->Droite->Droite = new T_NOEUD;
    Racine->Droite->Droite->Data = 23;
    Racine->Droite->Droite->Droite = NULL;
    Racine->Droite->Droite->Gauche = NULL;

    Racine->Droite->Gauche = new T_NOEUD;
    Racine->Droite->Gauche->Data = 15;
    Racine->Droite->Gauche->Droite = NULL;
    Racine->Droite->Gauche->Gauche = NULL;
    */
    return 0;
}


//pour vendredi travailler sur l'ajout à la fin, si la liste existe, on cherche 
//le dernier maillon. si la liste existe pas, on utilise la fonction ajoute au début
//-Essayer de reecrire le parcours de la liste de façon récursive
//Travailler sur l'ajout d'un Element en plein milieu suivant un critère, par ex
//par ordre croissant.

//petit controle vendredi 14 dec.. réviser compression,tri a bulle, quicksort heapsort, expliquer huffman,
//arithmetique, cryptage ,mealy , coder une césar, liste chainée simple
//gros controle a la rentrée

//faire le truc sur le cahier pour la prochaine fois



