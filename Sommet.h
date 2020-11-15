#ifndef SOMMET_H
#define SOMMET_H

#include <stdio.h>
#include <iostream>

using namespace std;

class Sommet {
	private :
		int freq;
		char lettre;
	public :
		Sommet();
		Sommet(Sommet& s);
		Sommet(char Slettre, int Sfreq);
		~Sommet();

		int getFreq();
		char getChar();
		void setFreq(int i);
		void setChar(char c);

		bool operator ==(Sommet& s); // s1 == s2
		bool operator <(Sommet& s); // s1 < s2
		bool operator >(Sommet& s); // s1 > s2
		Sommet& operator=(Sommet& s); //s1 = s2
		friend ostream& operator<<(ostream& flux, Sommet& s); // cout << s
		friend ostream& operator<<(ostream& flux, Sommet* s); // cout << *s
};
#endif