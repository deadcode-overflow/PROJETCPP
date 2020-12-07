#include "../inc/huffman.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {

	string file_name = choisir_texte();
	fstream file(file_name.c_str(), ios::in);
	verification_fichier(file, file_name);
	vector<string> texte_clair = copier_texte(file);
	afficher_frequence_alphabet(texte_clair);	
	afficher_texte(texte_clair);

	return 0;
}