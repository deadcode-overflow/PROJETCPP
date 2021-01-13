#include "../inc/test.h"
#include "../inc/Sommet.h"
#include "../inc/ArbreB.h"

#include <iostream>

using namespace std;

int test() {

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
    A.print_t(0,0,&A);
    
    //test rechecher un sommet dans l'arbre
    Sommet sommetArbre = A.rechercher(s5);
    cout << "recherche du sommet s5 dans l'arbre" << endl;
    cout << "sommet de l'arbre -> " << sommetArbre << endl;
    
    //test modifier un sommmet dans l'arbre
    A.modifier(s6, 'K', 6);
    cout << "modification du sommet s6 dans l'arbre par 'K' '6'" << endl;
    cout << "s6 -> " << s6 << endl;
    A.afficher(&A);
    
    //test hauteur de l'arbre
    cout << "hauteur de l'arbre A : " << A.hauteur(&A,0,0) << endl;;
    
    //test nombre d'élément dans l'arbre
    cout << "nombre d'element dans l'arbre A : " << A.nombre_element(&A) << endl;
    cout << endl;
    
    //test de suppression d'un sommet dans l'arbre
    A.supprimer(s5);
    cout << "s5 -> " << s5;
    cout << "suppression du sommet s5 dans l'arbre A" << endl;
    A.afficher(&A);
    
    //test affichage arbre amélioré
    Sommet s8('G', 1);
    cout <<  "s8 -> " << s8 << endl;
    Sommet s9('H', 2);
    cout <<  "s9 -> " << s9 << endl;
    Sommet s10('I', 3);
    cout <<  "s10 -> " << s10 << endl;
    Sommet s11('J', 2);
    cout <<  "s11 -> " << s11 << endl;
    Sommet s12('K', 6);
    cout <<  "s12 -> " << s12 << endl;
    Sommet s13('L', 4);
    cout <<  "s13 -> " << s13 << endl;
    Sommet s14('M', 3);
    cout <<  "s14 -> " << s14 << endl;
    Sommet s15('O', 3);
    cout <<  "s15 -> " << s15 << endl;
    Sommet s16('P', 3);
    cout <<  "s16 -> " << s16 << endl;
    Sommet s17('Q', 2);
    cout <<  "s17 -> " << s17 << endl;
    Sommet s18('R', 4);
    cout <<  "s18 -> " << s18 << endl;
    Sommet s20('T', 3);
    cout <<  "s20 -> " << s20 << endl;
    Sommet s21('U', 2);
    cout <<  "s21 -> " << s21 << endl;
    Sommet s22('V', 1);
    cout <<  "s22 -> " << s22 << endl;
    Sommet s23('W', 1);
    cout <<  "s23 -> " << s23 << endl;
    Sommet s24('X', 1);
    cout <<  "s24 -> " << s24 << endl;
    Sommet s25('Y', 1);
    cout <<  "s25 -> " << s25 << endl;
    Sommet s26('Z', 1);
    cout <<  "s26 -> " << s26 << endl;
    Sommet s19('N', 3);
    cout <<  "s19 -> " << s19 << endl;
    Sommet s27('S', 3);
    cout << "s27 -> " << s27 << endl; 
    
    ArbreB N(s14);
    N.ajouter(s20);
    N.ajouter(s9);
    N.ajouter(s22);
    N.ajouter(s10);
    N.ajouter(s12);
    N.ajouter(s13);
    N.ajouter(s15);
    N.ajouter(s24);
    N.ajouter(s25);
    N.ajouter(s26);
    N.ajouter(s8);
    N.ajouter(s17);
    N.print_t(0,0,&N);
    
    //test constructeur arbre copie
    ArbreB N_copie(&N);
    cout << "arbre N_copie " << endl;
    N_copie.print_t(0,0,&N_copie);
    N.print_t(0,0,&N);

    //test fusionner deux arbres binaires
    A.ajouter(s23);
	A.ajouter(s11);
    A.ajouter(s18);
    A.ajouter(s21);
    A.ajouter(s5);
    A.ajouter(s19);
    A.ajouter(s16);
    A.ajouter(s27);
    A.modifier(s12, 'E', 3);

    cout << "Arbre A" << endl;
    cout << endl;
    A.print_t(0,0,&A);

    cout << "Arbre N avant fusion" << endl;
    cout << endl;
    N.print_t(0,0,&N);

    N.fusionner(&A);

    cout << "Arbre N après fusion" << endl;
    cout << endl;
    N.print_t(0,0,&N);

    //test decomposition
    ArbreB AbrDroit, AbrGauche;
    N.decomposer(&AbrGauche, &AbrDroit, &N);
   
    cout << "AbrGauche de N fusion" << endl;
    cout << AbrGauche.getSommet();
    AbrGauche.print_t(0,0,&AbrGauche);
    
    cout << "AbrDroit de N fusion" << endl;
    cout << AbrDroit.getSommet();
    AbrDroit.print_t(0,0,&AbrDroit);
    //-------------------------------------------------
    return 0;
}