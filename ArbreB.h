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
		//ArbreB(ArbreB& A); //constructeur par copie (non utilisé pour l'instant)
		~ArbreB();

		ArbreB& ajouter(Sommet& s); //operateur +  (A + s) - fait
		ArbreB& supprimer(Sommet& s); //operateur - (A - s) - a faire
		Sommet& rechercher(Sommet& s); //fait
		ArbreB& modifier(Sommet& s, char c, int f); //fait
		ArbreB& fusionner(ArbreB& A); //operateur + (A + A) - a faire
		ArbreB& decomposer(); // A -> Ad + Ag - a faire
		void afficher(ArbreB* A); //operateur << - fait

		Sommet& getSommet();
		ArbreB* getDroite();
		ArbreB* getGauche();
		ArbreB* getPrecedent();

		//friend ostream& operator<<(ostream& flux, ArbreB& A); // cout << A
		//void supprimerArbre(ArbreB* A); //inutile pour l'instant
};
#endif