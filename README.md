# Vector Wallpaper Generator

A little university project to introduce the notion of object oriented programming in C++.
It is a vector wallpaper generator, it uses simple shapes to generate complex objects and backgrounds.

## Installation

A C++ compiler is required (i.e GNU Compiler Collection aka GCC) to compile the project and generate an executable.
An IDE (Integrated Development Environment) may be used to open, build and run the project as well. This project was made on [CodeBlocks](http://www.codeblocks.org/) and [CLion](https://www.jetbrains.com/clion/).

## Usage

### Menu

Upon execution the following menu will appear:

```bash
0. Quitter
1. Dessiner scene
2. Creer un paysage
3. Generer un paysage
4. Afficher un groupe d'objets
5. Detruire un groupe d'objets
Saisir votre action:
```

### 1. Generate a wallpaper

To generate a wallpaper choose option (3) and input a seed:

```bash
0. Quitter
1. Dessiner scene
2. Creer un paysage
3. Generer un paysage
4. Afficher un groupe d'objets
5. Detruire un groupe d'objets
Saisir votre action:3
 3

Saisie de vos parametres:

Graine:165
```

To draw the generated wallpaper choose option (1) then open the `wallpaper.svg` file:

```bash
0. Quitter
1. Dessiner scene
2. Creer un paysage
3. Generer un paysage
4. Afficher un groupe d'objets
5. Detruire un groupe d'objets
Saisir votre action:1
 1

Opening SVG output file : ../wallpaper.svg
OK
```

Note: For testing different seeds open the `wallpaper.html` file.
It has a set refresh rate to see your changes live and avoid constantly opening the `wallpaper.svg` file.

### 2. Create a wallpaper

To create a wallpaper choose option (2) and input the seed and density of each object you wish to create:

```bash
0. Quitter
1. Dessiner scene
2. Creer un paysage
3. Generer un paysage
4. Afficher un groupe d'objets
5. Detruire un groupe d'objets
Saisir votre action:2
 2

Saisie de vos parametres:

Graine:14
 Saisir l'heure digitale:
Heure:11
Minutes:10
Densite d'arbres:54

Densite de champignons:63

Densite de montagnes:15

Taille minimum des Montagnes:5

Taille maximum des Montagnes:10

Densite de collines:3

Densite de sol:4

Densite de lunes:1

Densite de soleils:1

Densite de l'herbe:1

Densite de fleurs:1

Densite de nuages:2

Densite d'etoiles:3
```

Note: After each wallpaper generation, creation or deletion the draw option (1) must be chosen to see the changes.

### Print object information

After drawing a wallpaper, to print the information of the object groups such as coordinates and size choose option (4):

```bash
0. Quitter
1. Dessiner scene
2. Creer un paysage
3. Generer un paysage
4. Afficher un groupe d'objets
5. Detruire un groupe d'objets
Saisir votre action:4
 4

0. Retour
1. Afficher Arriere
2. Afficher Semi arriere
3. Afficher Median
4. Afficher Avant

Saisir votre action:1
 1

Plan was created
Ciel was created
(0, 0)
Largeur x Hauteur: 1366 x 768
Couleur: rgb(254,155,70)

Etoile was created
(515, 12)

Etoile was created
(973, 28)

...
```

### Destroy a group of objects

To destroy a group of objects created or generated choose option (5) and choooe the group:

```bash
0. Quitter
1. Dessiner scene
2. Creer un paysage
3. Generer un paysage
4. Afficher un groupe d'objets
5. Detruire un groupe d'objets
Saisir votre action:5
 5

0. Retour
1. Detruire Arriere
2. Detruire Semi arriere
3. Detruire Median
4. Detruire Avant
Saisir votre action:

1
1
```

## Contributing

All pull requests are welcome. Although for major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)