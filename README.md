*Auteurs : Dylan HARAL et Tinhinane BERKANI*
*Projet C++ : Cryptage et décryptage*

---

# Programme
---

Le programme est répartie en 6 fichiers :

 * `main.cpp` : qui contient le programme principal.
 
 * `Sommet.cpp` et `Sommet.h` : qui définisssent un noeud dans l'arbre binaire
 
 * `ArbreB.cpp`et `ArbreB.h` : qui définissent un arbre binaire
 
 * `Makefile` : qui permet de compiler tous les fichiers et d'executer le fichier executable `main`.

## main.cpp :

Le fichier `main.cpp` contient la fonctinon main et le programme principal.

## Sommet.h et Sommet.h :

Le sommet d'un arbre binaire est représenté par la classe `Sommet` définie de la façon suivante :

 * elle contient un caractère, représenté par une `lettre`. Ainsi que la fréquence de cette lettre, représentée par l'entier `freq`.
 
 * elle possède 4 constructeurs. Un constructeur par défaut, un constructeur par copie qui prend en argument un autre sommet, un constructeur qui prend en argument un pointeur vers un sommet et un constructeur, où la lettre et la fréquence sont données explicitement dans l'argument de ce constructeur.

 * elle possède deux méthodes de surcharge d'opérateur. Une surcharge de l'opérateur `==`, qui permet de comparer si deux sommets sont égaux et une sucharge de l'opérateur `<<` , qui permet d'afficher un sommet.

 * elle possède deux getters, qui retournent la lettre et la fréquence.

## ArbreB.h et ArbreB.cpp :

L'arbre binaire est représenté par la classe `ArbreB` définie de la façon suivante :

 * elle hérite de la classe `Sommet`.

 * elle contient un pointeur vers un sommet noté `racine`, ainsi qu'un pointeur vers le sommet précèdent noté `parent`.

 * elle contient deux pointeurs, un pointeur vers le sous arbre droit noté `droite`, ainsi qu'un pointeur vers le sous arbre gauche noté `gauche`.

 * elle possède 4 constructeurs. Un constructeur par défaut, un constructeur qui prend en paramètre uniquement un sommmet, un constructeur qui prend en paramètre un sommet et son parent et un constructeur qui prend en paramètre un sommet, son parent et les sous arbre gauche et droit.

 * elle possède une méthode de surcharge de l'opérateur `<<`, qui permet d'afficher l'arbre binaire. 

 * elle possède deux getters, qui retournent la racine de l'arbre et le parent de cette racine.

 * elle possède une méthode `ajouter`, qui ajoute un sommet dans l'arbre binaire.

 * elle possède une méthode `supprimer`, qui supprime un sommet dans l'arbre binaire.

 * elle possède une méthode `décomposser`, qui décomposse l'arbre en deux arbres distincts.

 * elle possède une méthode `fusion`, qui fusionnne deux arbres en un unique arbre binaire.

 * elle possède une méthode `supprimerArbre` qui permet de supprimer l'ensemble de l'arbre binaire.