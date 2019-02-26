# Projet Hadoop Master 2 ILC

## Sujet

La note des critiques impacte-t-elle la vente d'un jeu vidéo ? 

## Fonctionnement

1. Lecture du jeu de données VG_Sales_And_Rankings.csv
2. MapReduce clé = (Name), valeurs = [(Platform, Global_Sales, Critic_Score)]
3. MapReduce clé = (Name, Platform), valeurs = (Global_Sales, Critic_Score)
    - On ignore les jeux où le score des critiques manque
    - Certaines notes ont pour valeurs 'tbd'
4. MapReduce clé = (Name, Platform), valeur = (Global_Sales, Critic_Score, Ratio)
    - Ratio = abs(Global_Sales / Critic_Score)
    - Sauvegarde du premier Ratio -> ratio témoin
5. MapReduce clé = (Name, PLatform), valeur = (Globale_Scales, Critic_Score, Influencé)
    - On suppose qu'un jeux est influencé par le score des critiques si l'écart entre le Ratio témoin et le ratio du jeu est inférieur à 20%
    - 0.8 * Temoin < Ratio < 1.2 * Temoin -> Influencé = Oui
    - Sinon Influencé  = Non
6. MapReduce clé = (Oui / Non), valeur = (Nombre d'influencé, Pourcentage)

## Auteurs
---

BROSSARD Florian  
HALLER François