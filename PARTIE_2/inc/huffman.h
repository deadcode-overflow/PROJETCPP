#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "../inc/Sommet.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

string choisir_texte();
void verification_fichier(fstream& fichier, string nom);
vector<string> copier_texte(fstream& fichier);
void calculer_frequence_alphabet(vector<string> texte, map<char, int>& frequence_alphabet);
void afficher_frequence_alphabet(map<char, int> frequence_alphabet);
void afficher_texte(vector<string> texte);
void creer_sommet(vector<Sommet>& sommets, map<char, int> frequence_alphabet);
void afficher_sommets(vector<Sommet> sommets);

#endif