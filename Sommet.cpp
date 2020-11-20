#include "Sommet.h"
#include <iostream>
#include <stdio.h>

using namespace std;

/**
* usage : contructeur par defaut
* 
* description : affecte '\0' à lettre et 0 à freq
*/
Sommet::Sommet() : lettre('\0'), freq(0) {}

/**
 * usage : constructeur de copie
 * entrée : une référence @s d'un objet de type Sommet
 * 
 * description : affecte @lettre de @s dans @lettre de l'objet courant
 *				 affecte @freq de @s dans @freq de l'objet courant
*/
Sommet::Sommet(Sommet& s) : lettre(s.lettre), freq(s.freq) {}

/**
 * usage : constructeur par valeur
 * entrée : un caractère @lettre et un entier @freq
 *
 * description : affecte @lettre en argument, à @lettre de l'objet courant
 *				 affecte @freq en argument, à @freq de l'objet courant
*/
Sommet::Sommet(char lettre, int freq) : lettre(lettre), freq(freq) {}

/**
 * usage : destructeur
*/
Sommet::~Sommet() {}

/**
 * usage : getter de @freq
 * retour : @freq du sommet courant
 * 
 * description : permet d'accèder à @freq de l'objet courant
*/
int Sommet::getFreq() {
	return freq;
}

/**
 * usage : getter de @lettre
 * retour : @lettre du sommet courant
 *
 * description : permet d'accèder à @lettre de l'objet courant
*/
char Sommet::getChar() {
	return lettre;
}

/**
 * usage : setter de @freq
 * entrée : un entier @i
 *
 * description : affecte la valeur de @i à @freq de l'objet courant
*/
void Sommet::setFreq(int i) {
	freq = i;
}

/**
 * usage : setter de @lettre
 * entrée : un caractère @c
 *
 * description : affecte la valeur de @c à @lettre de l'objet courant
*/
void Sommet::setChar(char c) {
	lettre = c;
}

/**
 * usage : comparaison d'égalité entre deux objets de type Sommet
 * entrée : une référence @s d'un objet de type Sommet
 * retour : un @boolean, résultat de la comparaison
 *
 * description : surcharge de l'opérateur ==, en comparant les @lettre et @freq entre le sommet courant et le sommet passé en paramètre de fonction 
*/
bool Sommet::operator ==(Sommet& s) {
	if(lettre == s.lettre && freq == s.freq) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * usage : comparaison d'infériorité entre deux objets de type Sommet
 * entrée : une référence @s d'un objet de type Sommet
 * retour : un @boolean, résultat de la comparaison
 *
 * description : surcharge de l'opérateur <, en comparant les @lettres entre l'objet courant et l'objet passé en paramètre de fonction
*/
bool Sommet::operator <(Sommet& s) {
	return lettre < s.lettre;
}

/**
 * usage : comparaison de supériorité entre deux objets de type Sommet
 * entrée : une référence @s d'un objet de type Sommet
 * retour : un @boolean, résultat de la comparaison
 *
 * description : surcharge de l'opérateur >, en comparant les @lettres entre l'objet courant et l'objet passé en paramètre de fonction
*/
bool Sommet::operator >(Sommet& s) {
	return lettre > s.lettre;
}

/**
 * usage : affectation d'un objet de type Sommet, avec un autre  objet de type Sommmet
 * entrée : une référence @s d'un objet de type Sommet
 * retour : l'objet courant
 *
 * description : surcharge de l'opérateur =, en affectant @lettre @s dans @lettre de l'objet courant et en affectant @freq de @s dans @freq de l'objet courant
*/
Sommet& Sommet::operator =(Sommet& s) {
	lettre = s.lettre;
	freq = s.freq;

	return *this;
}

/**
 * usage : affichage de l'objet de type Sommet avec std::cout
 * entrée : un flux de sortie @flux et une référence @s d'un objet de type Sommet
 * retour : le flux de sortie @flux
 * 
 * description : surcharge de l'opérateur <<, en affichant @lettre et @freq de l'objet @s
*/
ostream& operator<<(ostream& flux, Sommet& s) {
	flux << "Sommet : " << s.getChar() << " " << s.getFreq() << endl;

	return flux;
}

/**
 * usage : affichage de l'objet de type Sommet* avec std::cout
 * entrée : un flux de sortie @flux et une référence @s d'un objet de type Sommet*
 * retour : le flux de sortie @flux
 * 
 * description : surcharge de l'opérateur <<, en affichant @lettre et @freq de l'objet @s
*/
ostream& operator<<(ostream& flux, Sommet* s) {
	flux << "Sommet : " << s->getChar() << " " << s->getFreq() << endl;

	return flux;
}