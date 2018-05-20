(*opérateur && || not sur booléens true false*)
true && false;;
true || false;;
not false;;

(*déclaration d'un nouveau type cpf. Chaque variable de ce type auras uniquement les valeurs indiquer en filtre ci-dessous*)
type cpf = 
		Vrai
	|	Faux
	|	Neg of cpf
	|	Et	of cpf * cpf
	|	Ou of cpf * cpf
	|	Imp of cpf * cpf
;;
(*déclaration d'une formule de type cpf*)
let e : cpf = Et(Vrai, Ou(Faux, Vrai));;

(*test d'affichage de chaînes de caractères*)
print_string "coucou\n";;
let ch = "coucou 2\n";;
print_string ch;"test";;

(*déclaration d'une fonction afficheFormuleV1 servant à afficher une formule 'lisible'/que l'on écrirais, avec des parathèse*)
let rec (afficheFormuleV1 : cpf -> unit) = function
	|	Vrai		->	print_string "Vrai"
	|	Faux		->	print_string "Faux"
	|	Neg e1		->	print_string "/"; afficheFormuleV1 (e1);
	|	Et	(e1,e2)	->	print_string "(";afficheFormuleV1 (e1); print_string " . "; afficheFormuleV1 (e2); print_string")"
	|	Ou	(e1,e2)	->	print_string "(";afficheFormuleV1 (e1); print_string " + "; afficheFormuleV1 (e2); print_string")"
	;;

(*
déclaration d'une fonction afficheFormuleV2 prenant en paramètre une formule de type cpf 
et un booléen représentant le fait d'afficher des paranthèse ou non.
Elle à le même but que la fonction afficheFormuleV1 à l'exeption de ne pas afficher les parathèse les plus à l'extérieur.
Cette fonction doit être appelée une premier fois avec false comme booléen afin de ne pas afficher 
les parathèse les plus à l'extérieur.
*)
let rec (afficheFormuleV2 : cpf * bool -> unit) = function
	|	Vrai, b			->	print_string "Vrai"
	|	Faux, b			->	print_string "Faux"
	|	Neg e1, b		->	print_string "¬"; afficheFormuleV2 (e1,true)

	(*******************************************************************************************************************)
	
	|	Et	(e1,e2), b	->	
			if b = true
			then begin 
				print_string "(";afficheFormuleV2 (e1,true); print_string " ∧ "; afficheFormuleV2 (e2,true); print_string")"
			end
			else begin 
				afficheFormuleV2 (e1,true); print_string " ∧ "; afficheFormuleV2 (e2,true)
			end
	
	(*******************************************************************************************************************)
	
	|	Ou	(e1,e2), b	->	
			if b = true
			then begin 
				print_string "(";afficheFormuleV2 (e1,true); print_string " ∨ "; afficheFormuleV2 (e2,true); print_string")"
			end
			else begin 
				afficheFormuleV2 (e1,true); print_string " ∨ "; afficheFormuleV2 (e2,true)
			end
			
	(*******************************************************************************************************************)
			
	|	Imp	(e1,e2), b	->	
			if b
			then begin 
				print_string "(";afficheFormuleV2 (e1,true); print_string " => "; afficheFormuleV2 (e2,true); print_string")"
			end
			else begin 
				afficheFormuleV2 (e1,true); print_string " => "; afficheFormuleV2 (e2,true)
			end
			;;

(*Déclaration d'une fonction afficheFormule ayant pour but d'appelée la fonction afficheFormuleV2 avec comme paramètres
une formule de type cpf et un booléen false ce qui permet de ne pas s'embêté avec le booléen*)
let (afficheFormule : cpf -> unit) = function
	e	->	afficheFormuleV2(e,false);;
	
(*déclaration de trois formule e1, e2, e3 afin de teste la fonction afficheFormule*)
let e1 : cpf = Ou(Et(Vrai,Faux),Et(Vrai,Et(Faux,Et(Et(Vrai,Vrai),Faux))));;
let e2 : cpf = Et(Ou(Neg(Ou(Faux,Vrai)),Et(Vrai,Vrai)),Vrai);;
let e3 : cpf = Ou(Neg(Et(Vrai,Faux)),Et(Vrai,Et(Faux,Et(Et(Vrai,Vrai),Faux))));;

(*test des affichages*)
print_string"e1 : \n";;
afficheFormule e1;;
print_string"\ne2 : \n";;
afficheFormule e2;;
print_string"\ne3 : \n";;
afficheFormule e3;;

(*déclaration de la fonction evalueFormule ayant pour but d'évaluer une formule de type cpf en retournant un booléen en résultat*)
let rec (evalueFormule : cpf -> bool) = function
	|	Vrai		->	true
	|	Faux		->	false
	|	Neg e1		->	not(evalueFormule(e1))

	(*******************************************************************************************************************)
	
	|	Et	(e1,e2)	->	evalueFormule(e1) && evalueFormule(e2)
	
	(*******************************************************************************************************************)
	
	|	Ou	(e1,e2)	->	evalueFormule(e1) || evalueFormule(e2)
	
	(*******************************************************************************************************************)
	
	|	Imp	(e1,e2)	->	not(evalueFormule(e1)) || evalueFormule(e2)
	;;
	
(*test evalueFormule sans implications*)
print_string"e1 : \n";;
evalueFormule e1;;
print_string"\ne2 : \n";;
evalueFormule e2;;
print_string"\ne3 : \n";;
evalueFormule e3;;

(*déclaration de trois formule e4, e5, e6 afin de teste la fonction afficheFormule et evalueFormule avec l'implication*)
let e4 : cpf = Imp(Imp(Vrai,Faux) , Ou(Vrai,Faux));;
let e5 : cpf = Et(Et(Vrai , Imp(Vrai , Ou(Faux , Imp(Faux , Vrai)))) , Vrai);;
let e6 : cpf = Ou(Faux , Imp(Vrai , Et(Vrai , Imp(Vrai , Et(Vrai , Faux)))));;

(*test des affichages*)
print_string"\n\ne1 : \n\n";;
afficheFormule e4;;
evalueFormule e4;;
print_string"\n\ne2 : \n\n";;
afficheFormule e5;;
evalueFormule e5;;
print_string"\n\ne3 : \n\n";;
afficheFormule e6;;
evalueFormule e6;;
