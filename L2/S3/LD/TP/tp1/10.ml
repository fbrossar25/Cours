let (deuxOuTrois : int -> bool) = function
	| 2 -> true
	| 3 -> true
	| _ -> false
	;;
(*cette fonction rend true si on passe en parametre 2 ou 3 et false sinon*)
deuxOuTrois 2;;
deuxOuTrois 3;;
deuxOuTrois 4;;

let (estIlDAccord : string -> string) = function
	| "oui" -> "Il est d'accord"
	| "non" -> "Il n'est pas d'accord"
	| "Oui" -> "Il est d'accord"
	| "Non" -> "Il n'est pas d'accord"
	| _	-> "Je n'ai pas compris"
	;;
estIlDAccord "oui";;
estIlDAccord "Oui";;
estIlDAccord "non";;
estIlDAccord "Non";;
estIlDAccord "test";;
