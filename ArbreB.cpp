#include "ArbreB.h"
#include "Sommet.h"
#include <iostream>

using namespace std;

ArbreB::ArbreB() : racine(), precedent(0), droite(0), gauche(0) {
	cout << "dans le constructeur arbre par defaut" << endl;
}

ArbreB::ArbreB(Sommet& s) : racine(s), precedent(this), droite(0), gauche(0) {
	cout << "dans le constructeur arbre(sommet)" << endl;
}

ArbreB::ArbreB(Sommet& s, ArbreB* A) : racine(s), precedent(A), droite(0), gauche(0) {
	cout << "dans le constructeur arbre(sommet, precedent)" << endl;
}

/*ArbreB::ArbreB(ArbreB& A) {
	cout << "dans le constructeur arbre par copie" << endl;
}*/

ArbreB::~ArbreB() {
	cout << "destructeur ArbreB" << endl;
}

Sommet& ArbreB::getSommet() {
	return racine;
}

ArbreB* ArbreB::getDroite() {
	return droite;
}

ArbreB* ArbreB::getGauche() {
	return gauche;
}

ArbreB* ArbreB::getPrecedent() {
	return precedent;
}

ArbreB& ArbreB::ajouter(Sommet& s) {
	cout << "dans le ajouter sommet" << endl;
	if(racine.getChar() == 0) {
		racine = s;
		droite = nullptr;
		gauche = nullptr;
		precedent = nullptr;

		return *this;
	}

	ArbreB* tmp = this;
	ArbreB* prec = nullptr;

	while(tmp) {
		prec = tmp;

		if(s < tmp->racine) {
			tmp = tmp->gauche;
			cout << "--- deplacement à gauche ---" << endl; 
		}
		else {
			tmp = tmp->droite;
			cout << "--- déplacement à droite ---" << endl;
		}
	}

	if(s < prec->racine) {
		prec->gauche = new ArbreB(s, prec);
		cout << "--- creation -- gauche ---" << endl;
	}
	else {
		prec->droite = new ArbreB(s, prec);
		cout << "--- creation -- droite ---" << endl;
	}

	return *this;
}


ArbreB& ArbreB::supprimer(Sommet& s) {
	cout << "dans le supprimer sommet" << endl;

	return *this;
}

Sommet& ArbreB::rechercher(Sommet& s) {

	ArbreB* tmp = this;

	while(tmp) {
		if( s == tmp->racine) {
			return s;
		}
		else {
			if(s < tmp->racine) {
				tmp = tmp->gauche;
			}
			else {
				tmp = tmp->droite;
			}
		}
	}

	cout << "le sommet n'est pas dans l'arbre" << endl;
	
	s.setChar('\0');
	s.setFreq(0);

	return s;
}

ArbreB& ArbreB::modifier(Sommet& s) {
	return *this;
}

ArbreB& ArbreB::fusionner(ArbreB& A) {
	return *this;
}

ArbreB& ArbreB::decomposer() {
	return *this;
}

// affichage infixe (gauche->racine->droite)
void ArbreB::afficher(ArbreB* A) {

	if(racine.getChar() == 0) {
		cout << "l'arbre est vide" << endl;
		return;
	}

	if(A) {
		afficher(A->gauche);
		cout << A->racine;
		afficher(A->droite);
	}

	cout << endl;
}

/*ostream& operator<<(ostream& flux, ArbreB* A) {
	return flux;
}*/

/*void ArbreB::supprimerArbre(ArbreB* A) {
	cout << "dans le supprimer arbre" << endl;

	if(A->droite != nullptr) {
		supprimerArbre(A->droite);
	}

	if(A->gauche != nullptr) {
		supprimerArbre(A->gauche);
	}

	delete A;
}*/