#ifndef ARBREB_H
#define ARBREB_H

#include "Sommet.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class ArbreB : public Sommet
{
	protected :
		Sommet racine;
		ArbreB* droite;
		ArbreB* gauche;
		ArbreB* precedent;
	public :
		ArbreB();
		ArbreB(Sommet& s);
		ArbreB(Sommet& s, ArbreB* A);
		ArbreB(ArbreB* A); //constructeur par copie (non utilisé pour l'instant)
		~ArbreB();

		Sommet& getSommet();
		ArbreB* getDroite();
		ArbreB* getGauche();
		ArbreB* getPrecedent();

		ArbreB& ajouter(Sommet& s); //fait
		ArbreB& supprimer(Sommet& s); //fait
		Sommet& rechercher(Sommet& s); //fait
		ArbreB& modifier(Sommet& s, char c, int f); //fait
		ArbreB& fusionner(ArbreB* A); //fait
		void decomposer(ArbreB* Ag, ArbreB* Ad, ArbreB* A); //fait
		void afficher(ArbreB* A); //fait - (sert pour << ?)

		void print_t(int hauteur, int cote, ArbreB* A); //affichage ameliore

		bool operator ==(ArbreB* A); //sert pour constructeur par copie - (erreur à corriger : retourne toujours faux)
		ArbreB& operator =(ArbreB* A); //fait
		friend ostream& operator<<(ostream& flux, ArbreB& A); //a faire

		//--------------BONUS--------------
		int hauteur(ArbreB* A, int hg, int hd); //calcule la hauteur de l'arbre
		int nombre_element(ArbreB* A); //calcule le nombre d'élément dans l'arbre
		ArbreB* min(ArbreB* A); //retourne l'arbre (feuille) minimal de l'arbre - sert pour supprimer
		ArbreB* max(ArbreB* A); //retourne l'arbre (feuille) maximal de l'arbre - sert pour supprimer
		bool egalite(ArbreB* current, ArbreB* A); //vérifie de manière récursive si deux arbres sont égaux - sert pour l'operateur ==
		ArbreB& affecter(ArbreB* A); // sert pour operateur =
		void copier(ArbreB* A1, ArbreB* A2); //sert pour constructeur copie
		void ajouterGauche(ArbreB* Ag, ArbreB* A); //sert pour decomposer
		void ajouterDroite(ArbreB* Ad, ArbreB* A); //sert pour decomposer

};
#endif