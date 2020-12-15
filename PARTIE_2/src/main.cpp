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

	
	vector<ArbreB*> feuilles;
	for(Sommet& s : sommets) {
		feuilles.push_back(new ArbreB(s));
	}
	afficher_arbres_infixe(feuilles);

	list<ArbreB*> huffman;
	size_t taille = feuilles.size();
	size_t index = 1;
	size_t i;
	for(i = 1; i <= taille/2; i++) {
		ArbreB r;
		if(taille%2 == 1 && i == taille/2) {
			r.fusionner_huffman(feuilles[feuilles.size()-index], feuilles[feuilles.size()-(index+1)]);
			huffman.push_back(new ArbreB(&r));
			huffman.push_back(new ArbreB(feuilles[0]));
		}
		else {
			r.fusionner_huffman(feuilles[feuilles.size()-index], feuilles[feuilles.size()-(index+1)]);
			huffman.push_back(new ArbreB(&r));
		}
		index+=2;
	}
	//afficher_arbres_arbo(huffman);
	//huffman.front()->afficher_arbo(0,0,huffman.front());
	//huffman.front()->affichage_infixe(huffman.front());

	while(huffman.size() != 1) {
		ArbreB r;
		cout << "\tDERNIER" << endl;
		ArbreB* dernier = new ArbreB(huffman.front());
		dernier->afficher_arbo(0,0,dernier);
		dernier->affichage_infixe(dernier);
		//cout << "2" << endl;
		huffman.pop_front();
		cout << "\tAVANT DERNIER" << endl;
		ArbreB* avant_dernier =  new ArbreB(huffman.front());
		avant_dernier->afficher_arbo(0,0,avant_dernier);
		avant_dernier->affichage_infixe(avant_dernier);
		//cout << "4" << endl;
		huffman.pop_front();
		cout << "\tFUSION" << endl;
		cout << dernier->getSommet().getFreq() << endl;
		cout << avant_dernier->getSommet().getFreq() << endl;
		r.fusionner_huffman(dernier, avant_dernier);
		r.afficher_arbo(0,0,&r);
		r.affichage_infixe(&r);		
		cout << "\tHUFFMAN" << endl;
		huffman.push_back(new ArbreB(&r));
		huffman.back()->afficher_arbo(0,0,huffman.back());
		huffman.back()->affichage_infixe(huffman.back());
		delete avant_dernier;
		delete dernier;
	}
	//afficher_arbres_arbo(huffman);
	
	//ArbreB* huffman;
	//creer_arbres(huffman, feuilles);

	return 0;
}