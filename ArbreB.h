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

		ArbreB& ajouter(Sommet& s); //operateur +  (A + s)
		ArbreB& supprimer(Sommet& s); //operateur - (A - s)
		ArbreB& fusionner(ArbreB& A); //operateur + (A + A)
		ArbreB& decomposer();

		Sommet& getSommet();
		ArbreB* getDroite();
		ArbreB* getGauche();
		ArbreB* getPrecedent();

		void afficher(ArbreB* A); //operateur <<
		//friend ostream& operator<<(ostream& flux, ArbreB& A); // cout << A
		//void supprimerArbre(ArbreB* A); //inutile pour l'instant
};
#endif