#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "../inc/ArbreB.h"
#include "../inc/Sommet.h"
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

string choisir_texte();
void verification_fichier(fstream& fichier, string nom);
vector<string> copier_texte(fstream& fichier);
void calculer_frequence_alphabet(vector<string>& texte, map<char, int>& frequence_alphabet);
void afficher_texte(vector<string>& texte);
void creer_sommets(vector<Sommet>& sommets, map<char, int>& frequence_alphabet);
int comparaison_sommets(Sommet& a,Sommet& b);
void afficher_arbres_infixe(list<ArbreB*>& arbres);
void afficher_arbres_arbo(list<ArbreB*>& arbres);
void codage_alphabet(ArbreB* A, map<char, string>& code_alphabet);
void afficher_code_alphabet(map<char, string>& code_alphabet);
void afficher_texte_code(vector<string>& texte, map<char, string>& code_alphabet);
void copier_resultat(fstream& fichier, vector<string>& texte, map<char, string>& code_alphabet);
void decryptage(vector<string>& texte_crypte, list<ArbreB*>& huffman);
void huffman();
#endif