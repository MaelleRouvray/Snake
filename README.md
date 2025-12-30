## Projet Snake Maelle et Coline

Ce projet a pour objectif d'implémenter le jeu Snake qui consiste à manger des pommes présentes sur le plateau afin de grandir tout en évitant une collision contre le mur ou sur soi-même.

### Structure du projet 
```
.
├── include
│   ├── board.h  
│   ├── food.h
│   ├── game.h
│   └── snake.h
│
├── src
│   ├── board.cpp
│   ├── food.cpp
│   ├── game.cpp
│   ├── main.cpp
│   └── snake.cpp
│
└── tests
    ├── test_board.cpp
    ├── test_collision.cpp
    ├── test_food.cpp
    └── test_snake.cpp
```


### Documentation 
La documentation a été générée avec [doxygen](https://www.doxygen.nl/download.html) par la commande 
```
doxygen doxygenfile
```
pour l'ouvrir sous Windows, il faut taper la commande 
```
start html/index.html
```

### Compilation 
Le projet est compilé avec un Makefile généré par [CMake] (https://cmake.org/download/).  
Nous avons utilisé [Catch2](https://github.com/catchorg/Catch2.git) pour réaliser les tests sur notre code. 
Nous avons également utilisé la librairie graphique SFML afin d'obtenir un rendu graphique optimal. Pour cela, il est nécessaire d'avoir téléchargé [SFML](https://www.sfml-dev.org/fr/download/) ainsi que d'avoir copié la police Arial dans le sous-dossier build/Fonts
Sous Windows voici comment compiler notre projet :
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCatch2_DIR=" ~/Catch2/lib/cmake/Catch2"  # chemin pour Catch2 à modifier
mingw32-make
```
Pour lancer une partie avec l'interface graphique SFML, il faut faire 
```
./bin/snakeProject
``` 
Et pour lancer les tests, 
```
./bin/snake_tests
```

### Comment jouer 
Une fois la fenêtre graphique ouverte, il suffit de taper sur une des quatres touches directions du clavier et le serpent s'orientera dans la direction indiquée. La partie ne commence pas tant qu'aucune touche a été touchée. Le score s'affiche en haut à gauche et sera affiché lors de la fin de la partie. La partie s'arrête à la première collisions du serpent sur lui-même ou contre le mur.  
Attention aux collisions et amusez-vous bien !    



