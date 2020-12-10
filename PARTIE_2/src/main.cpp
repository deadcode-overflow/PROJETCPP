#include "../inc/huffman.h"
#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {

	string nom_fichier = choisir_texte();
	fstream fichier(nom_fichier.c_str(), ios::in);
	verification_fichier(fichier, nom_fichier);

	vector<string> texte_clair = copier_texte(fichier);
	map<char, int> frequence_alphabet;
	calculer_frequence_alphabet(texte_clair, frequence_alphabet);
	afficher_frequence_alphabet(frequence_alphabet);
	afficher_texte(texte_clair);

	vector<Sommet> sommets;
	creer_sommet(sommets, frequence_alphabet);
	sort(sommets.begin(), sommets.end(), comparaison);
	reverse(sommets.begin(),sommets.end());
	afficher_sommets(sommets);

	ArbreB A1;
	ArbreB A2;

	creer_A1_A2(sommets,&A1,&A2);
	cout << "ARBRE A1 " << A1.getSommet() << endl;
	cout << "ARBRE A2 " << A2.getSommet() << endl;

	ArbreB A;
	creer_A(&A, &A1,&A2);
	cout << "ARBRE A " << A.getSommet() << endl;

	return 0;
}