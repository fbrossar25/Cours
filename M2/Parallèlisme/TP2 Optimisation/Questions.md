# Exo 3

## Question 1.1

Oui, car il n'y a pas de dépendances entres les threads concernant cette boucle

## Question 1.2

Oui, mais en indiquant i comme privée dans la zone parallèle

## Examples

```
for i // parallelisable
    for k //oui mais critical nécessaire sur Cij =>  inefficace
        // critical nécessaire car i et j pour
        // être de même valeur (écriture concurrente) 
        for j -> oui
            Cij += Aik * Bkj
```

Faire benchmark 4096*4096 pour parallèlisation sur i