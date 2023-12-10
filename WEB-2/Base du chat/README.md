# Projet Final
## Utilisation du DOM pour la gestion des messages
Fichier JS : page-chat.js
Création de la div message avec append pour l'envoyer dans le div de tous les messages des utilisateurs.
Injection des messages avec innerText pour éviter les attaques XSS.
Création des divs des noms d'utilisateurs en utilisant innerHTML pour ajouter leur nom aux divs.
## Ajout/suppression de sprites au cours de l'animation
Fichiers JS : page-chat.js, Monster.js et Chicken.js
Création du Chicken dans page-chat.js.
Détection du toucher dans Monster.js et suppression du Chicken après 2 secondes.
## Enchaînement d'animations
Fichier JS : Pepega.js
Les Pepegas disparaissent lorsqu'ils se déplacent du haut vers le bas et que leur opacité atteint 0.
Fichier JS : Chicken.js
L'opacité du poulet diminue jusqu'à 0 lorsqu'il est touché.
## Modification de l'état des sprites au cours de l'animation
Fichier JS : Chicken.js
Lorsque le poulet est touché, son opacité diminue.
## Mouvement de sprites (x, y)
Fichiers JS : Monster.js et Chicken.js
Les deux personnages se déplacent en X, et le Monster se déplace en Y lorsqu'il saute.
## Programmation par objet pour au moins 2 types de sprite
Classes : Decoration.js, Monster.js, Chicken.js, Pepega.js, Maison.js
## Gestion d'événements clavier
Fichier JS : page-chat.js
Utilisation de keydown et keyup pour le mouvement du Monster.
Gestion d'événements souris
Fichiers JS : Pepega.js et Chicken.js
Utilisation de mouseover et mouseout pour le Pepega.
Utilisation d'événements click
Fichier JS : page-chat.js
Utilisation de click pour les boutons, par exemple, les touches du joueur, le bouton Surprise, le bouton Stop !
## Utilisation d'un message reçu dans le chat pour générer un comportement
Fichiers JS : Monster.js et page-chat.js
Utilisation de /boutique pour ouvrir la boutique lorsque le Monster est en contact avec le spritesheet de la classe Maison. Petit soucis :  lorsqu'on tappe /boutique ou /fermer on doit bouger le personnage vers les bors du shop pour détecter une collision