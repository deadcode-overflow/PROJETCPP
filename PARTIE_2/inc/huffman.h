#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

string choisir_texte();
void verification_fichier(fstream& fichier, string nom);
vector<string> copier_texte(fstream& fichier);
void calculer_frequence_alphabet(vector<string>& texte, map<char, int>& frequence_alphabet);
void afficher_frequence_alphabet(map<char, int>& frequence_alphabet);
void afficher_texte(vector<string>& texte);
void creer_sommets(vector<Sommet>& sommets, map<char, int>& frequence_alphabet);
int comparaison_sommets(Sommet& a,Sommet& b);
void afficher_sommets(vector<Sommet>& sommets);
void afficher_arbres_infixe(vector<ArbreB*>& arbres);
void afficher_arbres_arbo(vector<ArbreB*>& arbres);
double taille_(vector<ArbreB>& feuilles);
void creer_arbres(ArbreB* huffman, vector<ArbreB>& feuilles);
#endif