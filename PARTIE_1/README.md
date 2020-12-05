*Auteurs : Dylan HARAL et Tinhinane BERKANI*

*Projet C++ : Cryptage et décryptage*

---

Note : N'ayant pas eu le temps de faire la partie sur l'interface graphique, on a essayé de faire un affichage propre sur la sortie standard, on fera de notre mieux dans la deuxieme et troisième partie du projet pour dévélopper l'interface graphique et faire un affichage.

# Programme
---
Le programme est répartie en 7 fichiers :

 * `main.cpp` : qui contient le programme principal.
 
 * `test.cpp` et `test.h` : qui contient une fonction de test. 
 
 * `Sommet.cpp` et `Sommet.h` : qui définisssent un noeud dans l'arbre binaire.
 
 * `ArbreB.cpp`et `ArbreB.h` : qui définissent un arbre binaire.
 
 * `Makefile` : qui permet de compiler tous les fichiers et d'exécuter le fichier exécutable `main`.

## main.cpp :
---
Le fichier `main.cpp` appelle la fonction `test` qui lance les tests des sommets et de l'arbre binaire et le programme principal.

## test.h et test.cpp :
---
Le fichier `test.cpp` definie la fonction `test` qui contient l'ensemble des tests des Sommet.h et ArbreB.h

## Sommet.h et Sommet.cpp : 
---
Le sommet d'un arbre binaire est représenté par la classe `Sommet` définie de la façon suivante :

 * Elle contient un caractère, représenté par une `lettre`. Ainsi que la fréquence de cette lettre, représentée par l'entier `freq`.

 * Elle possède 3 constructeurs : 
	- Un constructeur par défaut : qui initialise la lettre et la fréquence en mettant dans la lettre le caractère vide et dans l'entier fréquence 0.
	- Un constructeur par copie qui prend en argument un sommet et qui copie les valeurs de ce sommet.
	- Un constructeur par valeur dans lequel les attributs du sommet vont prendre les valeurs des arguments passés à ce constructeur.
 * Un destructeur.
 * Elle possède les deux méthodes `getChar` et `getFreq` qui retournent la `lettre` et la fréquence `freq` du sommet.
 * Elle possède les deux méthodes `setChar` et `setFreq` qui permettent de modifier la `lettre` et la frequence `freq` du sommet .
 * Elle possède cinq méthodes de surcharge d'opérateur: 
	- Une surcharge de l'opérateur `==` de comparaison, qui permet de vérifier si deux sommets sont égaux.
	- Une sucharge de l'opérateur `<`  et de l'opérateur `>` qui permettent de comparer un sommet à un autre en vérifiant respectivement si la lettre de chacun est plus petite ou plus grande de la lettre de l'autre sommet.
	- Deux méthodes de sucharge de l'opérateur `<<`. Le premier pour afficher un objet de type sommet. Le deuxième pour afficher un objet de type pointeur sur un sommet.

  Le fichier `Sommet.cpp` contient l'implémentation des méthodes de la classe `Sommet` : les valeurs que prendront les attributs du sommet sont initialisés dans les constructeurs avec une liste d'initialisation.
  Pour afficher les sommets, on affiche le caractère suivi de la fréquence de ce caractère.

## ArbreB.h et ArbreB.cpp :
---
L'arbre binaire est représenté par la classe `ArbreB` définie de la façon suivante :

 * Elle hérite de la classe `Sommet`.

 * Elle a 4 attributs : 
	- La `racine` de l'arbre de type sommet.
	- Un pointeur sur le sous-arbre droit `droite` de type `ArbreB*`.
	- Un pointeur sur le sous-arbre gauche `gauche` de type `ArbreB*`.
	- Un pointeur sur l'arbre précèdent `precedent` de type `ArbreB*`.
 * Elle a 4 constructeurs : 
	- Un constructeur par défaut : qui va utiliser le constructeur par défaut de la class Sommet pour la `racine` et qui va initialiser tous les pointeurs des arbres binaires à `NULL` 
	- un constructeur par référence qui prends en argument un sommet `s`. Dans celui-ci on donne à la racine la valeur du sommet donné en argument. Le sous-arbre `gauche` et `droite` seront `NULL` et le `precedent` sera l'arbre lui-même. On s'en sert uniquement pour créer un nouvel arbre dans le main. 
	- un constructeur par référence avec deux arguments. Le premier arguments est un sommet `s` et le deuxieme est un arbre binaire `A` qui représente l'arbre précédent.
	- un constructeur par recopie qui va créer un nouvel arbre identique à l'arbre donné en parametres en utilisant la méthode `copier` qui prends en parametres deux arbres , le premier sera l'arbre où on va copier , le deuxième est l'arbre que l'on veut copier. 
		-  Si l'abre que l'on veut copier est vide, on sort de la fonction , sinon on copie la `racine` en utilisant l'opérateur `=`.
		- Si on a un sous-arbre `gauche` dans l'arbre qu'on veut copier on crée un sous-arbre `gauche` dans l'arbre courant et pareil pour le sous-arbre `droite`.
		- Ensuite, pour chaque noeud dans l'arbre qu'on veut copier,on va stocker le `precedent` de ce noeud dans l'arbre courant.
 * Elle a un destructeur qui va supprimer le sous-arbre `gauche` et le sous-arbre `droit`.
 * Elle possède 4 méthodes: `getSommet`, `getDroite`, `getGauche`, `getPrecedent` qui retournent respectivement la `racine`, le sous-arbre `droite`, le sous-arbre `gauche` et le `precedent`.
 * Elle possède une méthode `ajouter`, qui ajoute un sommet dans l'arbre binaire.
	Cette méthode fonctionne comme ceci : 
	- Dans un premier lieu, on vérifie si l'arbre dans lequel on veut ajouter le sommet est vide.
		- si c'est le cas on crée un nouvel arbre avec comme racine le sommet qu'on veut ajouter et on retourne cet arbre.
		- sinon, on parcourt l'arbre et on vérifie si le sommet est plus petit ou plus grand que le sommet de l'arbre rencontré;
	- Si le sommet qu'on veut ajouter est plus petit que le sommet de l'arbre, on va à `gauche`.
	- Si le sommet qu'on veut ajouter est plus grand que le sommet de l'arbre, on va à `droite`.
	- On recommence jusqu'à ce qu'on arrive à un sommet vide.
	- Une fois le sommet trouvé, on détermine dans quelle partie on se trouve par rapport au sommet précédent; 
        - Si le sommet est plus petit que le sommet précédent, on va aller à au sous-arbre gauche du `precedent`.
        - Si le sommet est plus grand que le sommet précédent, on va aller à au sous-arbre droit du `precedent`.
    Une fois dans le sous-arbre gauche ou droit, on crée un nouvel arbre en utilisant le constructeur par valeur qui prends 2 arguments le sommet `s`et l'arbre `precedent`.
    - On retourne l'arbre modifié.
 * Elle possède une méthode `supprimer`, qui supprime un sommet dans l'arbre binaire.
   Cette méthode fonctionne comme ceci : 
	- Elle prend en paramètre un seul argument qui est le sommet qu'on veut supprimer.
	- On vérifie si l'arbre est vide, si c'est le cas, on retourne l'arbre vide.
	- Si ce n'est pas le cas, on parcourt l'arbre toujours en comparant le sommet qu'on veut supprimer avec les sommets de l'arbre. Dés que l'on a trouvé le sommet, on sort de la boucle `while` qui parcourt l'arbre et on vérifie que `tmp` (le pointeur avec lequel on parcourt) est bien différent de `NULL`. 
        - Si c'est le cas cela veut dire qu'il aura parcouru tout l'arbre et qu'il n'a pas trouvé le sommet que l'on veut supprimer. On retourne l'arbre non modifié.
        - Sinon on a trouvé le sommet et on le compare à son précédent pour voir de quel coté il se trouve par rapport à lui.
           - S'il est plus petit on va à gauche.
           - S'il est plus grand on va à droite.
	- A ce stade, on a notre sommet à supprimer qui se trouve soit à gauche, soit à droite. Dans les deux cas, 3 possibilités s'offrent à nous.
        - Le sommet qu'on veut supprimer n'a aucun sous arbre, dans ce cas on supprime ce sommet et on retourne l'arbre sans le sommet.
        - Le sommet qu'on veut supprimer a un fils : soit un sous arbre gauche, soit un sous arbre droit, dans ce cas on supprime le sommet et on relie le sous arbre gauche ou droit au précédent du sommet qu'on a supprimé.
        - Le cas où le sommet qu'on veut supprimer a deux fils : un sous-arbre `gauche` et un sous-arbre `droit` : Dans ce cas on a fait deux fonctions `max` et `min` :
          - `max` retourne la valeur maximum d'un arbre binaire en prenant en parametre l'arbre et en se déplaçant dans celui-ci vers le sous-arbre `droit`jusqu'à arriver à la fin et au dernier sommet dans l'arbre, elle retournera celui-ci.
          - `min` retourne la valeur minimum d'un arbre binaire de la même manière que `max` mais en se déplacant dans l'arbre vers le sous-arbre `gauche`.
        On s'est servi de ces deux fonctions de la façon suivante :
        - On détermine la valeur max du sous arbre gauche,on regarde si le sommet max a lui même un fils ou 0 : 
        	- S'il a un fils, le sommet précédent de `max` sera relié au fils de `max`.
        	- S'il en a pas, le précédent de `max` sera relié à `NULL`.
        Le précédent de la valeur qu'on veut supprimer sera relié à cette étape à valeur `max`.
        Comme le sommet à supprimer a deux fils, les sous-arbres de la valeur `max` vont être reliés respectivement au sommet que l'on veut supprimer.
        - On supprime le sommet.
        - On retourne l'arbre dans lequel le sommet a été supprimé.
 * Elle possède une fonction `rechercher` qui prends en paramètres un sommet que l'on veut rechercher. Elle parcourt l'arbre dans le quel on veut le chercher en vérifiant d'abord si ce n'est pas la racine puis elle le cherche dans le sous-arbre `gauche` et `droite` et le renvoie s'il y est.
 * Elle possède une méthode `décomposer`, qui décomposse l'arbre en deux arbres distincts.
   Elle prends en parametres 3 arguments ; le sous-arbre `gauche` de l'arbre,le sous-arbre `droit` de l'arbre, l'arbre en lui-même.
   Elle vérifie si l'arbre est vide ou pas , s'il est vide on sort de la fonction.
   Dans le cas contraire, on va utiliser deux autres fonctions qui sont `ajouterGauche` et `ajouterDroite` qui sont des fonctions récursives et qui vont ajouter dans tout le sous-arbre `gauche` ou `droite` respectivement de l'arbre qu'on veut décomposer dans les arbres passées en parametres. Ces fonctions font appel à la méthode `ajouter`.
 * Elle possède une méthode `modifier` qui prends en paramètres 3 argumets;le sommet à modifier, les valeurs de chacune de lettre et fréquence à mettre dans le sommet à modifier. Elle parcourt l'arbre en cherchant le sommet à modifier donné en paramètres, et une fois trouvé, elle utilise les méthodes `setChar` et `setFreq` pour le modifier et le renvoyer. Si elle ne le trouve pas, elle retourne l'arbre non modifié.
 * Elle possède une méthode `fusion`, qui fusionnne deux arbres en un unique arbre binaire :
   Cette fonction prend en parametre l'arbre à ajouter dans l'arbre qui appellent la méthode.
   Si l'arbre que l'on veut ajouter est `NULL`, on retourne l'arbre courant, si ce n'est pas le cas on va ajouter la racine aprés un sommet à un autre récursivement.
   Cette fonction retourne l'arbre courant qui sera donc la fusion de deux arbres.
* Elle possède une méthode ` afficher` qui affiche l'arbre de manière infixe.
* Elle possède une méthode `print_t`, qui affiche l'arbre de manière arborecente. C'est une fonction récursive qui prend en paramètre la `hauteur`, un entier qui déterminera le côté droit ou gauche de l'arbre et une référence sur l'arbre à afficher.
* Elle possède une méthode `hauteur`, qui calcule la hauteur d'un arbre récursivement, en comparant la hauteur du sous-arbre gauche et sous-arbre droit et en renvoyant le maximum des deux. 
* Elle possède une méthode `nombre_element`, qui calcule le nombre de sommet d'un arbre binaire en vérifiant d'abord si l'arbre est vide, dans ce cas, elle renvoie 0, sinon, elle ajoute un au résultat finale et rapelle la fonction sur le sous-arbre gauche et le sous-arbre droit.

## Compilation du projet
---
Pour compiler le projet, il vous suffit d'exécuter la commande :
```bash
$ make project
```
Une fois cette commande effectuée, et si tout c'est bien déroulé, les fichiers intermédiaires **(.o)** du projet sont générés dans le répertoire local `obj/` et un fichier exécutable `main` est généré dans le repertoire local `bin/`.

## Exécution du programme
---
Pour exécuter le programme du projet, il suffit de taper `./bin/main` dans le terminal.

## Suppression projet
---
Pour supprimer tous les fichiers générés ainsi que l'exécutable, vous pouvez utiliser la commande `make clean_project`, ou simplement `make clean`, qui supprimera tous.

---
---

# Qt
---

## Prérequis pour Qt
---
Pour construire le `build` Qt du projet, il vous faut disposer de la library **Qt5** et de **Cmake** *(version minimale 3.0.0)*.

Si vous ne disposez pas de la library Qt5, veuillez l'installer via le site officiel, à l'URL suivante :
https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4.
>*Ǹote : une fois le fichier téléchargé, il vous faut donner l'accès pour que vous puissiez exécuter le fichier.
>Faites clic-droit sur le fichier, allez dans Priopriété, puis "Autoriser l'exécution du programme".*

Si vous ne disposez pas de Cmake, veuillez l'installer via le site officiel, à l'URL suivante :
https://cmake.org/download/

Veuillez également installez les `packages` suivant :
 * `qtbase5-dev`
 * `qtdeclarative5-dev`
    
Si vous utilisez une distibution Linux, dérivant de Débian ou Ubuntu, la commande de base est la suivante :
```bash
$ sudo apt-get install <nom-du-package>
```

## Création et compilation du build
---
Pour construire le build Qt du projet, puis le compiler, il vous suffit d'exécuter la commande :
```bash
$ make qt_build
```
Une fois cette commande effectuée, et si tout c'est bien déroulé, le build du projet et un Makefile correspondant sont générés dans le repertoire local `build/` dans un premier temps. Puis, dans un deuxième temps, un fichier exécutable `Main` est généré.

## Exécution du programme Qt
---
Pour exécuter le programme du projet, il suffit de taper `./build/Main` dans le terminal.

## Suppression du build
---
Pour supprimer le build, ainsi que tous les fichiers générés, vous pouvez utiliser la commande `make clean_qt_build`, ou simplement `make clean`, qui supprimera tous.
