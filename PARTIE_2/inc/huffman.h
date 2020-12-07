#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <vector>

using namespace std;

string choisir_texte();
void verification_fichier(fstream& file, string name);
vector<string> copier_texte(fstream& file);
int calcul_freq(char c, string s);
void afficher_frequence_alphabet(vector<string> texte);
void afficher_texte(vector<string> texte);

#endif