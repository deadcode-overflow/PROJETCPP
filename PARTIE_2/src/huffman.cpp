#include "../inc/huffman.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int calcul_freq(char c, string s) {
    int freq = 0;
	string::size_type i;
	for(i = 0; i < s.size(); i++) {
		if(s[i] == c)
			freq++;
		else if(s[i]-32 == c)
			freq++;
	}
	return freq;
}
