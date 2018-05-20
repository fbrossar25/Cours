let (x : int) = 3;;
let(ajouterDouble : int -> int) = function y -> let x = y * 2 
in x + y;; 
(*ici le parametre donné lore de l'appel de la fonction est y.
la fonction rend x + y où x = y*2 
l'utilité ici est qu'on peut appeler plusieurs variables par le même nom sans pour autant qu'elle ne se redéfinisse l'une ou l'autre*)
ajouterDouble 2;;
