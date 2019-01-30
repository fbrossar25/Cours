# Évolution artificielle <!-- omit in toc -->

## Table des matières <!-- omit in toc -->

- [Machine de Koza](#machine-de-koza)
  - [Effort calculatoire](#effort-calculatoire)
  - [Observation sur la puissance de calcul](#observation-sur-la-puissance-de-calcul)
- [Évaluation multi-critères](#%C3%A9valuation-multi-crit%C3%A8res)
  - [Contexte](#contexte)
  - [Traitement séparé des critères](#traitement-s%C3%A9par%C3%A9-des-crit%C3%A8res)
  - [Agrégation des critères](#agr%C3%A9gation-des-crit%C3%A8res)

## Machine de Koza

### Effort calculatoire

Il est difficle d'évaluer la perf d'in algo stochastique car :

- Ce sont des algo probabilistes
- Quand un run ne réussit pas à trouver un bon résultat, comment savoir s'il était sur la bonne voie ?
- Comme dire au bout de combien de générations on va trouver le résultat escompté ?

### Observation sur la puissance de calcul

A chaque grosse étape conceptuelle/sémantique dans la progression, ça correspond à un facteur 10 de la puissance de la machine (Relation entre puissance de calcul et résultats obtenus).

## Évaluation multi-critères

### Contexte

- Il s'agit de minimiser plusieurs critères en même temps, qui sont souvent antagonistes...
- Concerne la plupart des secteurs de l'industrie, où toutes les solutions sont toujours des compromis, entre 2 objectifs (poids/résistance) ou plus (poids/résistance/prix)
- La notion de solution optimale perd sont sens (vélo 10k€ / 5Kg + optimal que 100€ / 15Kg ?)
- Les deux optimaux, chacun dans leurs genre...

Dominant = dominé par personne.  
Dominance forte : sur tous les critères  
Dominance faible : sur au moins 1 critères

### Traitement séparé des critères

- C'est possible si les critères sont indépendants entre eux.  On les minimise un par un.
- Méthode lexicographique (Fourman[85]) : les objectifs sont rangés par ordre d'importance décroissant
- Premier problème : la minimisation du premier critère emmène l'algo vers un zone restreinte, d'où les critères ne peuvent plus ressortir
- De plus, dans la vie courante, les critères sont très souvent liées, et surtout, antagonistes...

### Agrégation des critères

- Moyenne pondérée :
  - On cherche à minimiser une fonction objectif: $f(x) = \sum\lambda_if_i(x)$. Avec $\lambda_i$ pondération de chaque contrainte.