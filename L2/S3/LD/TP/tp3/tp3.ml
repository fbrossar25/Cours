(*test de sting_of_bool*)
let p =false;;
string_of_bool p;;
print_string (string_of_bool p);;

(*déclaration d'un type ap représentant un atome d'une formule propositionnelle sous forme d'une chaîne de caractères*)
type ap = string;;

(*déclaration d'un type pf représentant une formule propositionnelle*)
type pf =	Vrai
		|	Faux
		|	Atome of ap
		|	Neg of pf
		|	Et of pf * pf
		|	Ou of pf * pf
		;;
		
(*déclaration d'une formule propositionnelle f*)
let f : pf = Et(Atome("P"),Ou(Faux,Et(Vrai,Atome("Q"))));;

(*déclaration d'une fonction ayant pour but d'afficher lisiblement un fonction propositionnelle sans les paranthèses aux extrêmitées*)
let rec (affichePF2 : pf * bool -> unit) = function
	|	Vrai, b			->	print_string "Vrai"
	|	Faux, b			->	print_string "Faux"
	|	Neg e1, b		->	print_string "¬"; affichePF2 (e1,true)
	|	Atome e1, b		->	print_string e1

	(*******************************************************************************************************************)
	
	|	Et	(e1,e2), b	->	
			if b
			then begin 
				print_string "(";affichePF2 (e1,true); print_string " ∧ "; affichePF2 (e2,true); print_string")"
			end
			else begin 
				affichePF2 (e1,true); print_string " ∧ "; affichePF2 (e2,true)
			end
	
	(*******************************************************************************************************************)
	
	|	Ou	(e1,e2), b	->	
			if b
			then begin 
				print_string "(";affichePF2 (e1,true); print_string " ∨ "; affichePF2 (e2,true); print_string")"
			end
			else begin 
				affichePF2 (e1,true); print_string " ∨ "; affichePF2 (e2,true)
			end
			;;

(*déclaration d'une fonction ayant pour but d'appeler la fonction affichePF2 avec un booléen false*)
let (affichePF : pf -> unit) = function
	e	->	affichePF2(e,false);;

(*test de la fonction affichePF*)	
affichePF f;;

(*déclaration de  f1 et f2*)
let f1 : pf = Ou(Et(Vrai , Faux) , Et(Vrai , Et(Faux, Et(Et(Vrai , Vrai) , Faux))));;
let f2 : pf = Et(Et(Et(Et(Atome("P") , Faux) , Ou(Faux , Vrai)) , Ou(Ou(Atome("P") , Vrai), Et(Vrai , Atome("Q")))) , Vrai);;

(*test de affichePF sur f1 et f2*)
affichePF f1;;
affichePF f2;;

(*déclaration de la fonction valuation1 retournant vraie si l'on donne un atome P, faux pour Q et une erreur sinon*)
let (valuation1 : ap -> bool) = function
	|	"P"			->	true
	|	"Q"			->	false
	|	_			->	failwith "n'est pas definis"
	;;

(*déclaration de la fonction valuation2 retournant vraie si l'on donne un atome P ou Q et une erreur sinon*)
let (valuation2 : ap -> bool) = function
	|	"P"			->	true
	|	"Q"			->	true
	|	_			->	failwith "n'est pas definis"
	;;

(*déclaration de la fonction ffois2 renvoyant 2 * le résultat de f(x)*)
let ffois2 = function
	(x,f) -> f(x)*2
	;;

(*appel de ffois2 sur un fonction renvoyant x+3 avec x=4 ffois2 retourne donc 2*(4+3) = 14*)
ffois2 (4,(function x -> x+3));;

(*déclaration d'une fontion ff prenant une variable x et une fonction f qui retourne f(x)*)
let ff = function
	(x,f) -> f(x)
	;;

(* x=4 et f(x) -> 2*x donc cette appel à ff rend 8*)
ff(4 , (function x -> 2*x));;

(*rend faux (ici la fonction f rendra toujours faux quel que soit le paramètre)*)
ff(true , (function x -> true && false));;

(*
déclaration d'une fonction interpretation prenant en parametre un forme propositionnelle de type pf  
et une valuation (ici valuation1 ou valuation2 afin de déclarer les valeurs de P et Q)
*)
let rec (interpretation : pf * (ap -> bool) -> bool) = function
	|	Vrai	, valuation				->	true
	|	Faux	, valuation				->	false
	|	Neg e1	, valuation				->	not(interpretation(e1,valuation))
	|	Atome a	, valuation				->	valuation(a)

	(*******************************************************************************************************************)
	
	|	Et	(e1,e2)	, valuation	->	interpretation(e1,valuation) && interpretation(e2,valuation)
	
	(*******************************************************************************************************************)
	
	|	Ou	(e1,e2)	, valuation	->	interpretation(e1,valuation) || interpretation(e2,valuation)
	;;
	
(*test de la fonction interpretation sur f, f1 et f2 avec valuation1 et valuation2*)
interpretation(f,valuation1);;
interpretation(f,valuation2);;
interpretation(f1,valuation1);;
interpretation(f1,valuation2);;
interpretation(f2,valuation1);;
interpretation(f2,valuation2);;

(*test de la fonction interpretation sur f3 avec valuation1 pour déterminer si les erreurs d'écriture sont gérées*)
let f3 : pf = Ou(Faux , Et(Et(Atome("R") , Vrai) , Atome("P")));;
interpretation(f3,valuation1);;
