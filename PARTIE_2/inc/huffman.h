#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <vector>

using namespace std;

string choisir_texte();
void verification_fichier(fstream& fichier, string nom);
vector<string> copier_texte(fstream& fichier);
void calculer_frequence_alphabet(vector<string> texte, map<char, int>& frequence_alphabet);
void afficher_frequence_alphabet(map<char, int> frequence_alphabet);
void afficher_texte(vector<string> texte);

#endif