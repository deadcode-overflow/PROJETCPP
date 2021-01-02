*Auteurs : Dylan HARAL et Tinhinane BERKANI*

 *Projet C++ : Cryptage et décryptage*

 ---

 # Programme
 ---
 Le programme est répartie en 4 dossiers :

  * `src/` : qui contient les fichiers sources **(.cpp)** du projet.

  * `inc/` : qui contient les fichiers d'en-tête **(.h)** du projet. 

  * `obj/` : qui une fois compilé, contient les fichiers intermédiares **(.o)** du projet.

  * `bin/` : qui une fois compilé, contient le fichier exécutable `main.exe`.

 Le programme est répartie en 12 fichiers :

  * `main.cpp` : qui contient le programme principal.

  * `huffman.cpp` et `huffman.h` : qui contiennent les fonctions de codages de Huffman et de lecture d'un fichier texte. 

  * `Sommet.cpp` et `Sommet.h` : qui définisssent un noeud dans l'arbre binaire de la partie 1.

  * `ArbreB.cpp`et `ArbreB.h` : qui définissent un arbre binaire de la partie 1.

  * `texte.txt` : qui est le fichier de texte qui contient le texte sur lequel on test le codage de Huffman.

  * `resultat_cryptage.txt` : qui est le résultat du cryptage du texte sur lequel on test le codage de Huffman.

  * `resultat_decryptage.txt` : qui est le résultat du décryptage du texte crypté donné par l'utilisateur.

  * `code.txt` : qui est le fichier de texte qui contient un code crypté par défaut et sur lequel on peut tester le décryptage après avoir effectuer le codage de Huffman sur le fichier `texte.txt`.

  * `Makefile` : qui permet de générer tous les fichiers et dossiers du projet.

 ## Compilation du projet
 ---
 Pour compiler le projet, il vous suffit d'exécuter la commande :
 ```bash
 $ make
 ```
 Une fois cette commande effectuée, et si tout c'est bien déroulé, les fichiers intermédiaires **(.o)** du projet sont générés dans le répertoire local `obj/` et un fichier exécutable `main.exe` est généré dans le repertoire local `bin/`.

 ## Exécution du programme
 ---
 Pour exécuter le programme du projet, il vous suffit de taper `./bin/main.exe` dans le terminal.
 
 Entrez le fichier de test à crypter `texte.txt`, pour tester le cryptage.
 Une fois le cryptage terminé, un fichier `resultat_cryptage.txt` est créé. Il contient le résultat du cryptage du fichier de texte sélectionné.

 Entrez un fichier à décrypter. *(Vous pouvez utiliser `résultat_cryptage.txt` pour vérifier que le décryptage du fichier crypté s'effectue correctement. Ou alors vous pouvez entrer `code.txt` pour vérifier que le décryptage d'un code inconnu n'est pas reconnu par le programme.)*

 ## Suppression du projet
 ---
 Pour supprimer tous les fichiers générés ainsi que l'exécutable, vous pouvez utiliser la commande `make clean`.

 ## main.cpp :
 ---
 Le fichier `main.cpp` appelle la fonction `huffman` qui lance le programme principal.

  ## huffman.h et huffman.cpp :
 ---
 Le fichier `huffman.cpp` definie la fonction `huffman` qui contient les fonctions qui permettent de `crypter` et `decrypter` un fichier texte donné par l'utilisateur et de créer l'arbre d'Huffman.

 Le programme est divisé en x fonctions.

  * `choisir_texte_a_crypter()` est une fonction qui permet à l'utilisateur de choir un fichier texte sur lequel appliquer le cryptage à l'aide de l'algorithme de Huffman. Elle retourne le nom du fichier texte.

  * `verification_fichier` est une fonction qui permet de vérifier si un fichier est correctement ouvert ou non. S'il n'est pas ouvert, la fonction relève une erreur et sort du programme. Elle prend en paramètre le fichier ainsi que le non de ce fichier.

  * `copier_texte` est une fonction qui permet de copier le contenu d'un fichier texte dans un vecteur de `string`. Elle prend en paramètre le fichier et le vecteur dans lequel copier le contenu du fichier. La copie du fichier se fait ligne par ligne.

  * `calculer_frequence_alphabet` est une fonction qui permet de calculer la fréquence d'un caractère dans un texte. Elle utilise pour cela la fonction `calcul_freq` qui retourne le nombre d'occurence d'un caractère dans une ligne. On utilise cette fonction avec un caractère pour chaque ligne du texte. De cette manière on a le nombre d'occurence d'un caractère dans un texte. On sauvegarde ensuite le résultat dans une `map`.
  A la fin de cette fonction chaque caractère du texte est associé à une fréquence contenu dans la `map`.

  * `afficher_texte` est une fonction qui affiche le contenu d'un texte. Elle prend en paramètre un vecteur de `string`.

  * `creer_sommets` est une fonction qui créée un `Sommet` pour chaque caractère du texte avec sa fréquence. Ces sommet seront contenu dans un vecteur. Elle prend en paramètre la `map` et un vecteur de `Sommet`.

  * `comparaison_sommet` est une fonction qui permet de spécifier la manière dont la fonction `std::sort` trie les sommets du vecteur de sommet. On trie les sommets en fonction de la fréquence du caractère qu'elles contiennent. Dans tous les cas, le premier sommet sera considéré plus petit que le deuxième.
  
  * `afficher_arbres_infixe` est une fonction qui permet d'afficher de manière infixe une liste d'arbre binaire `ArbreB`. Elle utilise la méthode `affichage_infixe` de `ArbreB` et elle prend en paramètre une liste d'arbre bainaire.

  * `afficher_arbres_arbo` est une fonction qui permet d'afficher de manière arborescente une liste d'arbre binaire `ArbreB`. Elle utilise la méthode `afficher_arbo` de `ArbreB` et elle prend en paramètre une liste d'arbre bainaire.

  * `codage_alphabet` est une fonction qui détermine le code pour chaque caractère du texte à l'aide de l'arbre de Huffman et qui sauvegarde le résultat dans une `map`. Elle utilise la fonction `code_lettre` qui fonctionne de la manière suivante :
    - Le `code` est représenté par un `string`.
    - On parcourt récursivement l'arbre généré par l'algorithme de Huffman pour chaque caractère du texte.
    - Lorsque l'on se déplace dans le sous-arbre gauche, on ajoute 1 au `string`.
    - Lorsque l'on se déplace dans le sous-arbre droit, on ajoute 0 au `string`.
    - Une fois le caractère trouvé on retourne le `code` en concatenant le code avec un autre `string` vide.
  
    Le résultat est ensuite stocké dans la `map`.
  
  * `afficher_code_alphabet` est une fonction qui permet d'afficher le code généré pour chaque caractère du texte. Elle prend en paramètre la `map`

  * `cryptage` est une fonction qui permet de crypter un texte à l'aide de la `map` de codage. Elle prend en paramètre un vecteur de `string` et la `map`.
  Elle fonctionne de la manière suivante :
    - pour chaque caractère lu dans le texte, on regarde dans la map le codage correspondant.
    - On affiche le codage correspondant.

  * `copier_resultat_cryptage` est une fonction qui fonctionne de la même manière que la fonction `cryptage`, sauf qu'elle écrit le codage correspondant dans un fichier texte nommé `resultat_cryptage.txt` au lieu de l'afficher.

  * `choisir_texte_a_decrypter()` est une fonction qui permet à l'utilisateur de choir un fichier texte sur lequel appliquer le décryptage à l'aide de l'arbre de Huffman. Elle retourne le nom du fichier texte.

  * `decryptage` est une fonction qui permet de décrypter un texte à l'aide de la `map` de l'arbre généré par l'algorithme de Huffman. Elle prend en paramètre un vecteur de `string` et la liste d'arbre binaire.
  Elle fonctionne de la manière suivante :
    - pour chaque bit lu dans le texte, on parcours l'arbre bianire.
      - Lorsque l'on lit un bit 1, on se déplace dans le sous-arbre gauche.
      - Lorsque l'on lit un bit 0, on se déplace dans le sous-arbre droit.
      - Une fois le caractère trouvé, on retourne à la `racine` de l'arbre binaire.
      - Si le caractère n'est pas trouvé, on arrète le décryptage et on sort du programme.
    - On affiche le caractère trouvé dans l'arbre.

  * `copier_resultat_decryptage` est une fonction qui fonctionne de la même manière que la fonction `decryptage`, sauf qu'elle écrit le caractère trouvé dans un fichier texte nommé `resultat_decryptage.txt` au lieu de l'afficher.

  * `huffman` est une fonction qui regroupe toute les fonctions precedentes et qui construit l'arbre de Huffman.

 ## Sommet.h et Sommet.cpp : 
 ---
 Le sommet d'un arbre binaire est représenté par la classe `Sommet` définie de la façon suivante :

  * Elle contient un caractère `lettre`. Ainsi que la fréquence de ce caractère, représentée par l'entier `freq`.

  * Elle possède 3 constructeurs : 
    - Un constructeur par défaut qui initialise le caractère à vide et la fréquence à 0.
    - Un constructeur par copie qui prend en argument un autre sommet et qui copie les valeurs de ce sommet.
    - Un constructeur par valeur dans lequel les attributs du sommet vont prendre les valeurs des arguments passés en paramètre.
  * Elle possède un destructeur.
  * Elle possède les deux méthodes `getChar` et `getFreq` qui retournent la `lettre` et la fréquence `freq` du sommet.
  * Elle possède les deux méthodes `setChar` et `setFreq` qui permettent de modifier la `lettre` et la fréquence `freq` du sommet.
  * Elle possède six méthodes de surcharge d'opérateur: 
    - Une surcharge de l'opérateur `==` de comparaison, qui permet de vérifier si deux sommets sont égaux.
    - Une sucharge de l'opérateur `<`  et une autre de l'opérateur `>` qui permettent de comparer un sommet à un autre, en vérifiant respectivement si le caractère du sommet placé a gauche de l'opérateur est plus petit ou plus grand que le sommet avec lequel il est comparé.
    - Deux méthodes de sucharge de l'opérateur `<<`. Le premier pour afficher un objet de type `Sommet`. Le deuxième pour afficher un objet de type pointeur sur un `Sommet`.

   Le fichier `Sommet.cpp` contient l'implémentation des méthodes de la classe `Sommet` : les valeurs que prendront les attributs du sommet sont initialisés dans les constructeurs avec une liste d'initialisation.
   Pour afficher les sommets, on affiche le caractère suivi de la fréquence de ce caractère.

 ## ArbreB.h et ArbreB.cpp :
 ---
 L'arbre binaire est représenté par la classe `ArbreB` définie de la façon suivante :

  * Elle hérite de la classe `Sommet`.

  * Elle contient 4 attributs :
    - La `racine` de l'arbre qui est un sommet.
    - Un pointeur sur le sous-arbre droit `droite`.
    - Un pointeur sur le sous-arbre gauche `gauche`.
    - Un pointeur sur la `racine` de l'arbre précèdent `precedent`.

  * Elle possède 4 constructeurs :

    - Un constructeur par défaut qui va utiliser le constructeur par défaut de la classe `Sommet` pour initialiser la `racine` et qui va initialiser tous les pointeurs de l'arbre binaire à `NULL`.
    - un constructeur par référence qui prends en argument un sommet. La `racine` prend la valeur du sommet donné en argument de fonction. Le sous-arbre gauche et droit sont initialisés à `NULL` et le `precedent` est la racine de l'arbre lui-même. On s'en sert uniquement pour créer un nouvel arbre dans le `main`.
    - un constructeur par référence avec deux arguments. Le premier arguments est un sommet et le deuxieme est un arbre binaire qui représente la `racine` de l'arbre `precedent`.
    - un constructeur par recopie qui va créer un nouvel arbre identique à l'arbre donné en paramètre en utilisant la méthode `copier` qui prends en paramètres deux arbres, le premier sera l'arbre où dans lequel on va copier, le deuxième est l'arbre que l'on veut copier.
      -  Si l'abre que l'on veut copier est vide, on sort de la fonction, sinon on copie la `racine` en utilisant l'opérateur `=`.
      - Si on a un sous-arbre gauche dans l'arbre qu'on veut copier, on créé un sous-arbre gauche dans l'arbre courant. On procède de la même manière pour le sous-arbre droit.
      - Ensuite, pour chaque sommet de l'arbre que l'on veut copier, on va stocker le `precedent` de ce sommet dans l'arbre courant.
  * Elle possède un destructeur qui va supprimer le sous-arbre gauche et le sous-arbre droit.
  * Elle possède 4 méthodes : `getSommet`, `getDroite`, `getGauche`, `getPrecedent` qui retournent respectivement la `racine`, le sous-arbre droit, le sous-arbre gauche et le `precedent`.
  * Elle possède une méthode `ajouter`, qui ajoute un sommet dans l'arbre binaire.
  Cette méthode fonctionne comme ceci : 
    - Dans un premier lieu, on vérifie si l'arbre dans lequel on veut ajouter le sommet est vide.
      - si c'est le cas on crée un nouvel arbre avec comme racine le sommet qu'on veut ajouter et on retourne cet arbre.
      - sinon, on parcourt l'arbre et on vérifie si le sommet est plus petit ou plus grand que le sommet de l'arbre rencontré.
    - Si le sommet que l'on veut ajouter est plus petit que le sommet de l'arbre, on va à `gauche`.
    - Si le sommet que l'on veut ajouter est plus grand que le sommet de l'arbre, on va à `droite`.
    - On recommence jusqu'à ce qu'on arrive à un sommet vide.
    - Une fois le sommet trouvé, on détermine dans quelle partie l'on se trouve par rapport au sommet précédent.
      - Si le sommet est plus petit que le sommet précédent, on va aller au sous-arbre gauche de l'arbre `precedent`.
      - Si le sommet est plus grand que le sommet précédent, on va aller au sous-arbre droit de l'arbre`precedent`.
    - Une fois dans le sous-arbre gauche ou droit, on crée un nouvel arbre en utilisant le constructeur par valeur qui prends 2 arguments le sommet et la racine de l'arbre `precedent`.
    - On retourne l'arbre modifié.
  * Elle possède une méthode `supprimer`, qui supprime un sommet dans l'arbre binaire.
    Cette méthode fonctionne comme ceci :
    - Elle prend en paramètre un seul argument qui est le sommet que l'on veut supprimer.
    - On vérifie si l'arbre est vide, si c'est le cas, on retourne l'arbre vide.
    - Si ce n'est pas le cas, on parcourt l'arbre toujours en comparant le sommet que l'on veut supprimer avec les sommets de l'arbre. Dés que l'on a trouvé le sommet, on sort de la boucle `while` qui parcourt l'arbre et on vérifie que `tmp` (le pointeur avec lequel on parcourt l'arbre) est différent de `NULL`.
      - Si c'est le cas, cela veut dire que l'on a parcouru tout l'arbre et qu'il n'a pas trouvé le sommet que l'on veut supprimer.
        - On retourne l'arbre non modifié.
      - Sinon, cela veut dire que l'on a trouvé le sommet que l'on veut supprimer.
        - On le compare au sommet de l'arbre précédent pour voir de quel coté on se trouve par rapport à lui.
          - S'il est plus petit, on est à gauche.
          - S'il est plus grand, on est à droite.
    - A ce stade, on a notre sommet à supprimer qui se trouve soit à gauche, soit à droite. Dans les deux cas, 3 possibilités s'offrent à nous :
      - Le sommet que l'on veut supprimer n'a aucun sous-arbres. Dans ce cas, on supprime ce sommet et on retourne l'arbre avec le sommet supprimé.
      - Le sommet que l'on veut supprimer a un fils : soit un sous arbre gauche, soit un sous arbre droit. Dans ce cas, on supprime le sommet et on relie le sous-arbre gauche ou droit à la racine de l'arbre `precedent` du sommet que l'on a supprimé.
      - Le sommet que l'on veut supprimer a deux fils : un sous-arbre gauche et un sous-arbre droit. Dans ce cas, on utilise deux fonctions `max` ou `min` :
        - `max` retourne la valeur maximum d'un arbre binaire en prenant en paramètre l'arbre binaire. On se déplaçe dans celui-ci vers le sous-arbre `droit` jusqu'à arriver à un sommet qui n'a pas de sous-arbre `droit`. Elle retourne ensuite ce sommet.
        - `min` retourne la valeur minimum d'un arbre binaire de la même manière que `max` mais en se déplacant dans l'arbre vers le sous-arbre `gauche`.
      - On détermine la valeur `max` du sous-arbre gauche. On regarde si le sommet `max` a un fils ou 0 : 
        - S'il a un fils, le fils gauche de la `racine` de l'arbre `precedent` du sommet `max` sera relié à la `racine` de l'arbre du fils de `max`.
        - S'il n'en a pas, le fils gauche de la `racine` de l'arbre `precedent` du sommet `max` sera relié à `NULL`.
      - Le `racine` de l'arbre `precedent` de la valeur que l'on veut supprimer, sera reliée au sommet `max`.
      - Comme le sommet à supprimer a deux fils, les sous-arbres gauche et droit du sommet `max` vont être reliés respectivement au sous-arbre gauche et droit du sommet que l'on veut supprimer.
      - On met tous les pointeurs du sommet que l'on veut supprimer à `NULL`.
      - On supprime le sommet que l'on veut supprimer.
      - On retourne l'arbre avec le sommet supprimé.
  * Elle possède une fonction `rechercher` qui prend en paramètre le sommet que l'on veut rechercher.    
    - Elle parcourt l'arbre dans lequel on veut chercher le sommet.
    - On vérifie d'abord si le sommet que l'on veut rechercher, n'est pas la racine de l'arbre.
    - Si ce n'est pas le cas, on recherche ce sommet dans le sous-arbre gauche et droite.
    - On retourne le sommet trouvé si il ce trouve dans l'arbre.
    - Sinon on retourne, un sommet vide.
  * Elle possède une méthode `decomposer`, qui décomposse l'arbre en deux arbres distincts.
    - Elle prends en parametres 3 arguments : le sous-arbre gauche, le sous-arbre droit et la `racine` de l'arbre.
    - Elle vérifie si l'arbre est vide. S'il est vide, on sort de la fonction il n'y rien a `decomposer`.
    - Dans le cas contraire, on utilise deux autres fonctions qui sont `recupererGauche` et `recupererDroite` qui sont des fonctions récursives et qui vont recuperer le sous-arbre gauche ou droite en ajoutant dans un nouvel arbre le sous-arbre gauche et droit de l'arbre que l'on veut décomposer. `recupererGauche` et `recupererDroite` font appels à la méthode `ajouter`.
  * Elle possède une méthode `modifier`, qui prends en paramètres 3 argumets : le sommet à modifier, les valeurs du caractère et de la fréquence.
    - Elle parcourt l'arbre en cherchant le sommet à modifier donné en paramètres.
    - Si le sommet est trouvé, on utilise les méthodes `setChar` et `setFreq` pour le modifier les attribut du sommet à modifier. On l'arbre avec le sommet modifié.
    - Si le sommet n'est pas trouvé, on retourne l'arbre non modifié.
  * Elle possède une méthode `fusionner`, qui fusionnne deux arbres en un unique arbre binaire. Le résultat de la fusion est l'un des deux arbres fusionnés.
    - Cette fonction prend en paramètre un arbre à `fusionner` dans l'arbre qui appelle la méthode.
    - On fusionne les deux arbres en ajoutant l'arbre donné en paramètre dans l'arbre qui appelle la méthode.
    - Si l'arbre que l'on veut `ajouter` est `NULL`, on retourne l'arbre non modifier
    - Si ce n'est pas le cas, on va `ajouter` à la `racine` de l'arbre qui appelle la méthode tous les sommets de l'arbre en paramètre. On comme par les sommets proche de la `racine` et de `gauche` à `droite`.
    - On retourne l'arbre courant qui sera donc la fusion des deux arbres.
 * Elle possède une méthode `affichage_infixe` qui affiche l'arbre de manière infixe.
 * Elle possède une méthode `afficher_arbo`, qui affiche l'arbre de manière arborecente.
    - C'est une fonction récursive qui prend en paramètre la `hauteur` de l'arbre, un entier qui déterminera le côté `droit` ou `gauche` dans l'arbre et la racine de l''arbre à afficher.
 * Elle possède une méthode `hauteur`, qui calcule la hauteur d'un arbre récursivement, en comparant la hauteur du sous-arbre gauche et du sous-arbre droit. On retourne la `hauteur` maximale des deux sous-arbres.
 * Elle possède une méthode `nombre_element`, qui calcule le nombre de sommet dans un arbre binaire.
    - On vérifie d'abord si l'arbre est vide.
      - Si c'est le cas, on retourne 0.
      - Sinon, on incrémente le résultat de 1. On rapelle la fonction sur le sous-arbre gauche et le sous-arbre droit.
        - On retourne ensuite le résultat final.
 * Elle possède une méthode `fusionner_huffman`, qui fusionne deux arbres binaire donnés en paramètre à l'aide du constructeur par copie et qui additionne la fréquence du caractère contenu dans les deux `racine` des arbres. La nouvelle fréquence du résultat obtenu est contenu dans une nouvelle racine qui sera la racine de la fusion des deux arbres. On retourne ensuite la nouvelle racine de l'arbre.