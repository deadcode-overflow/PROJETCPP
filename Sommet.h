#ifndef SOMMET_H
#define SOMMET_H

class Sommet {
	private :
		int freq;
		char lettre;
	public :
		Sommet();
		Sommet(const Sommet& s);
		Sommet(Sommet* &s);
		Sommet(char Slettre, int Sfreq);
		~Sommet();

		int getFreq();
		char getChar();

		bool operator ==(Sommet& s);
};
#endif