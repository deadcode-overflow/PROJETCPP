#include <iostream>
#include "Sommet.h"
#include "ArbreB.h"

using namespace std;

int main() {

	Sommet s('A', 1);
	Sommet s2('B', 2);
	Sommet s3('C', 1);
	Sommet s4('D', 3);
	Sommet s5('E', 4);
	Sommet s6('F', 2);

    cout << "sommet 1 : " << s.getChar() << " " << s.getFreq()  << endl;

    ArbreB A1(s);

    cout << "racine de l'arbre : "<< A1.getSommet()->getChar() << " " << A1.getSommet()->getFreq() << endl;
	
	cout << "............B2..............." << endl;
	cout << "dans le ajouter sommet - 1" << endl;
    A1.ajouter(s2, &A1, &A1);
    cout << "............C1..............." << endl;
    cout << "dans le ajouter sommet - 2" << endl;
    A1.ajouter(s3, &A1, &A1);
    cout << "............D3..............." << endl;
    cout << "dans le ajouter sommet - 3" << endl;
    A1.ajouter(s4, &A1,  &A1);
    cout << "............E4..............." << endl;
    cout << "dans le ajouter sommet - 4" << endl;
    A1.ajouter(s5, &A1, &A1);
	cout << "............F2..............." << endl;
    cout << "dans le ajouter sommet - 5" << endl;
    A1.ajouter(s6, &A1, &A1);
    cout << "..........................." << endl;

    cout << "parent-enfant" << endl;
    A1.afficher(&A1);
    A1.supprimerArbre(&A1);

    return 0;
}