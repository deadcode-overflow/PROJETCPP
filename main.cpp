#include <iostream>
#include "Sommet.h"
#include "ArbreB.h"

using namespace std;

int main() {

    //--------------test-des-sommets------------------
    cout << endl;
    //test affichage constructeur par valeur
	Sommet s('A', 4);
    cout <<  "s -> " << s << endl;
    //test affichage constructeur par défaut
    Sommet defaut;
    cout << "def -> " << defaut << endl;
    //test affectation
    Sommet s2('B', 1);
    cout << "s2 -> " << s2 << endl;
    defaut = s2;
    cout << "affectation def = s2" << endl;
    cout << "def -> " << defaut << endl;
    //test égalité
    Sommet s3('A', 4);
    cout << "s3 -> " << s3 << endl;
    cout << "comparaison s == s3" << endl;
    if(s == s3)
        cout << "s et s3 sont égaux" << endl;
    else
        cout << "s et s3 ne sont pas égaux" << endl;
    cout << endl;
    //test affichage constructeur par copie
    Sommet copie(s);
    cout << "copie de s" << endl;
    cout << "sommmet 'copie' de 's' -> " << copie << endl;
    //-------------------------------------------------

    //--------------test-de-l'arbre-binaire------------
    //test affichage constructeur par défaut
    ArbreB AbrDefaut;
    cout << "creation de d'un arbre par défaut" << endl;
    AbrDefaut.afficher(&AbrDefaut);
    //test affichage constructeur par valeur
    ArbreB A(s);
    cout << "creation de l'arbre de racine s" << endl;
    A.afficher(&A);
    //test ajout d'un sommet dans l'arbre
    A.ajouter(s2);
    cout << "ajout de s2 dans l'arbre" << endl;
    A.afficher(&A);
    //test ajout de plusieurs sommet dans l'arbre
    Sommet s4('C',1);
    cout << "s4 -> " << s4 << endl;
    Sommet s5('D',2);
    cout << "s5 -> " << s5 << endl;
    Sommet s6('E',3);
    cout << "s6 -> " << s6 << endl;
    Sommet s7('F',2);
    cout << "s7 -> " << s7 << endl;
    A.ajouter(s4);
    A.ajouter(s5);
    A.ajouter(s6);
    A.ajouter(s7);
    cout << "ajout de plusieurs sommets dans l'arbre" << endl;
    A.afficher(&A);
    //test rechecher un sommet dans l'arbre
    Sommet sommetArbre = A.rechercher(s5);
    cout << "recherche du sommet s5 dans l'arbre" << endl;
    cout << " sommet de l'arbre -> " << sommetArbre << endl;
    //test modifier un sommmet dans l'arbre
    A.modifier(s6, 'K', 6);
    cout << "modification du sommet s6 dans l'arbre par 'K' '6'" << endl;
    A.afficher(&A);
    //-------------------------------------------------

    return 0;
}