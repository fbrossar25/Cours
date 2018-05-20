let (x : int) = 3;; 
(*on déclare x = 3*)
let (ajouterX : int -> int) = function y -> x + y;;
(* cette fonction rend x + y*)
ajouterX 2;;
(*La fonction rend x+2 donc 5 car x=3 ici*)
let x = 4;;
(*on réaffecte x avec 4*)
ajouterX 3;;
(*la fonction rend 6 donc on peut voir que le x utiliser par cette fonction utilise une copie du x utilisé lors de sa cration*)
let (ajouterX : int -> int) = function y -> x + y;;
(*on recréer la même fonction ajouterX cependant cette fois elle utiliseras une nouvelle copie de x (ici x=4)*)
ajouterX 3
(*rend 7 cette fois ci*)
