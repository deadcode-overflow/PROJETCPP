#ifndef ARBREB_H
#define ARBREB_H

#include "Sommet.h"

class ArbreB : public Sommet
{
	private :
		Sommet* racine;
		Sommet* parent;
	public :
		ArbreB* droite;
		ArbreB* gauche;

		ArbreB();
		ArbreB(const Sommet& s);
		ArbreB(const Sommet& s, Sommet* &Sparent);
		ArbreB(const Sommet& s, Sommet* &Sparent, ArbreB* Adroite, ArbreB* Agauche);
		~ArbreB();

		Sommet* getSommet();
		Sommet* getParent();

		ArbreB& ajouter(const Sommet& s, Sommet* &parent, ArbreB* A);
		ArbreB& supprimer(const Sommet& s, const ArbreB* A);
		void afficher(const ArbreB* A);
		void supprimerArbre(const ArbreB* A);
};
#endif