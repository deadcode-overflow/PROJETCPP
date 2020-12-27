#include "../inc/huffman.h"
#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

const char alphabet_latin[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 
 /**
 * usage : choisir le fichier texte sur lequel appliquer le codage de huffman
 * retour : le nom du fichier
 *
 * description :
 * 		-propose à l'utilisateur d'entrer le nom d'un fichier texte
 * 		-retourne le nom du fichier entré par l'utilisateur
 * 
*/
string choisir_texte() {
	string nom_fichier;
	cout << "Entrez le nom du fichier texte : " << endl;
	cin >> nom_fichier;
	cout << endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return nom_fichier;
}

/**
 * usage : vérifier l'ouverture d'un fichier
 * entrée : le nom du fichier et le fichier
 *
 * description : vérifie si le fichier est ouvert, relève une erreur si ce n'est pas le cas et sort du programme.
*/
void verification_fichier(fstream& fichier, string nom) {
	if(!fichier.is_open()) {
		cerr << "Erreur: lors de l\'ouverture du fichier " << nom << "." << endl;
		exit(1);
	}
}

/**
 * usage : copier le texte d'un fichier
 * entrée : le fichier
 * retour : le texte
 *
 * description : copie ligne par ligne le texte du fichier dans un vecteur jusqu'à la fin du fichier et retourne le vecteur
*/
vector<string> copier_texte(fstream& fichier){
	vector<string> texte;
	string ligne;
	while(getline(fichier, ligne)) {
		texte.push_back(ligne);
	}
	return texte;
}

/**
 * usage : determiner la fréquence d'une lettre dans une ligne
 * entrée : une lettre et une ligne d'un texte
 * retour : la frequence de la lettre dans la ligne
 *
 * description : lit caractère par caractère la ligne et incrémente la frequence de 1 chaque fois que le caractère lu
 * et identique à la lettre d'ont on évalue la fréquence.
*/
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

/**
 * usage : calculer la fréquence de chaque lettre de l'alphabet dans un texte
 * entrée : un vecteur de string qui représente un texte, et une map de char et int qui represente le tableau de fréquence
 * de chaque lettre de l'alphabet.
 *
 * description :lit ligne par ligne le texte pour chaque lettre et détermine leur fréquence avec la fonction calcul_freq()
*/
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

/**
 * usage : afficher un texte
 * entrée : un vecteur de string qui représente un texte
 *
 * description : affiche le texte non codé
*/
void afficher_texte(vector<string>& texte) {
	cout << "\t TEXTE ORIGINAL" << endl;
	for(string ligne : texte)
		cout << ligne << endl;
	cout << endl;
}

/**
 * usage : créer un sommet pour chaque lettre et sa frequence correspondante
 * entrée :
 * 		-un vecteur de sommet qui représente le tableau de sommet que l'on va obtenir
 * 		-une map de char et int qui représente chaque lettre et leur fréquence correspondante.
 *
 * description : créer un sommet pour chaque lettre à l'aide de la map, avec le constructeur par valeur
 * et l'ajoute au vecteur
*/
void creer_sommets(vector<Sommet>& sommets, map<char, int>& frequence_alphabet) {
	for(int i = 0; i < 26; i++) {
		if(frequence_alphabet[alphabet_latin[i]] != 0) {
			Sommet s(alphabet_latin[i], frequence_alphabet[alphabet_latin[i]]);
			sommets.push_back(s);
		}
	}	
}

/**
 * usage : renseigne la manière de trier pour la fonction std::sort entre deux sommmets
 * entrée : les deux sommets à comparer
 * retour : le resultat de la comparaison
 *
 * description : compare deux sommets en fonction de la fréquence qu'ils contiennent
*/
int comparaison_sommets(Sommet& a,Sommet& b) {
    return a.getFreq() == b.getFreq() ? a.getFreq() < b.getFreq() : a.getFreq() < b.getFreq();
}

/**
 * usage : afficher l'arbre d'huffman de manière infixe
 * entrée : un vecteur de pointeur sur des arbres binaires
 *
 * description : utilise la fonction affichage_infixe pour afficher l'arbre d'huffman
*/
void afficher_arbres_infixe(list<ArbreB*>& arbres) {
	cout << "\tHUFFMAN" << endl;
	int ix = 0;
	for(auto const& i : arbres) {
		cout << "index " << ix << endl;
		i->affichage_infixe(i);
		ix++;
	}
	cout << endl;
}

/**
 * usage : afficher l'arbre d'huffman de manière arborescente
 * entrée : un vecteur de pointeur sur des arbres binaires
 *
 * description : utilise la fonction afficher_arbo pour afficher l'arbre d'huffman
*/
void afficher_arbres_arbo(list<ArbreB*>& arbres) {
	cout << "\tHUFFMAN" << endl;
	int ix = 0;
	for(auto const& i : arbres) {
		cout << "index " << ix << endl;
		i->afficher_arbo(0,0,i);
		ix++;
	}
	cout << endl;
}

/**
 * usage : determine le codage pour une lettre de l'alphabet
 * entrée :
 * 		-l'arbre bianire d'huffman
 * 		-la lettre à coder
 * 		-le code qui est modifier à chaque fois que l'on parcourant l'arbre
 * 		-le resultat final du codage de la lettre
 *
 * description :
 * 		-parcoure l'arbre de manière récursive
 * 		-ajoute 1 au code lorsque l'on se déplace à gauche dans l'arbre
 * 		-ajoute 0 au code lorsque l'on se déplace à droite dans l'arbre
 * 		-si la lettre est trouvé le code devient resultat
 * 		-sinon le code n'est pas sauvgardé
*/
void code_lettre(ArbreB* A, char lettre, string code, string& resultat) {
	if(A) {
		if(A->getSommet().getChar() == lettre) {
			resultat.append(code);
		}
		
		code.push_back('1');
		code_lettre(A->getGauche(), lettre, code, resultat);
		code.pop_back();
		code.push_back('0');
		code_lettre(A->getDroite(), lettre, code, resultat);
	}
}

/**
 * usage : determine le codage pour chaque lettre de l'alphabet
 * entrée :
 * 		-l'arbre binaire d'huffman
 * 		-une map de char et string qui représente le codage de chaque lettre
 *
 * description : utilise la fonction code_lettre pour déterminer le codage pour chaque lettre de l'alphabet
*/
void codage_alphabet(ArbreB* A, map<char, string>& code_alphabet) {
	for(int i = 0; i < 26; i++) {
		string resultat = "";
		string code = "";
		code_lettre(A ,alphabet_latin[i], code, resultat);
		if(resultat != "")
			code_alphabet[alphabet_latin[i]] = resultat;
	}
}

/**
 * usage : afficher le code de chaque lettre de l'alphabet
 * entrée : une map de char et string qui représente le codage de chaque lettre
 *
 * description : afficher la lettre et son code correspondant
*/
void afficher_code_alphabet(map<char, string>& code_alphabet) {
	cout << "\t CODAGE DES LETTRES" << endl;
	for(int  i = 0; i < 26; i++)
		cout << alphabet_latin[i] << ": " << code_alphabet[alphabet_latin[i]] << endl;
	cout << endl;
}

/**
 * usage : savoir si un caractère fait parti des lettres de l'alphabet
 * entrée : le caractère à évaluer et un tableau de caractère qui représente les lettres de l'alphabet
 * retour : un booléen
 * description : retourne vrai si le caractère et dans l'alphabet, sinon retourne faux
*/
bool in(char c, const char* alphabet_latin) {
	for(int i = 0; i < 26; i++) {
		if(c == alphabet_latin[i])
			return true;
	}
	return false;
}

/**
 * usage : afficher un texte codé
 * entrée : un vecteur de string qui représente le texte et une map de char et de string qui représente
 * le code de chaque lettre de l'alphabet
 *
 * description : affiche le texte codé
*/
void afficher_texte_code(vector<string>& texte, map<char, string>& code_alphabet) {
	cout << "\t TEXTE CODÉ" << endl;
	for(string ligne : texte) {
		for(size_t i = 0; i < ligne.size(); i++) {
			char c = ligne.at(i);
			if(code_alphabet[c] == "" && code_alphabet[c-32] == "")
				cout << "";
			if(in(c, alphabet_latin))
				cout << code_alphabet[c];
			else
				cout << code_alphabet[c-32];
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * usage : copier le texte codé dans un fichier texte
 * entrée : le fichier texte, un vecteur de string qui représente le texte à copier
 * et une map de char/string qui représente le code de chaque lettre de l'alphabet
 *
 * description : copie bit par bit le code du texte dans un fichier texte
*/
void copier_resultat(fstream& fichier, vector<string>& texte, map<char, string>& code_alphabet) {
	for(string ligne : texte) {
		for(size_t i = 0; i < ligne.size(); i++) {
			char c = ligne.at(i);
			if(code_alphabet[c] == "" && code_alphabet[c-32] == "")
				fichier << "";
			if(in(c, alphabet_latin))
				fichier << code_alphabet[c];
			else
				fichier << code_alphabet[c-32];
		}
		fichier << endl;
	}
	fichier << endl;
	fichier.close();
}

/**
 * usage : prendre un texte et le coder avec l'algorithme de huffman
 *
 * description :
 * 		-ouvre le fichier donner par l'utilisateur
 * 		-vérifie son ouverture
 * 		-copie le texte du fichier
 * 		-afficher le texte
 * 		-détermine la fréquence de chaque lettre dans le texte
 * 		-créer un sommet pour chaque lettre dans un vecteur
 * 		-trie le vecteur de sommet
 * 		-créer les feuilles de l'arbre d'huffman
 * 		-construit des pairs de feuilles en fonction de la fréquence du sommet
 * 		-construit l'arbre d'huffman en fonction de la fréquence de chaque lettre
 * 		-affiche l'arborecence de l'arbre d'huffman
 * 		-code les lettres de l'alphabet avec l'arbre d'huffman
 * 		-affiche le code de chaque lettre de l'alphabet
*/
void huffman() {
	string nom_fichier = choisir_texte();
	fstream fichier(nom_fichier.c_str(), ios::in);
	verification_fichier(fichier, nom_fichier);

	vector<string> texte_clair = copier_texte(fichier);
	fichier.close();
	map<char, int> frequence_alphabet;
	calculer_frequence_alphabet(texte_clair, frequence_alphabet);
	afficher_texte(texte_clair);

	vector<Sommet> sommets;
	creer_sommets(sommets, frequence_alphabet);
	sort(sommets.begin(), sommets.end(), comparaison_sommets);
	reverse(sommets.begin(),sommets.end());
	
	vector<ArbreB*> feuilles;
	for(Sommet& s : sommets) {
		feuilles.push_back(new ArbreB(s));
	}

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

	while(huffman.size() != 1) {
		ArbreB r;
		ArbreB* dernier = new ArbreB(huffman.front());
		huffman.pop_front();
		ArbreB* avant_dernier =  new ArbreB(huffman.front());
		huffman.pop_front();
		r.fusionner_huffman(dernier, avant_dernier);
		huffman.push_back(new ArbreB(&r));
		delete avant_dernier;
		delete dernier;
	}
	afficher_arbres_arbo(huffman);

	map<char, string> code_alphabet;
	codage_alphabet(huffman.front(), code_alphabet);
	afficher_code_alphabet(code_alphabet);
	afficher_texte_code(texte_clair, code_alphabet);
	fstream fichier_resultat("resultat_crypte.txt", ios::out | ios::trunc);
	verification_fichier(fichier_resultat, "resultat_crypte.txt");
	copier_resultat(fichier_resultat, texte_clair, code_alphabet);
	fichier_resultat.close();
}