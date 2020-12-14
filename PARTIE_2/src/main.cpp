#include "../inc/huffman.h"
#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <list>

using namespace std;

int main(void) {

	string nom_fichier = choisir_texte();
	fstream fichier(nom_fichier.c_str(), ios::in);
	verification_fichier(fichier, nom_fichier);

	vector<string> texte_clair = copier_texte(fichier);
	map<char, int> frequence_alphabet;
	calculer_frequence_alphabet(texte_clair, frequence_alphabet);
	//afficher_frequence_alphabet(frequence_alphabet);
	afficher_texte(texte_clair);

	vector<Sommet> sommets;
	creer_sommets(sommets, frequence_alphabet);
	sort(sommets.begin(), sommets.end(), comparaison_sommets);
	reverse(sommets.begin(),sommets.end());
	//afficher_sommets(sommets);

	
	vector<ArbreB*> arbres;
	for(Sommet& s : sommets) {
		arbres.push_back(new ArbreB(s));
	}
	cout << "FEUILLES" << endl;
	afficher_arbres_infixe(arbres);

	list<ArbreB*> huffman;
	size_t taille = arbres.size();
	size_t index = 1;
	for(size_t i = 1; i <= taille/2; i++) {
		ArbreB r;
		if(taille%2 == 1 && i == taille/2) {
			r.fusionner_huffman(arbres[arbres.size()-index], arbres[arbres.size()-(index+1)]);
			r.afficher_arbo(0,0,&r);
			huffman.push_back(&r);
			huffman.push_back(new ArbreB(arbres[0]));
		}
		else {
			r.fusionner_huffman(arbres[arbres.size()-index], arbres[arbres.size()-(index+1)]);
			cout << "	RESULTAT DE LA FUSION" << endl;
			r.afficher_arbo(0,0,&r);
			r.affichage_infixe(&r);
			huffman.push_back(new ArbreB(&r));
		}
		index+=2;
	}
	cout << "	HUFFMAN" << endl;
	afficher_arbres_arbo(huffman);

	//ArbreB* huffman;
	//creer_arbres(huffman, arbres);

	return 0;
}