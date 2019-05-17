#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct T_MAILLON {
    int Data;
    T_MAILLON* Suivant;
} T_MAILLON;

T_MAILLON* Debut_Liste = NULL;
T_MAILLON* Fin_Liste = NULL;
int les_valeurs[100];   

void Ajoute_Fin(int P_valeur);

void Remplir_tableau(){
    int L_compteur=0;
    T_MAILLON* L_Maillon_Courant;
    L_Maillon_Courant = Debut_Liste;
    
    for (L_compteur = 0; L_compteur < 100; L_compteur++) {//initialisation
        les_valeurs[L_compteur] = 0;
    }
    
    for(L_compteur=0;L_Maillon_Courant != NULL && L_compteur<100;L_compteur++) {//remplir
        les_valeurs[L_compteur] = L_Maillon_Courant->Data;
        L_Maillon_Courant = L_Maillon_Courant->Suivant;
    }
    cout << "Tableau les valeurs" << endl;

    for (L_compteur = 0; L_compteur < 100; L_compteur++) {//affichage
        cout << "Case " << L_compteur << " : " << les_valeurs[L_compteur] << endl;
    }
}

void Ajoute_Au_Debut(int P_Valeur) {

    T_MAILLON* L_Maillon = new T_MAILLON; //1 creation nouveau maillon
    if (Debut_Liste == NULL) {
        Fin_Liste = L_Maillon;
    }
    L_Maillon->Suivant = Debut_Liste; //2 chainer nouveau maillon avec le premier
    Debut_Liste = L_Maillon; //3 dire que le nouveau maillon est le premier
    L_Maillon->Data = P_Valeur; //4 initialiser le Data 
}

void tableau_to_list() {
    int compteur = 0;
    T_MAILLON* L_Maillon_nouveau;
    L_Maillon_nouveau = Debut_Liste;
    int tempo=0;
    for (compteur = 0; compteur < 100; compteur++) {//initialisation
        les_valeurs[compteur] = 1 ;
    }
    for (compteur = 0; compteur < 100; compteur++) {//remplir
        tempo=les_valeurs[compteur];
        Ajoute_Fin(tempo);
    }
}

void Affiche_Liste() {
    T_MAILLON* L_Maillon_Courant;
    L_Maillon_Courant = Debut_Liste;

    while (L_Maillon_Courant != NULL) {
        cout << L_Maillon_Courant->Data << " ";
        L_Maillon_Courant = L_Maillon_Courant->Suivant;
    }
    cout << "Fin liste" << endl;
}

int Compte_Nombre_Maillons() {
    T_MAILLON* L_Maillon_Courant;
    L_Maillon_Courant = Debut_Liste;
    int Compteur = 0;

    while (L_Maillon_Courant != NULL) {
        L_Maillon_Courant = L_Maillon_Courant->Suivant;
        Compteur++;
    }
    cout << "Il y a " << Compteur << " Maillons" << endl;
    return Compteur;
}

void Supprimer_Liste() {
    T_MAILLON* L_Maillon_Suivant;

    while (Debut_Liste != NULL) {
        L_Maillon_Suivant = Debut_Liste->Suivant;
        delete Debut_Liste;
        Debut_Liste = L_Maillon_Suivant;
    }
}

void Ajoute_Fin(int P_Valeur) {
    if(Debut_Liste==NULL){
        Ajoute_Au_Debut(P_Valeur);
    }
    else{
        T_MAILLON* L_Nouveau= new T_MAILLON;
        Fin_Liste->Suivant=L_Nouveau;
        L_Nouveau->Suivant=NULL;
        L_Nouveau->Data=P_Valeur;
        Fin_Liste=L_Nouveau;
    }
}

int main(int argc, char** argv) {

    /*Ajoute_Au_Debut(10);
    Ajoute_Au_Debut(20);
    Ajoute_Au_Debut(30);
    
    Ajoute_Fin(40);*/
    tableau_to_list();
    Remplir_tableau();
    Affiche_Liste();
    Compte_Nombre_Maillons();
    
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



