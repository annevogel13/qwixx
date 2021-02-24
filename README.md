**Anne DEJONG  p1905532  ;  Loris MERCIER  p1906860  ;  Victoire CELLIER  p1804414**


Ce Module Image permet de gérer des images. Le code est écrit en C++ et peut se compiler sous Linux.


## 1-- ORGANISATION DE L'ARCHIVE
L'archive est subdivisée en cinq sous-dossiers accompagnée d'un makefile et d'un fichier texte.
- **bin** qui correspond au répertoire où se situent les executables une fois compilés.
- **data** qui contient les assets (images) utilisées par le module
- **doc** qui contient le fichier doxygen qui permet de générer la documentation du code
- **obj** qui correspond au répertoire où se trouve les fichiers objets (.o)
- **src** qui contient les classes s'occupant de faire tourner le module image et de l'afficher
- **makefile**
- **README.md**


## 2-- COMPILATION ET EXÉCUTION

### A] Compilation
Pour compiler ce Module Image et obtenir 3 fichiers exécutables de démonstration, il est nécessaire d'utiliser la commande **```make```** afin de créer mainExemple, mainTest et mainAffichage. Vous pouvez également cibler un des 3 programmes avec **```make nom_du_main```**
Cette commande fait appel au makefile présent dans notre archive.

### B] Exécution
Pour exécuter un des trois programmes compilés (voir section ci-dessus), veuillez suivre ces commandes :
- **mainTest.cpp** : utilisez la commande **```bin/test```**.
- **mainAffichage.cpp** : utilisez la commande **```bin/affichage```**.
- **mainExemple.cpp** : utilisez la commande **```bin/exemple```**.


## 3-- FONCTIONNALITÉS DES EXÉCUTABLES
Chaque exécutable gère une fonctionnalité différente dans le Module Image.
- **mainTest.cpp** crée une image puis exécute la fonction TestRegression() afin de s'assurer que le module fonctionne.
- **mainAffichage.cpp** crée une image et l'affiche dans une fenêtre SDL2.
- **mainExemple.cpp** crée deux images et les enregistre dans un fichier de format .ppm.
