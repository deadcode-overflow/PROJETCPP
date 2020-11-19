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
	if(droite) {
		delete droite;
	}
	if (gauche)
	{
		delete gauche;
	}
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

ArbreB* ArbreB::min(ArbreB* A) {
	ArbreB* tmp = A;
	ArbreB* min = nullptr;

	while(A) {
		min = A;
		A = A->gauche;
	}

	return min;
}

ArbreB* ArbreB::max(ArbreB* A) {
	ArbreB* tmp = A;
	ArbreB* max = nullptr;

	while(A) {
		max = A;
		A = A->droite;
	}

	return max;
}

ArbreB& ArbreB::supprimer(Sommet& s) {
	cout << "dans le supprimer sommet" << endl;

	if(racine.getChar() == 0) {
		cout << "suppression impossible l'arbre est vide" << endl;
		return *this;
	}

	ArbreB* tmp = this;

	//recherche du sommet dans l'arbre
	while(tmp) {
		if(s == tmp->racine) {
			break;
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

	//si le sommet à supprimmer n'existe pas dans l'arbre
	if(tmp == nullptr) {
		cout << "l'element à supprimer n'existe pas" << endl;
		return *this;
	}

	//si le sommet à supprimmer se trouve à gauche
	if(tmp->racine < tmp->precedent->racine) {
		//si le sommet à supprimmer est une feuille
		if(tmp->gauche == nullptr && tmp->droite == nullptr) {
			tmp->precedent->gauche = nullptr;

			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;
			
			delete tmp;
			
			return *this;
		}//si le sommet à supprimmer a 1 fils à gauche
		if(tmp->gauche != nullptr && tmp->droite == nullptr) {
			tmp->precedent->gauche = tmp->gauche;
			tmp->gauche->precedent = tmp->precedent;

			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;
			
			delete tmp;
			
			return *this;
		}//si le sommet à supprimmer a 1 fils à droite
		if(tmp->gauche == nullptr && tmp->droite != nullptr) {
			tmp->precedent->gauche = tmp->droite;
			tmp->droite->precedent = tmp->precedent;

			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;
			
			delete tmp;
			
			return *this;
		}//si le sommet à supprimer a 2 fils
		if(tmp->gauche != nullptr && tmp->droite != nullptr) {
			ArbreB* Abr_max = max(tmp->gauche);
			
			tmp->precedent->gauche = Abr_max;
			
			if(Abr_max->gauche) {
				Abr_max->precedent->droite = Abr_max->gauche;
				Abr_max->gauche->precedent = Abr_max->precedent;
			}
			else {
				Abr_max->precedent->droite = nullptr;
			}
			Abr_max->precedent = tmp->precedent;

			
			tmp->droite->precedent = Abr_max;
			tmp->gauche->precedent = Abr_max;
			
			Abr_max->droite = tmp->droite;
			Abr_max->gauche = tmp->gauche;

			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;
			
			delete tmp;
			
			return *this;
		}
	}
	else {	//si le sommet à supprimer se trouve à droite
		//si le sommet à supprimer est une feuille
		if(tmp->gauche == nullptr && tmp->droite == nullptr) {
			tmp->precedent->droite = nullptr;
			
			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;

			delete tmp;
			
			return *this;
		}//si le sommet à supprimer a 1 fils à gauche
		if(tmp->gauche != nullptr && tmp->droite == nullptr) {
			tmp->precedent->droite = tmp->gauche;
			tmp->gauche->precedent = tmp->precedent;
			
			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;

			delete tmp;
			
			return *this;
		}//si le sommet à supprimer a 1 fils à droite
		if(tmp->gauche == nullptr && tmp->droite != nullptr) {
			tmp->precedent->droite = tmp->droite;
			tmp->droite->precedent = tmp->precedent;
			
			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;

			delete tmp;
			
			return *this;
		}//si le sommet à supprimer a 2 fils
		if(tmp->gauche != nullptr && tmp->droite != nullptr) {
			ArbreB* Abr_max = max(tmp->droite);
			
			tmp->precedent->droite = Abr_max;
			
			if(Abr_max->gauche) {
				Abr_max->precedent->droite = Abr_max->gauche;
				Abr_max->gauche = Abr_max->precedent;
			}
			else {
				Abr_max->precedent->droite = nullptr;
			}
			Abr_max->precedent = tmp->precedent;
			
			tmp->droite->precedent = Abr_max;
			tmp->gauche->precedent = Abr_max;
			
			Abr_max->droite = tmp->droite;
			Abr_max->gauche = tmp->gauche;
			
			tmp->precedent = nullptr;
			tmp->droite = nullptr;
			tmp->gauche = nullptr;

			delete tmp;
			
			return *this;
		}
	}

	return *this;
}

Sommet& ArbreB::rechercher(Sommet& s) {
	cout << "dans le rechercher sommet" << endl;

	ArbreB* tmp = this;

	while(tmp) {
		if(s == tmp->racine) {
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

	cout << "le sommet n'existe pas dans l'arbre" << endl;

	return s;
}

ArbreB& ArbreB::modifier(Sommet& s, char c, int f) {
	cout << "dans le modifier sommet" << endl;

	ArbreB* tmp = this;

	while(tmp) {
		if(s == tmp->racine) {
			tmp->racine.setChar(c);
			tmp->racine.setFreq(f);
			return *this;
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

	cout << "le sommet n'existe pas dans l'arbre" << endl;

	return *this;
}


ArbreB& ArbreB::fusionner(ArbreB* A) {

	if(!A || racine.getChar() == 0 || A->racine.getChar() == 0) {
		return *this;
	}

	ajouter(A->racine);

	fusionner(A->gauche);
	fusionner(A->droite);

	return *this;
}

/*
ArbreB& ArbreB::decomposer() {
	return *this;
}
*/


void ArbreB::print_t(int hauteur, int cote, ArbreB* A) {
    if (A == nullptr)  {
    	return;
    }
    else {
    	int i;
        for (i = 1; i < hauteur; i++) {
        	cout << "│ ";
        }
        if (hauteur)    {
            if (cote == 0) {
                cout << "├─ " << A->getSommet().getChar() << endl;
            }
            else {
                cout << "└─ " << A->getSommet().getChar() << endl;
            }
        }
        else {
            cout << A->getSommet().getChar() << endl;
        }
    }

    print_t (hauteur + 1, 0, A->getGauche());
    print_t (hauteur + 1, 1, A->getDroite());
}

// affichage infixe (gauche->racine->droite)
void ArbreB::afficher(ArbreB* A) {

	if(A == nullptr) return;

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

bool ArbreB::egalite(ArbreB* current, ArbreB* A) {

	if(current == nullptr || A == nullptr) return false;

	if(current->racine == A->racine) {
		egalite(current->gauche, A->gauche);
		egalite(current->droite, A->droite);
		return true;
	}
	
	return false;
}

bool ArbreB::operator ==(ArbreB* A) {

	ArbreB* tmp = this;

	bool res = egalite(tmp, A);

	return res;
}

/*
ostream& operator<<(ostream& flux, ArbreB* A) {
	return flux;
}
*/

int ArbreB::hauteur(ArbreB* A, int hg, int hd) {

	if(racine.getChar() == 0 || A == nullptr) {
		return 0;
	}

	hg = hauteur(A->gauche, hg, hd);
	hd = hauteur(A->droite, hg, hd);

	if(hg > hd) {
		return 1 + hg;
	}
	else {
		return 1 + hd;
	}

	cout << "erreur dans la hauteur de l'arbre" << endl;

	return -1;
}

int ArbreB::nombre_element(ArbreB* A) {

	if(racine.getChar() == 0 || A == nullptr) {
		return 0;
	}

	return 1 + nombre_element(A->gauche) + nombre_element(A->droite);
}