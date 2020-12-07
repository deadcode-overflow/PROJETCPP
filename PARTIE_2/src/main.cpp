#include "../inc/huffman.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

int main(void) {

	string file_name;
	cout << "Entrez le nom du fichier texte : " << endl;
	cin >> file_name;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	fstream file(file_name.c_str(), ios::in);
	if(file.is_open()) {
		char alphabet_latin[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		int freq;

		vector<string> decrypt_txt; 
		string line;
		while(getline(file, line)) {
			decrypt_txt.push_back(line);
		}
		
		for(int i = 0; i < 26; i++) {
			for(string texte : decrypt_txt) {
				freq += calcul_freq(alphabet_latin[i], texte);
			}
			cout << alphabet_latin[i] << " : " << freq << endl;
			freq = 0;
		}	
			
		for(string texte : decrypt_txt) {
			cout << texte << endl;
		}


	}
	else {
		cerr << "Erreur: lors de l\'ouverture du fichier " << file_name << "." << endl;
		exit(2);
	}
	


	return 0;
}