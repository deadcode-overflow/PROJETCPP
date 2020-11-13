#include "Sommet.h"
#include <iostream>

using namespace std;

Sommet::Sommet() {
	lettre = '\0';
	freq = 0;
}

Sommet::Sommet(const Sommet& s) {
	lettre = s.lettre;
	freq = s.freq;
}

Sommet::Sommet(Sommet* &s) {
	lettre = s->lettre;
	freq = s->freq;
}

Sommet::Sommet(char Slettre, int Sfreq) {
	lettre = Slettre;
	freq = Sfreq;
}

Sommet::~Sommet() {
	cout << "destructeur Sommet" << endl;
}

int Sommet::getFreq() {
	return freq;
}

char Sommet::getChar() {
	return lettre;
}


bool Sommet::operator ==(Sommet& s) {
	if(lettre == s.lettre && freq == s.freq) {
		return true;
	}
	else {
		return false;
	}
}