#include "../inc/huffman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

string choisir_texte() {
	string file_name;
	cout << "Entrez le nom du fichier texte : " << endl;
	cin >> file_name;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return file_name;
}

void verification_fichier(fstream& file, string name) {
	if(!file.is_open()) {
		cerr << "Erreur: lors de l\'ouverture du fichier " << name << "." << endl;
		exit(2);
	}
}

vector<string> copier_texte(fstream& file){
	vector<string> decrypt_txt; 
	string line;
	while(getline(file, line)) {
		decrypt_txt.push_back(line);
	}
	return decrypt_txt;
}

int calcul_freq(char c, string s) {
    int freq = 0;
	string::size_type i;
	for(i = 0; i < s.size(); i++) {
		if(s[i] == c)
			freq++;
		else if(s[i]-32 == c)
			freq++;
	}
	return freq;
}

void afficher_frequence_alphabet(vector<string> texte) {
	int freq;
	char alphabet_latin[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	for(int i = 0; i < 26; i++) {
		for(string ligne : texte) {
			freq += calcul_freq(alphabet_latin[i], ligne);
		}
		cout << alphabet_latin[i] << " : " << freq << endl;
		freq = 0;
	}
}

void afficher_texte(vector<string> texte) {
	for(string ligne : texte) {
		cout << ligne << endl;
	}
}
