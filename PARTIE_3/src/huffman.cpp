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

#define NOMBRE_CARACTERE 95
const char alphabet_latin[NOMBRE_CARACTERE] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	' ','.',',','!','?',';',':','/','=','+','<','>','(',')','[',']','"','\'','-','_','#','@','&','$','%','*',
	'0','1','2','3','4','5','6','7','8','9','\\','^','`','{','}','|','~'};
 
 /**
 * usage : choisir le fichier texte sur lequel appliquer le codage de huffman
 * retour : le nom du fichier
 *
 * description :
 * 		-propose à l'utilisateur d'entrer le nom d'un fichier texte
 * 		-retourne le nom du fichier entré par l'utilisateur
 * 
*/
string choisir_texte_a_crypter() {
	string nom_fichier;
	cout << "Entrez le nom du fichier texte à crypter : " << endl;
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
 * usage : determiner la fréquence d'un caractère dans une ligne
 * entrée : un caractère et une ligne d'un texte
 * retour : la frequence du caractère dans la ligne
 *
 * description : lit caractère par caractère la ligne et incrémente la frequence de 1 chaque fois que le caractère lu
 * et identique au caractère d'ont on évalue la fréquence.
*/
int calcul_freq(char c, string s) {
    int freq = 0;
	for(size_t i = 0; i < s.size(); i++) {
		if(s[i] == c)
			freq++;
	}
	return freq;
}

/**
 * usage : calculer la fréquence de chaque caractère de l'alphabet dans un texte
 * entrée : un vecteur de string qui représente un texte, et une map de char et int qui represente le tableau de fréquence
 * de chaque caractère de l'alphabet.
 *
 * description :lit ligne par ligne le texte pour chaque caractère et détermine leur fréquence avec la fonction calcul_freq()
*/
void calculer_frequence_alphabet(vector<string>& texte, map<char, int>& frequence_alphabet) {
	int frequence;
	for(int i = 0; i < NOMBRE_CARACTERE; i++) {
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
 * usage : créer un sommet pour chaque caractère et sa frequence correspondante
 * entrée :
 * 		-un vecteur de sommet qui représente le tableau de sommet que l'on va obtenir
 * 		-une map de char et int qui représente chaque caractère et leur fréquence correspondante.
 *
 * description : créer un sommet pour chaque caractère à l'aide de la map, avec le constructeur par valeur
 * et l'ajoute au vecteur
*/
void creer_sommets(vector<Sommet>& sommets, map<char, int>& frequence_alphabet) {
	for(int i = 0; i < NOMBRE_CARACTERE; i++) {
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
		i->afficher_arbo(0,0,i);
		ix++;
	}
	cout << endl;
}

/**
 * usage : determine le codage pour un caractère de l'alphabet
 * entrée :
 * 		-l'arbre bianire d'huffman
 * 		-le caractère à coder
 * 		-le code qui est modifier à chaque fois que l'on parcourant l'arbre
 * 		-le resultat final du codage de le caractère
 *
 * description :
 * 		-parcoure l'arbre de manière récursive
 * 		-ajoute 1 au code lorsque l'on se déplace à gauche dans l'arbre
 * 		-ajoute 0 au code lorsque l'on se déplace à droite dans l'arbre
 * 		-si le caractère est trouvé le code devient resultat
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
 * usage : determine le codage pour chaque caractère de l'alphabet
 * entrée :
 * 		-l'arbre binaire d'huffman
 * 		-une map de char et string qui représente le codage de chaque caractère
 *
 * description : utilise la fonction code_lettre pour déterminer le codage pour chaque caractère de l'alphabet
*/
void codage_alphabet(ArbreB* A, map<char, string>& code_alphabet) {
	for(int i = 0; i < NOMBRE_CARACTERE; i++) {
		string resultat = "";
		string code = "";
		code_lettre(A ,alphabet_latin[i], code, resultat);
		if(resultat != "")
			code_alphabet[alphabet_latin[i]] = resultat;
	}
}

/**
 * usage : afficher le code de chaque caractère de l'alphabet
 * entrée : une map de char et string qui représente le codage de chaque caractère
 *
 * description : afficher le caractère et son code correspondant
*/
void afficher_code_alphabet(map<char, string>& code_alphabet) {
	cout << "\t CODAGE DES CARACTERES" << endl;
	for(int  i = 0; i < NOMBRE_CARACTERE; i++) {
		if(code_alphabet[alphabet_latin[i]] != "")
			cout << alphabet_latin[i] << ": " << code_alphabet[alphabet_latin[i]] << endl;
	}
	cout << endl;
}

/**
 * usage : savoir si un caractère fait parti des caractères de l'alphabet
 * entrée : le caractère à évaluer et un tableau de caractère qui représente les caractères de l'alphabet
 * retour : un booléen
 * description : retourne vrai si le caractère et dans l'alphabet, sinon retourne faux
*/
bool in(char c, const char* alphabet_latin) {
	for(int i = 0; i < NOMBRE_CARACTERE; i++) {
		if(c == alphabet_latin[i])
			return true;
	}
	return false;
}

/**
 * usage : afficher un texte codé
 * entrée : un vecteur de string qui représente le texte et une map de char et de string qui représente
 * le code de chaque caractère de l'alphabet
 *
 * description : affiche le texte codé
*/
void cryptage(vector<string>& texte, map<char, string>& code_alphabet) {
	cout << "\t RESULTAT DU CRYPTAGE" << endl;
	for(string ligne : texte) {
		for(size_t i = 0; i < ligne.size(); i++) {
			char c = ligne.at(i);
			if(code_alphabet[c] == "")
				continue;
			if(in(c, alphabet_latin))
				cout << code_alphabet[c];
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * usage : copier le texte codé dans un fichier texte
 * entrée : le fichier texte, un vecteur de string qui représente le texte à copier
 * et une map de char/string qui représente le code de chaque caractère de l'alphabet
 *
 * description : copie bit par bit le code du texte dans un fichier texte
*/
void copier_resultat_cryptage(fstream& fichier, vector<string>& texte, map<char, string>& code_alphabet) {
	for(string ligne : texte) {
		for(size_t i = 0; i < ligne.size(); i++) {
			char c = ligne.at(i);
			if(code_alphabet[c] == "")
				fichier << "";
			if(in(c, alphabet_latin))
				fichier << code_alphabet[c];
		}
		fichier << endl;
	}
	fichier << endl;
}

/**
 * usage : choisir le fichier texte sur lequel appliquer l'algorithme de décryptage du codage de huffman
 * retour : le nom du fichier
 *
 * description :
 * 		-propose à l'utilisateur d'entrer le nom d'un fichier texte
 * 		-retourne le nom du fichier entré par l'utilisateur
 * 
*/
string choisir_texte_a_decrypter() {
	string nom_fichier;
	cout << "Entrez le nom du fichier texte a decrypter : " << endl;
	cin >> nom_fichier;
	cout << endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return nom_fichier;
}

/**
 * usage : afficher un texte clair à partir d'un texte crypté
 * entrée : un vecteur de string qui représente le texte crypté et un arbre binaire généré par l'algorithme de huffman
 * qui représente le code de chaque caractère de l'alphabet
 *
 * description : affiche le texte clair décrypté
*/
void decryptage(vector<string>& texte_crypte, list<ArbreB*>& huffman) {
	cout << "\t RESULTAT DU DECRYPTAGE" << endl;
	for(string& ligne : texte_crypte) {
		ArbreB* tmp = huffman.front();
		for(size_t i = 0; i < ligne.size(); i++) {
			if(ligne[i] == '0')
				tmp = tmp->getDroite();
			if(ligne[i] == '1')
				tmp = tmp->getGauche();

			if(!tmp) {
				cerr << "\nLe code est inconnu" << endl;
				exit(2);
			}

			if(tmp->getSommet().getChar() == '\0' && i == (ligne.size()-1)) {
				cerr << "\nLe code est inconnu" << endl;
				exit(3);
			}

			if(tmp->getSommet().getChar() != '\0') {
				cout << tmp->getSommet().getChar();
				tmp = huffman.front();
			}
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * usage : copier le texte clair décrypté dans un fichier texte
 * entrée : le fichier texte, un vecteur de string qui représente le texte à décrypté
 * et un arbre binaire généré par l'algorithme de huffman qui représente le code de chaque caractère de l'alphabet
 *
 * description : décrypte bit par bit le code en parcourant l'arbre de huffman et copie le caractère du code parcouru
 * dans un fichier texte
*/
void copier_resultat_decryptage(fstream& fichier, vector<string>& texte_crypte, list<ArbreB*>& huffman) {
	for(string& ligne : texte_crypte) {
		ArbreB* tmp = huffman.front();
		for(size_t i = 0; i < ligne.size(); i++) {
			if(ligne[i] == '0')
				tmp = tmp->getDroite();
			if(ligne[i] == '1')
				tmp = tmp->getGauche();

			if(!tmp) {
				cerr << "\nLe code est inconnu" << endl;
				exit(4);
			}

			if(tmp->getSommet().getChar() == '\0' && i == (ligne.size()-1)) {
				cerr << "\nLe code est inconnu" << endl;
				exit(5);
			}

			if(tmp->getSommet().getChar() != '\0') {
				fichier << tmp->getSommet().getChar();
				tmp = huffman.front();
			}
		}
		fichier << endl;
	}
	fichier << endl;
}

/**
 * usage : prendre un texte et le coder avec l'algorithme de huffman
 *
 * description :
 * 		-ouvre le fichier de texte à crypter donné par l'utilisateur
 * 		-vérifie son ouverture
 * 		-copie le texte du fichier à crypter
 * 		-détermine la fréquence de chaque caractère dans le texte
 * 		-créé un sommet pour chaque caractère dans un vecteur
 * 		-trie le vecteur de sommet
 * 		-créé les feuilles de l'arbre d'huffman
 * 		-construit des pairs de feuilles en fonction de la fréquence du sommet
 * 		-construit l'arbre d'huffman en fonction de la fréquence de chaque caractère
 *	 	-code les caractères de l'alphabet avec l'arbre d'huffman
 *		-crypte le texte à crypter avec le code correspondant aux caractères dans un fichier
 * 		-affiche le code de chaque caractère de l'alphabet
 * 		-affiche l'arborescence de l'arbre d'huffman
 *		-affiche le texte du fichier a crypter
 *		-affiche le résultat du cryptage
 *		-ouvre le fichier de texte à décrypter donné par l'utilisateur
 *		-vérifie son ouverture
 *		-copie le texte du fichier à décrypter
 *		-affiche le texte à décrypter
 *		-décrypte le texte à décrypter à l'aide de l'arbre généré précédemment avec l'algorithme de huffman dans un fichier
 *		-affiche le résultat du décryptage
*/
void huffman() {
	string nom_fichier_a_crypter = choisir_texte_a_crypter();
	fstream fichier_a_crypter(nom_fichier_a_crypter.c_str(), ios::in);
	verification_fichier(fichier_a_crypter, nom_fichier_a_crypter);

	vector<string> texte_clair = copier_texte(fichier_a_crypter);
	map<char, int> frequence_alphabet;
	calculer_frequence_alphabet(texte_clair, frequence_alphabet);
	fichier_a_crypter.close();

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

	map<char, string> code_alphabet;
	codage_alphabet(huffman.front(), code_alphabet);
	afficher_code_alphabet(code_alphabet);
	afficher_arbres_arbo(huffman);
	afficher_texte(texte_clair);
	cryptage(texte_clair, code_alphabet);
	
	fstream fichier_resultat_cryptage("resultat_cryptage.txt", ios::out | ios::trunc);
	verification_fichier(fichier_resultat_cryptage, "resultat_cryptage.txt");
	copier_resultat_cryptage(fichier_resultat_cryptage, texte_clair, code_alphabet);
	fichier_resultat_cryptage.close();
	
	string nom_fichier_a_decrypter = choisir_texte_a_decrypter();
	fstream fichier_a_decrypter(nom_fichier_a_decrypter, ios::in);
	verification_fichier(fichier_a_decrypter, nom_fichier_a_decrypter);
	vector<string> texte_a_decrypter = copier_texte(fichier_a_decrypter);
	afficher_texte(texte_a_decrypter);
	decryptage(texte_a_decrypter, huffman);
	
	fstream fichier_resultat_decryptage("resultat_decryptage.txt", ios::out | ios::trunc);
	verification_fichier(fichier_resultat_decryptage, "resultat_decryptage.txt");
	copier_resultat_decryptage(fichier_resultat_decryptage, texte_a_decrypter, huffman);
	fichier_resultat_decryptage.close();
	fichier_a_decrypter.close();
}