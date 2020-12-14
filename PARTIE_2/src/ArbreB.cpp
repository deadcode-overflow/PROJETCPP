#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"

#include <iostream>

using namespace std;

/**
 * usage : constructeur par defaut
 * 
 * description :
 * 		initialise la @racine de l'objet courant avec le constructeur par defaut de l'objet de type Sommet
 *		initialise @precedant, @droite et @gauche à null.
*/
ArbreB::ArbreB() : racine(), droite(0), gauche(0), precedent(0) {}

/**
 * usage : constructeur par référence
 * entrée : une référence @s d'un objet de type Sommet
 *
 * description :
 * 		initialise la @racine de l'objet courant avec le constructeur par référence de l'objet de type Sommet, prenant en paramètre @s
 *		initialise @precedant avec l'objet courant
 * 		initialise @droite et @gauche à null.
*/
ArbreB::ArbreB(Sommet& s) : racine(s), droite(0), gauche(0), precedent(this) {}

/**
 * usage : constructeur par référence
 * entrée : une référence @s d'un objet de type Sommet et un pointeur @A sur un objet de type ArbreB
 *
 * description :
 * 		initialise la @racine de l'objet courant avec le constructeur par référence de l'objet de type Sommet, prenant en paramètre @s
 *		initialise @precedant avec @A
 * 		initialise @droite et @gauche à null.
*/
ArbreB::ArbreB(Sommet& s, ArbreB* A) : racine(s), droite(0), gauche(0), precedent(A) {}

/**
 * usage : destructeur
 *
 * description : désalloue le sous arbre gauche et le sous arbre droite d'un arbre binaire
*/
ArbreB::~ArbreB() {
	if(droite) {
		delete droite;
	}
	if(gauche)
	{
		delete gauche;
	}
}

/**
 * usage : copie d'un arbre binaire
 * entrée :
 *		un pointeur @copie sur un objet de type ArbreB qui représente l'arbre dans lequel on copie
 *		un pointeur @A sur un objet de type ArbreB qui représente l'arbre que l'on copie
 *
 * description : copie un arbre binaire dans un autre arbre bianire de manière recursive.		
*/
void ArbreB::copier(ArbreB* copie, ArbreB* A) {
	if(!A) return;

	copie->racine = A->racine;
	
	
	if(A->gauche) {
		copie->gauche = new ArbreB(A->gauche->racine);
	}
	if(A->droite) {
		copie->droite = new ArbreB(A->droite->racine);
	}

	copie->precedent = new ArbreB(A->precedent->racine);

	copier(copie->gauche, A->gauche);
	copier(copie->droite, A->droite);
}

/**
 * usage : constructeur de copie
 * entrée : un pointeur @A sur un objet de type ArbreB
 *
 * description : utilise la fonction copier, pour copier l'objet @A dans l'objet courant
*/
ArbreB::ArbreB(ArbreB* A) {
	ArbreB* tmp = this;
	copier(tmp, A);
}

/**
 * usage : getter de @racine
 * retour : @racine de l'arbre courant
 *
 * description : permet d'accéder à la racine de l'arbre binaire courant
*/
Sommet& ArbreB::getSommet() {
	return racine;
}

/**
 * usage : getter de @droite
 * retour : @droite de l'arbre courant
 *
 * description : permet d'accéder au sous-arbre droit de l'arbre binaire courant
*/
ArbreB* ArbreB::getDroite() {
	return droite;
}

/**
 * usage : getter de @gauche
 * retour : @gauche de l'arbre courant
 *
 * description : permet d'accéder au sous-arbre gauche de l'arbre binaire courant
*/
ArbreB* ArbreB::getGauche() {
	return gauche;
}

/**
 * usage : getter de @precedent
 * retour : @precedent de l'arbre courant
 *
 * description : permet d'accéder à l'arbre bianire précédant de l'arbre binaire courant
*/
ArbreB* ArbreB::getPrecedent() {
	return precedent;
}

/**
 * usage : ajout d'un sommet dans un arbre binaire
 * entrée : une référence @s du sommet que l'on veut ajouter
 * retour : l'arbre binaire après ajout ou non du sommet
 *
 * description :
 * 		ajoute un sommet dans un arbre bianire de manière itérative à l'aide une boucle while et un pointeur pour parcourir l'arbre binaire.
 *		le sommet ajouté, est comparé avec les sommets de l'arbre binaire pour déterminer sa place au sein de l'arbre.
*/
ArbreB& ArbreB::ajouter(Sommet& s) {
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
		}
		else {
			tmp = tmp->droite;
		}
	}

	if(s < prec->racine) {
		prec->gauche = new ArbreB(s, prec);
	}
	else {
		prec->droite = new ArbreB(s, prec);
	}

	return *this;
}

/**
 * usage : déterminer le sommet de valeur minimale dans un arbre binaire
 * entrée : un pointeur vers l'arbre bianire dans lequel on veut obtenir la valeur minimale
 * retour : un arbre binaire qui contient la racine avec la valeur minimale
 *
 * description :
 * 		détermine la valeur minimale d'un arbre de manière itérative à l'aide d'un boucle while et d'un pointeur qui parcours l'arbre binaire.
 * 		on se déplace toujours à gauche dans l'arbre jusqu'à arriver vers une feuille, car les valeurs minimales sont toujours à gauches.
*/
ArbreB* ArbreB::min(ArbreB* A) {
	ArbreB* min = nullptr;

	while(A) {
		min = A;
		A = A->gauche;
	}

	return min;
}

/**
 * usage : déterminer le sommet de valeur maximale dans un arbre binaire
 * entrée : un pointeur vers l'arbre bianire dans lequel on veut obtenir la valeur maximale
 * retour : un arbre binaire qui contient la racine avec la valeur maximale
 * 
 * description :
 * 		détermine la valeur maximale d'un arbre de manière itérative à l'aide d'un boucle while et d'un pointeur qui parcours l'arbre binaire.
 * 		on se déplace toujours à droite dans l'arbre jusqu'à arriver vers une feuille, car les valeurs maximales sont toujours à droite.
*/
ArbreB* ArbreB::max(ArbreB* A) {
	ArbreB* max = nullptr;

	while(A) {
		max = A;
		A = A->droite;
	}

	return max;
}

/**
 * usage : supprimer un sommet dans un arbre binaire
 * entrée : une référence du sommet @s que l'on veut supprimer dan l'abre courant.
 * retour : l'arbre binaire après suppression ou non du sommet
 * 
 * description :
 * 		on determine la position du sommet @s dans l'arbre binaire à l'aide d'une boucle while et d'un pointeur.
 *		suivant le cas où le sommet que l'on veut supprimer à 0, 1 ou 2 sous-arbres, on supprime ce sommet.
 *		dans le cas où le sommet que l'on veut supprer à deux sous-arbre, on utilise les fonctions max ou min.
*/
ArbreB& ArbreB::supprimer(Sommet& s) {
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

/**
 * usage : rechercher un sommet dans un arbre binaire 
 * entrée : une référence @s du sommet à rechercher 
 * retour : le sommet trouvé dans l'arbre 
 *
 * description : effectue un parcours d'arbre à l'aide d'un pointeur et une fois le sommet trouvé on le renvoie .
*/
Sommet& ArbreB::rechercher(Sommet& s) {
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

/**
 * usage : modification des valeurs @lettre et @freq d'un sommet d'un arbre binaire
 * entrée : une référence du sommet à modifier, les valeurs nouvelles de @lettre et @freq de @s
 * retour : l'arbre binaire avec le sommet modifié
 *
 * description :
 * 		la méthode parcourt l'arbre à l'aide d'un pointeur et cherche le sommet donné en paramètres.
 * 		une fois trouvé elle modifie les valeurs de ses attributs à l'aide des méthodes SetChar() et SetFreq()
*/
ArbreB& ArbreB::modifier(Sommet& s, char c, int f) {
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

/**
 * usage : fusionner deux arbres binaires
 * entrée : l'arbre binaire avec lequel on veut fusionner l'arbre courant
 * retour : nouvel arbre qui est la fusion de l'arbre à fusionner donné en paramètre avec l'arbre courant
 *
 * description : ajoute les sommets de l'arbre en paramètre dans l'arbre courant de manière récursive
*/
ArbreB& ArbreB::fusionner(ArbreB* A) {
	if(!A || racine.getChar() == 0 || A->racine.getChar() == 0) {
		return *this;
	}

	ajouter(A->racine);

	fusionner(A->gauche);
	fusionner(A->droite);

	return *this;
}

/**
 * usage : récupérer le sous-arbre gauche d'un arbre bianire
 * entrée : l'arbre binaire @Ag qui récupere le sous-arbre gauche et l'arbre bianire @A dans lequel on veut récupérer son sous-arbre gauche
 *
 * description : ajout de manière récursive le sous-arbre gauche de l'arbe binaire passé en paramètre
*/
void ArbreB::recupererGauche(ArbreB* Ag, ArbreB* A) {
	if(!A || A->getSommet().getChar() == 0) {
		return;
	}

	if(A->racine == racine) {
		recupererGauche(Ag, A->gauche);
		return;
	}

	Ag->ajouter(A->racine);

	recupererGauche(Ag, A->gauche);
	recupererGauche(Ag, A->droite);
}

/**
 * usage : récupérer le sous-arbre droit d'un arbre bianire
 * entrée : l'arbre binaire @Ad qui récupere le sous-arbre droit et l'arbre bianire @A dans lequel on veut récupérer son sous-arbre droit
 *
 * description : ajout de manière récursive le sous-arbre droit de l'arbe binaire passé en paramètre
*/
void ArbreB::recupererDroite(ArbreB* Ad, ArbreB* A) {
	if(!A || A->getSommet().getChar() == 0) {
		return;
	}

	if(A->racine == racine) {
		recupererDroite(Ad, A->droite);
		return;
	}

	Ad->ajouter(A->racine);

	recupererDroite(Ad, A->gauche);
	recupererDroite(Ad, A->droite);
}

/**
 * usage : décomposer un arbre bianire en deux sous-arbres
 * entrée :
 * 		l'arbre binaire @Ag qui récuperer le sous-arbre gauche,
 * 		l'arbre binaire @Ad qui récupere le sous-arbre droit,
 * 		l'arbre bianire @A dans lequel on veut récupérer son sous-arbre gauche et son sous-arbre droit
 *
 * description : utilisation des fonction ajouterGauche et ajouterDroite pour récupérer respectivement le sous-arbre gauche et le sous-arbre droit de l'arbre @A
*/
void ArbreB::decomposer(ArbreB* Ag, ArbreB* Ad, ArbreB* A) {
	if(!A) {
		return;
	}

	Ag->recupererGauche(Ag, A->gauche);
	Ad->recupererDroite(Ad, A->droite);
}

/**
 * usage : afficher l'arbre courant dans la sortie standard
 * entrée :
 * 		la hauteur de l'arbre que l'on veut afficher
 * 		un entier pour déterminer de quel côté on se trouve dan l'arbre
 *		un pointeur sur l'arbre que l'on afficher
 *
 * description : affiche de manière recursive l'arbre binaire en incrémentant la hauteur de 1
*/
void ArbreB::afficher_arb(int hauteur, int cote, ArbreB* A) {
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

    afficher_arb(hauteur + 1, 0, A->getGauche());
    afficher_arb(hauteur + 1, 1, A->getDroite());
}

/**
 * usage : afficher l'arbre courant dans la sortie standard avec le sommet courant et son précédent
 * entrée : un pointeur sur l'arbre que l'on veut afficher
 *
 * description : affiche de manière recursive l'arbre en parcours infixe
*/
void ArbreB::affichage_infixe(ArbreB* A) {
	if(A == nullptr) return;

	if(racine.getChar() == 0) {
		cout << A->racine << endl;
		return;
	}

	if(A) {
		affichage_infixe(A->gauche);
		cout << A->racine;
		affichage_infixe(A->droite);
	}

	cout << endl;
}

/**
 * usage : déterminer la hauteur d'un arbre binaire
 * entrée : un pointeur sur l'abre binaire, et une hauteur pour le sous-arbre droit et une hauteur pour le sous-arbre gauche
 * retour : la hauteur de l'abre binaire
 * 
 * description :
 * 		determine la hauteur de manière récursive en comparant la hauteur du sous-arbre droit et du sous-arbre gauche
 *		on retour la hauteur maximal entre le sous-arbre droit et le sous-arbre gauche
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

/**
 * usage : déterminer le nombre de sommet dans un arbre binaire
 * entrée : un pointeur sur l'arbre binaire dont on veut déterminer le nombre de sommet
 * retour : le nombre de sommet dans l'abre bianire
 *
 * description : on determine le nombre de sommet de manière recursive en incrémentant de 1 à chaque fois que l'on passe d'un sommet de l'arbre à un autre.
*/
int ArbreB::nombre_element(ArbreB* A) {

	if(racine.getChar() == 0 || A == nullptr) {
		return 0;
	}

	return 1 + nombre_element(A->gauche) + nombre_element(A->droite);
}

void ArbreB::ajouterGauche(ArbreB* A1, ArbreB* A) {
	if(A1)
		A->gauche = new ArbreB(A1->getSommet(),A);
}

void ArbreB::ajouterDroite(ArbreB* A2, ArbreB* A) {
	if(A2)
		A->droite = new ArbreB(A2->getSommet(),A);
}

ArbreB& ArbreB::setFreq(ArbreB* A1, ArbreB* A2) {
	racine.setFreq(A1->racine.getFreq() + A2->racine.getFreq());
	return *this;
}

ArbreB& ArbreB::fusionner(ArbreB* A1, ArbreB* A2) {
	if(racine.getChar() != 0)
		return *this;

	gauche = new ArbreB(A1);
	droite = new ArbreB(A2);
	precedent = this;
	racine.setFreq(A1->racine.getFreq() + A2->racine.getFreq());

	return *this;
}