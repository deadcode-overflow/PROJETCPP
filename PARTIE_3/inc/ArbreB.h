#ifndef ARBREB_H
#define ARBREB_H

#include "../inc/Sommet.h"

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
		ArbreB(ArbreB* A);
		// Destructeur
		~ArbreB();

		// Getters
		Sommet& getSommet();
		ArbreB* getDroite();
		ArbreB* getGauche();
		ArbreB* getPrecedent();
		ArbreB& setFreq(ArbreB* A1, ArbreB* A2);

		// Méthodes
		ArbreB& ajouter(Sommet& s);
		ArbreB& supprimer(Sommet& s);
		Sommet rechercher(Sommet& s);
		ArbreB& modifier(Sommet& s, char c, int f);
		ArbreB& fusionner(ArbreB* A);
		ArbreB& fusionner_huffman(ArbreB* A1, ArbreB* A2);
		void decomposer(ArbreB* Ag, ArbreB* Ad, ArbreB* A);
		void affichage_infixe(ArbreB* A);
		void afficher_arbo(int hauteur, int cote, ArbreB* A);

		//---------------------------------
		int hauteur(ArbreB* A, int hg, int hd);
		int nombre_element(ArbreB* A);
		ArbreB* min(ArbreB* A);
		ArbreB* max(ArbreB* A);
		void copier(ArbreB* destination, ArbreB* source, Sommet& racine_destination);
		void recupererGauche(ArbreB* Ag, ArbreB* A);
		void recupererDroite(ArbreB* Ad, ArbreB* A);
};
#endif