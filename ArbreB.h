#ifndef ARBREB_H
#define ARBREB_H

#include "Sommet.h"

class ArbreB : public Sommet
{
	private :
		Sommet* racine;
	public :
		ArbreB* droite;
		ArbreB* gauche;
		ArbreB* parent;

		ArbreB();
		ArbreB(const Sommet& s);
		ArbreB(const Sommet& s, ArbreB* Aparent);
		ArbreB(const Sommet& s, ArbreB* Aparent, ArbreB* Adroite, ArbreB* Agauche);
		~ArbreB();

		Sommet* getSommet();
		ArbreB* getParent();

		ArbreB& ajouter(const Sommet& s, ArbreB* parent, ArbreB* A);
		ArbreB& supprimer(const Sommet& s, const ArbreB* A);
		void afficher(const ArbreB* A);
		void supprimerArbre(const ArbreB* A);
};
#endif