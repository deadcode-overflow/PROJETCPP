*Auteurs : Dylan HARAL et Tinhinane BERKANI*

*Projet C++ : Cryptage et décryptage*

---

# Prérequis pour Qt
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
    
Si vous êtes utilisez une distibution Linux, dérivant de Débian ou Ubuntu, la commande de base est la suivante :
```bash
$ sudo apt-get install <nom-du-package>
```

# Création du build
---
Pour construire le build Qt du projet, il vous suffit d'exécuter la commande `cmake`, suivie de l'emplacement du `CMakeLists.txt` du projet Qt dans le terminal.

L'emplacement de ce fichier ce trouve dans le repertoire :
```
./PARTIE_1/Qt/CMakeLists.txt
```
Voici donc la commade :
```
$ cmake ../Qt
```
Une fois cette commande effectuée, et si tout c'est bien déroulé, le build du projet et un Makefile correspondant sont générés.

# Compilation du build
---
Pour compiler le build du projet, il vous suffit maintenant, de taper la commande `make` dans le terminal. Une fois cette commande effectuée un fichier exécutable `Main` est générés.

# Exécution du programme
---
Pour executer le programme du projet, il suffit de taper `./Main` dans le terminal.

# Suppression du build
---
Pour supprimer le build ainsi que tous les fichiers générés, vous pouvez utiliser la commande `make clean_Qt_build` ou simplement `make clean` dans le repertoire `PARTIE_1/`.