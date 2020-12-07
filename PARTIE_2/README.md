*Auteurs : Dylan HARAL et Tinhinane BERKANI*

 *Projet C++ : Cryptage et décryptage*

 ---

 Note : N'ayant pas eu le temps de faire la partie sur l'interface graphique, on a essayé de faire un affichage propre sur la sortie standard, on fera de notre mieux dans la deuxieme et troisième partie du projet pour dévélopper l'interface graphique et faire un affichage.

 # Programme
 ---
 Le programme est répartie en 4 dossiers :

  * `src/` : qui contient les fichiers sources **(.cpp)** du projet.

  * `inc/` : qui contient les fichiers d'en-tête **(.h)** du projet. 

  * `obj/` : qui un fois compilé, contient les fichiers intermédiares **(.o)** du projet.

  * `bin/` : qui une fois compilé, contient le fichier exécutable `main.exe`.

 Le build est répartie en 6 fichiers :

  * `main.cpp` : qui contient le programme principal.

  * `huffman.cpp` et `huffman.h` : qui contient les fonctions de codages de Huffman et de lecture d'un fichier texte. 

  * `texte.txt` : qui est le fichier de texte qui contient le texte sur lequel on test le codage de Huffman.

  * `Makefile` : qui permet de générés tous le fichiers et dossiers du projet.

 ## Compilation du projet
 ---
 Pour compiler le projet, il vous suffit d'exécuter la commande :
 ```bash
 $ make project
 ```
 Une fois cette commande effectuée, et si tout c'est bien déroulé, les fichiers intermédiaires **(.o)** du projet sont générés dans le répertoire local `obj/` et un fichier exécutable `main` est généré dans le repertoire local `bin/`.

 ## Exécution du programme
 ---
 Pour exécuter l'exécutable du projet, il vous suffit de taper `./bin/main.exe` dans le terminal.

 ## Suppression du projet
 ---
 Pour supprimer tous les fichiers générés ainsi que l'exécutable, vous pouvez utiliser la commande `make clean_project`, ou simplement `make clean`, qui supprimera tous.

 ---
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
 ## Structure du build Qt
 ---
Le build est répartie en 3 dossiers :

  * `Qt/` : qui contient l'ensemble du programme Qt.

  * `Qt/src/` : qui contient les fichiers sources **(.src)** du build. 

  * `build/` : qui contient les fichiers nécéssaires à la compilation du build Qt, et la génération du fichier exécutable `Main`.

 Le build est répartie en 5 fichiers :

  * `main.cpp` : qui contient le programme principal.
  
  * `README.md` : qui décrit pour quel raison, le répertoire build est inititialement vide.
  
  * `config_build.txt`: qui est un script, pour générer un `Makefile` dans le répertoire `build/`.

  * `CMakeLists.txt` : qui permet de générer le build Qt et de créer un `Makefile` pour le compiler.

  * `Makefile` : qui permet de compiler tous le fichiers et les dossiers du build.

 ## Création et compilation du build
 ---
 Pour construire le build Qt du projet, puis le compiler, il vous suffit d'exécuter la commande :
 ```bash
 $ make qt_build
 ```
 Une fois cette commande effectuée, et si tout c'est bien déroulé, le build du projet et un Makefile correspondant sont générés dans le répertoire local `build/` dans un premier temps. Puis, dans un deuxième temps, un fichier exécutable `Main` est généré.

 ## Exécution du programme Qt
 ---
 Pour exécuter le programme du projet, il vous suffit de taper `./build/Main` dans le terminal.

 ## Suppression du build
 ---
 Pour supprimer le build, ainsi que tous les fichiers générés, vous pouvez utiliser la commande `make clean_qt_build`, ou simplement `make clean`, qui supprimera tous.