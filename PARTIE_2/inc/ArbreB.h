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
		Sommet& rechercher(Sommet& s);
		ArbreB& modifier(Sommet& s, char c, int f);
		ArbreB& fusionner(ArbreB* A);
		void decomposer(ArbreB* Ag, ArbreB* Ad, ArbreB* A);
		void afficher(ArbreB* A); //affichage infixe
		void print_t(int hauteur, int cote, ArbreB* A); //affichage arborescent

		//---------------------------------
		int hauteur(ArbreB* A, int hg, int hd); //calcule la hauteur de l'arbre
		int nombre_element(ArbreB* A); //calcule le nombre d'élément dans l'arbre
		ArbreB* min(ArbreB* A); //retourne l'arbre (feuille) minimal de l'arbre
		ArbreB* max(ArbreB* A); //retourne l'arbre (feuille) maximal de l'arbre
		void copier(ArbreB* A1, ArbreB* A2); //sert pour constructeur copie
		void recupererGauche(ArbreB* Ag, ArbreB* A); //recupere le sous-arbre gauche d'un arbre binaire
		void recupererDroite(ArbreB* Ad, ArbreB* A); //recupere le sous-arbre droit d'un arbre binaire
		void ajouterGauche(ArbreB* Ag, ArbreB* A);
		void ajouterDroite(ArbreB* Ad, ArbreB* A);
};
#endif