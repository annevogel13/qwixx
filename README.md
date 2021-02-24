**Anne DEJONG  p1905532  ;  Loris MERCIER  p1906860  ;  Victoire CELLIER  p1804414**


Ce Module Image permet de gérer des images. Le code est écrit en C++ et illustre les outils tels que git, doxygen, valgrind que l'on peut être amené à utiliser dans un code. Ce dernier peut se compiler sous Linux.


## 1-- ORGANISATION DE L'ARCHIVE
L'archive est subdivisée en cinq sous-dossiers et contient aussi un makefile et un fichier texte.
- **bin** qui correspond au répertoire où les exécutables sont compilés
- **data** qui contient les assets (images) utilisées par le module
- **doc** qui contient le fichier doxygen qui permet de générer la documentation du code
- **obj** qui correspond au répertoire où il y a les compilations intermédiaires (.o)
- **src** qui contient les classes s'occupant de faire tourner le module image et de l'afficher
- **makefile**
- **README.md**


## 2-- COMPILATION ET EXÉCUTION

### A] Compilation
Pour compiler ce Module Image, il est nécessaire d'utiliser la commande **```make```**.
Elle fait appel au makefile présent dans notre archive.

### B] Exécution
Lors de l'exécution, vous pouvez utiliser trois différentes commandes, toutes trois exécuteront un programme C++ différent.
- **mainTest.cpp** : pour l'exécuter, utilisez la commande **```bin/test```**.
- **mainAffichage.cpp**, utilisez la commande **```bin/affichage```**.
- **mainExemple.cpp**, utilisez la commande **```bin/exemple```**.


## 3-- FONCTIONNALITÉS DES EXÉCUTABLES

A faire





