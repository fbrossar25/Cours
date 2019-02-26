# Projet Hadoop Master 2 ILC

## Sujet

La note des critiques impactent-t'elles les ventes des jeux vidéos ?

## Fonctionnement

1. Lecture du jeu de données VG_Sales_And_Rankings.csv
2. MapReduce clé = (Name), valeurs = [(Platform, Global_Sales, Critic_Score, User_Score)]
3. MapReduce clé = (Name, Platform), valeurs = [(Global_Sales, (Critic_Score / User_Score))]
    - Pour les jeux n'ayant pas de critique, on les ignorent à cette étape

## Auteurs
---

BROSSARD Florian  
HALLER François