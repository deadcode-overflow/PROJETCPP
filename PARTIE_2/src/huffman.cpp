#include "../inc/huffman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <map>

using namespace std;

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
	string::size_type i;
	for(size_t i = 0; i < s.size(); i++) {
		if(s[i] == c)
			freq++;
		else if(s[i]-32 == c)
			freq++;
	}
	return freq;
}

void calculer_frequence_alphabet(vector<string> texte, map<char, int>& frequence_alphabet) {
	int frequence;
	char alphabet_latin[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	for(int i = 0; i < 26; i++) {
		for(string ligne : texte) {
			frequence += calcul_freq(alphabet_latin[i], ligne);
		}
		frequence_alphabet[alphabet_latin[i]] = frequence;
		frequence = 0;
	}
}

void afficher_frequence_alphabet(map<char, int> frequence_alphabet) {
	for(size_t i = 0; i < frequence_alphabet.max_size(); i++)
		cout << frequence_alphabet[i] << endl;
}

void afficher_texte(vector<string> texte) {
	for(string ligne : texte) {
		cout << ligne << endl;
	}
}
