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
	creer_sommets(sommets, frequence_alphabet);
	sort(sommets.begin(), sommets.end(), comparaison_sommets);
	reverse(sommets.begin(),sommets.end());
	afficher_sommets(sommets);

	cout << "-----------" << endl;
	vector<ArbreB*> arbres;
	creer_arbres(arbres, sommets);
	int i = 1;
	arbres[i]->affichage_infixe(arbres[i]);
	arbres[i]->afficher_arb(0,0,arbres[i]);
	//reverse(arbres.begin(), arbres.end(), comparaison_arbres);
	//afficher_arbres(arbres);
	

	return 0;
}