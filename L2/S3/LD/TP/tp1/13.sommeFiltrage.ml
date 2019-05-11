let tail = function
	| []	-> failwith "tail sur une liste vide"
	| tete::queue -> queue
	;;
let head = function
	| []	-> failwith "head sur une liste vide"
	| tete::queue -> tete
	;;
let rec somme = function
	| []	-> 0
	| tete::queue -> tete + somme(queue)
	;;
let pairs = [0;2;4;6];;
let rec nbNonNul = function
	| []	-> 0
	| tete::queue -> if tete !=0 then 1 + nbNonNul(queue)
					 else nbNonNul (queue)
	;;
List.length pairs;; 
(*retourne un entier indiquant le nombre d'élements de la liste pairs*)
List.append pairs pairs;;
 (*retourne une liste que résulte de la concaténation des listes pairs et pairs*)