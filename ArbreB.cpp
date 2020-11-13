#include "ArbreB.h"
#include "Sommet.h"
#include <iostream>

using namespace std;

ArbreB::ArbreB() {
	cout << "dans le constructeur arbre par defaut" << endl;
	parent = nullptr;
	racine = nullptr;
	droite = nullptr;
	gauche = nullptr;
}

ArbreB::ArbreB(const Sommet& s) {
	cout << "dans le constructeur arbre(sommet)" << endl;
	parent = nullptr;
	racine = new Sommet(s);
	droite = nullptr;
	gauche = nullptr;
}

ArbreB::ArbreB(const Sommet& s, Sommet* &Sparent) {
	cout << "dans le constructeur arbre(sommet, parent)" << endl;
	parent = new Sommet(Sparent);
	racine = new Sommet(s);
	droite = nullptr;
	gauche = nullptr;
}

ArbreB::ArbreB(const Sommet& s, Sommet* &Sparent, ArbreB* Adroite, ArbreB* Agauche) {
	cout << "dans le constructeur arbre(sommet, droite, gauche, parent)" << endl;
	parent = new Sommet(Sparent);
	racine = new Sommet(s);
	droite = Adroite;
	gauche = Agauche;
}

ArbreB::~ArbreB() {
	cout << "destructeur ArbreB" << endl;
}

Sommet* ArbreB::getSommet() {
	return racine;
}

Sommet* ArbreB::getParent() {
	return parent;
}

ArbreB& ArbreB::ajouter(const Sommet& s, Sommet* &parent, ArbreB* A) {

	if(racine == nullptr) {
		ArbreB* arbre = new ArbreB(s);
		return *this;
	}
	else {
	
		if(A->droite == nullptr) {
			cout << "création droite" << endl;
			if (A->parent != nullptr) {
				A->droite = new ArbreB(s, A->parent);
				return *this;
			}
			else {
				A->droite = new ArbreB(s, racine);
				return *this;
			}
		}
		
		if(A->gauche == nullptr) {
			cout << "création gauche" << endl;
			if(A->parent != nullptr) {
				A->gauche = new ArbreB(s, A->parent);
				return *this;
			}
			else {
				A->gauche = new ArbreB(s, racine);
				return *this;
			}
			
		}
		
		if(A->droite != nullptr) {
			ajouter(s, A->racine, A->droite);
		}
		if(A->gauche != nullptr){
			ajouter(s, A->racine, A->gauche);
		}
	}

	return *this;
}

ArbreB& ArbreB::supprimer(const Sommet& s, const ArbreB* A) {
	cout << "dans le supprimer sommet" << endl;
/*	
	Sommet* p, fd, fg;

	if(racine == s) {
		delete s;
	}
	supprimer(s, A->droite);
	supprimer(s, A->gauche);
*/
	return *this;
}

void ArbreB::afficher(const ArbreB* A) {

	if(racine == nullptr) {
		cout << "l'arbre est vide" << endl;
		return;
	}
	if(A->parent != nullptr) { 
		cout << "(" << A->parent->getChar() << ") -> (" << A->racine->getChar() << ")" << endl;
	}
	else {
		cout << "(" << racine->getChar() << ")" << endl;
	}

	if(A->droite != nullptr) {
		afficher(A->droite);
	}
	
	if(A->gauche != nullptr) {
		afficher(A->gauche);
	}
}

void ArbreB::supprimerArbre(const ArbreB* A) {
	cout << "dans le supprimer arbre" << endl;

	if(A->droite != nullptr) {
		supprimerArbre(A->droite);
	}

	if(A->gauche != nullptr) {
		supprimerArbre(A->gauche);
	}

	delete A->racine;
}