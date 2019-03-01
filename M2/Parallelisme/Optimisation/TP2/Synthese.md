# Parallèlisation avec OpenMP

Ce TP porte sur la parallélisation CPU du produit de deux matrices A et B vers une matrice résultat C avec OpenMP. La parallélisation de deux implémentations seront comparées :
- Implémentation manuelle
- Utilisation de BLAS mis à disposition dans la bibliothèque OpenBLAS 

La constante SIZE dans les exemples d'algorithmes désigne la taille des matrice.

## Implémentation manuelle
L'implémentation proposée prend cette forme:
```
for (0 <= i < SIZE)
  for (0 <= j < SIZE)
    for(0 <= k < SIZE)
      // Utilisation d'un accumulateur
      C(i,j) += A(i,k) * B(k,j)
```

### Analyse de l'agorithme

## Parallélisation des deux variantes du kernel 0: 

A travers le TP de produit de matrices sur une machine multi-coeurs en utilisant "OpenMP", où l'on a essayé de régler le problème de parallélisation du produit matricielle. On a rencontré plusieurs cas de figures:

Parties de code parallélisable car il est sequentiel et le résultat de son exécution par un thread ne dépend pas des résultats calculés par les autres threads, on peut prendre comme exemple : 
    
- La boucle externe du kernel 0 où les itérations sont indépendantes, afin de rendre cette partie du code parallélisable il faut ajouter "un #pragma omp parallel" for private"(i,j,k)" afin de rendre toute la région parallel et          prévatiser les variables (i,j,k), afin que ces variables évoluent de façon indépendante.
            Quelques résultats :

| Threads | Texec | Gflops |ExecBoucle|
| --- | -------- | -------- |-------- |
| 2   | 0.36    | 6.5    |0.31    | 
| 5   | 0.19   | 14.43   |0.14   | 


- La boucle du milieu où c’est possible de paralléliser, car le code est séquentiel et ses itérations sont indépendantes où il fallait privatiser le "i" dans toute la région parallèle pour qu'il soit partagé et disponible  pour tous les threads.
         
La privatisation des ” j, k” sont également importante pour qu'ils évoluent indépendamment.  
Quelques exemple:
        
| Threads | Texec | Gflops |ExecBoucle|
| --- | -------- | -------- |-------- |
| 2   | 0.36    | 6.46    |0.33    | 
| 5   | 0.23    | 10.83   |0.19   | 

Parties du code où ce n'est pas sequentiel on rencontre plus de difficultés, mais on arrive à faire la parallélisation en ajoutant une zone critique afin d'empêcher la lecture et l'écriture concurentielle. Ceci permettera à chaque thread d'accéder à la zone critique les uns après les autres, et non pas en même temps. On peut prendre comme exemple la boucle interne du Kernel 0 où l'on a privatisé la variable "k" pour qu'elle soit propre à chaque thread et le `#pragma omp critical`. 

Il faut ajouter un private "k" pour qu’il soit indépendant. Comme chaque thread calcul un morceau de l’accumulateur, il faut ensuite ajouter un opérateur d'adition "+" pour que chacun ajoute son calcul.

```CPP
C[i][j] +=  accu[0] + accu[1] + accu[2] +
            accu[3] + accu[4] + accu[5] +
            accu[6] + accu[7];
```

On remarque une diminution de performances car l'accès à la zone critique par les threads à tour de rôle rend l'exécution du programme plus lente :
       
| Threads | Texec | Gflops |ExecBoucle|
| --- | -------- | -------- |-------- |
| 2   | 1.09    | 2.017    |1.06   | 
| 16  | 11.78    | 10.83   |11.75   | 
        

On remarque, aux niveaux des performances, que la parallélisation de la variante "ijk" est la plus efficace car la parallélisation de boucles dont les itérations sont indépendantes est plus simple (Bonne utilisation du cache , traitement des éléments contigus en mémoire) et nous permet d'obtenir de meilleurs résultats.

## Prallélisation d'appels BLAS

L'implémentation proposée au départ est un simple appels à la fonction cblas_dgemm de la bibliothèque BLAS. Cette fonction prend plusieurs paramètres, notamment:
- la méthode de stockage en mémoire (RowMajor, où ColumnMajor)
- les tailles des matrices
- un pointeur vers la case d'index (0,0) pour chacunes des matrices A,B,C

Ici, la parallélisation se fait en jouant sur ces paramètres: on "coupe" les matrices en plusieurs morceaux, permettant de faire plusieurs appels à la fonction cblas_dgemm, chacun indépendant des autres:
1. On peut donner une partie de chaque matrice, à condition de bien les faires correspondres
2. Les matrices A et B sont seulement accédées en lecture
3. La matrices C est accédée en écriture, mais comme expliqué dans le point 1., chaque thread écrit dans une partie de C qui est propre à ce thread

En C et C++ La méthode de stockage utilisée naturellement est RowMajor, méthode que nous utiliserons pour chacuns de ces appels, ceci impliquant que chaque thread multipliera une partie de A avec la matrice B:
![](https://i.imgur.com/SjMZ5w4.jpg =200x)  
En vert, la partie utilisée par un thread.

Le nombre de colonnes des matrices A et C est calculée fonction du nombre de threads totaux, du numéro du thread actuel et de la taille des matrices.

## Comparaison et analyse des performances

**INSERE JOLI GRAPHIQUE ICI**

# Auteurs
DJEBRI Maroua  
BROSSARD Florian













