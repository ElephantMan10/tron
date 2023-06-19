# Tron Multijoueur

Ce projet est une implémentation multijoueur au tour par tour du célebre jeu de Snake en C++. Les joueurs s'affontent dans une grille de taille fixe avec pour objectif de survivre le plus longtemps possible, laissant derière eux un mur infranchissable.
Vous avez également la possiblité d'implémenter des intelligences artificielles (3 sont déjà présentes) pour les faires s'affronter entre elles et voir qui gagne et le temps qu'elle prennent à survivre.

## Fonctionnalités

- Détection des collisions avec les murs et les autres joueurs
- Design simple

## Prérequis

- Compilateur C++

## Installation

1. Cloner ce repo.
``git clone https://github.com/ElephantMan10/tron``

2. Accéder au répertoire du projet
``cd tron``

3. Compiler le code source
``make``

4. Exécuter le jeu
``./tron``

## Déroulement

Chaque joueur est représenté par un numéro (0,1,2,...) et les murs sont représenté par '#'.
