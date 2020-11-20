#ifndef ARBREB_H
#define ARBREB_H

#include "Sommet.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class ArbreB : public Sommet
{
	private :
		Sommet racine;
		ArbreB* droite;
		ArbreB* gauche;
		ArbreB* precedent;
	public :
		// Constructeurs
		ArbreB();
		ArbreB(Sommet& s);
		ArbreB(Sommet& s, ArbreB* A);
		ArbreB(ArbreB* A); //constructeur par copie
		// Destructeur
		~ArbreB();

		// Getters
		Sommet& getSommet();
		ArbreB* getDroite();
		ArbreB* getGauche();
		ArbreB* getPrecedent();

		// Méthodes
		ArbreB& ajouter(Sommet& s); //fait
		ArbreB& supprimer(Sommet& s); //fait
		Sommet& rechercher(Sommet& s); //fait
		ArbreB& modifier(Sommet& s, char c, int f); //fait
		ArbreB& fusionner(ArbreB* A); //fait
		void decomposer(ArbreB* Ag, ArbreB* Ad, ArbreB* A); //fait
		void afficher(ArbreB* A); //fait - (sert pour << ?)
		void print_t(int hauteur, int cote, ArbreB* A); //affichage ameliore

		//--------------BONUS--------------
		int hauteur(ArbreB* A, int hg, int hd); //calcule la hauteur de l'arbre
		int nombre_element(ArbreB* A); //calcule le nombre d'élément dans l'arbre
		ArbreB* min(ArbreB* A); //retourne l'arbre (feuille) minimal de l'arbre - sert pour supprimer
		ArbreB* max(ArbreB* A); //retourne l'arbre (feuille) maximal de l'arbre - sert pour supprimer
		void copier(ArbreB* A1, ArbreB* A2); //sert pour constructeur copie
		void ajouterGauche(ArbreB* Ag, ArbreB* A); //sert pour decomposer
		void ajouterDroite(ArbreB* Ad, ArbreB* A); //sert pour decomposer

};
#endif