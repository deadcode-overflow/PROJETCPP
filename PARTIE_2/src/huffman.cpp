#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"
#include "../inc/huffman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <map>
#include <list>

using namespace std;

#define ALPHABET_LATIN 26
const char alphabet_latin[ALPHABET_LATIN] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

string choisir_texte() {
	string nom_fichier;
	cout << "Entrez le nom du fichier texte : " << endl;
	cin >> nom_fichier;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return nom_fichier;
}

void verification_fichier(fstream& fichier, string nom) {
	if(!fichier.is_open()) {
		cerr << "Erreur: lors de l\'ouverture du fichier " << nom << "." << endl;
		exit(1);
	}
}

vector<string> copier_texte(fstream& fichier){
	vector<string> texte;
	string ligne;
	while(getline(fichier, ligne)) {
		texte.push_back(ligne);
	}
	return texte;
}

int calcul_freq(char c, string s) {
    int freq = 0;
	for(size_t i = 0; i < s.size(); i++) {
		if(s[i] == c)
			freq++;
		else if(s[i]-32 == c)
			freq++;
	}
	return freq;
}

void calculer_frequence_alphabet(vector<string>& texte, map<char, int>& frequence_alphabet) {
	int frequence;
	for(int i = 0; i < 26; i++) {
		for(string ligne : texte) {
			frequence += calcul_freq(alphabet_latin[i], ligne);
		}
		frequence_alphabet[alphabet_latin[i]] = frequence;
		frequence = 0;
	}
}

void afficher_frequence_alphabet(map<char, int>& frequence_alphabet) {
	for(int  i = 0; i < ALPHABET_LATIN; i++)
		cout << alphabet_latin[i] << " " << frequence_alphabet[alphabet_latin[i]] << endl;
	cout << endl;
}

void afficher_texte(vector<string>& texte) {
	for(string ligne : texte)
		cout << ligne << endl;
	cout << endl;
}

void creer_sommets(vector<Sommet>& sommets, map<char, int>& frequence_alphabet) {
	for(int i = 0; i < 26; i++) {
		if(frequence_alphabet[alphabet_latin[i]] != 0) {
			Sommet s(alphabet_latin[i], frequence_alphabet[alphabet_latin[i]]);
			sommets.push_back(s);
		}
	}	
}

int comparaison_sommets(Sommet& a,Sommet& b) {
    return a.getFreq() == b.getFreq() ? a.getFreq() < b.getFreq() : a.getFreq() < b.getFreq();
}

void afficher_sommets(vector<Sommet>& sommets) {
	for(Sommet& s : sommets)
		cout << s << endl;
}

void afficher_arbres_infixe(vector<ArbreB*>& arbres) {
	for(size_t i=0; i < arbres.size(); i++) {
		cout << "index " << i << endl;
		arbres[i]->affichage_infixe(arbres[i]);
	}
}

void afficher_arbres_arbo(vector<ArbreB*>& arbres) {
	for(size_t i=0; i < arbres.size(); i++) {
		cout << "index " << i << endl;
		arbres[i]->afficher_arbo(0,0,arbres[i]);
	}
}

void afficher_arbres_infixe(list<ArbreB*>& arbres) {
	int ix = 0;
	for(auto const& i : arbres) {
		cout << "index " << ix << endl;
		i->affichage_infixe(i);
		ix++;
	}
}

void afficher_arbres_arbo(list<ArbreB*>& arbres) {
	int ix = 0;
	for(auto const& i : arbres) {
		cout << "index " << ix << endl;
		i->afficher_arbo(0,0,i);
		ix++;
	}
}

/*void creer_A(ArbreB* A, ArbreB* A1, ArbreB* A2) {
	A->ajouterGauche(A1, A);
	A->ajouterDroite(A2, A);
	A->setFreq(A1, A2);
}*/

/*void creer_arbres(ArbreB* huffman, vector<ArbreB>& feuilles) {
	;
}*/