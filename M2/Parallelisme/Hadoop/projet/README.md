# Projet Hadoop Master 2 ILC

## Sujet

La note des critiques impacte-t-elle la vente d'un jeu vidéo ? 

## Jeu de données

https://www.kaggle.com/rush4ratio/video-game-sales-with-ratings/#Video_Games_Sales_as_at_22_Dec_2016.csv

## Fonctionnement

1. Lecture du jeu de données VG_Sales_And_Rankings.csv
2. MapReduce clé = (Name), valeurs = [(Platform, Global_Sales, Critic_Score)]
3. MapReduce clé = (Name, Platform), valeurs = (Global_Sales, Critic_Score)
    - On ignore les jeux où le score des critiques manque
    - Certaines notes ont pour valeurs 'tbd'
4. MapReduce clé = (Name, Platform), valeur = (Ratio)
    - Ratio = 100*(Global_Sales / Critic_Score)
    - Sauvegarde des premier Ratio par console -> ratios témoins
5. MapReduce clé = (Name, PLatform), valeur = (Influencé)
    - On suppose qu'un jeux est influencé par le score des critiques si l'écart entre le Ratio témoin de la même palteforme que le jeu et le ratio du jeu est inférieur à 20%
    - 0.8 * Temoin < Ratio < 1.2 * Temoin -> Influencé = Oui
    - Sinon Influencé  = Non
6. MapReduce clé = (Oui / Non), valeur = (Nombre d'influencé, Pourcentage)

## Lancement du projet

 1. make # compilation
 2. make run # lancement

## Auteurs
---

BROSSARD Florian  
HALLER François