type couleur = Bleu | Vert | Rouge;;
(* on définit le nouveau type couleur composés d'un attributs pouvant prendre trois valeurs différentes*)
let couleurBleue = Bleu;;
let couleurVerte = Vert;;
let couleurRouge = Rouge;;
let (estDuVert : couleur -> bool) = function
	|Vert -> true
	|_ -> false
	;;
estDuVert Bleu;;
estDuVert couleurBleue;;
estDuVert couleurVerte;;
estDuVert 3;;

type paire = MkPaire of int * int;;
(*on créer un nouveau type paire composant de deux entier. MkPaire est le constructeur du type paire*)
let unePaire = MkPaire (3,2);;
let (first : paire -> int) = function MkPaire (x,y) -> x;;
let (second : paire -> int) = function MkPaire (x,y) -> y;;
first (MkPaire (10,34));;
second (MkPaire (10,34));;
first (unePaire (10,34));;
second (unePaire (10,34));;
(*la fonction first va chercher le premier élément de la paire donner en parametre, la fonction second rend le deuxieme*)
