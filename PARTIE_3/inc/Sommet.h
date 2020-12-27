#ifndef SOMMET_H
#define SOMMET_H

#include <iostream>

using namespace std;

class Sommet {
	private :
		int freq;
		char lettre;
	public :
		// Constructeurs
		Sommet();
		Sommet(const Sommet& s);
		Sommet(char Slettre, int Sfreq);
		// Destructeur
		~Sommet();

		// Gettres
		int getFreq();
		char getChar();
		// Setters
		void setFreq(int i);
		void setChar(char c);

		// Surchages d'opérateurs
		bool operator ==(Sommet& s);
		bool operator <(Sommet& s);
		bool operator >(Sommet& s);
		Sommet& operator =(const Sommet& s);
		friend ostream& operator<<(ostream& flux, Sommet& s);
		friend ostream& operator<<(ostream& flux, Sommet* s);
};
#endif