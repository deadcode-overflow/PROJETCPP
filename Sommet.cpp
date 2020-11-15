#include "Sommet.h"
#include <iostream>
#include <stdio.h>

using namespace std;

Sommet::Sommet() : lettre('\0'), freq(0) {}

Sommet::Sommet(Sommet& s) : lettre(s.lettre), freq(s.freq) {}

Sommet::Sommet(char Slettre, int Sfreq) : lettre(Slettre), freq(Sfreq) {}

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

Sommet& Sommet::operator=(Sommet& s) {
	lettre = s.lettre;
	freq = s.freq;

	return *this;
}

ostream& operator<<(ostream& flux, Sommet& s) {
	flux << "Sommet : " << s.getChar() << " " << s.getFreq() << endl;

	return flux;
}

ostream& operator<<(ostream& flux, Sommet* s) {
	flux << "Sommet : " << s->getChar() << " " << s->getFreq() << endl;

	return flux;
}