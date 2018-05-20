(*BROSSARD Florian L2 Groupe TP2 B*)

type ap = string ;;
(*Declaration du type ap (atome)*)

type pf = Vrai
	| Faux
	| Atome of ap
	| Neg of pf
 	| Et of pf * pf
	| Ou of pf * pf
;;
(*Declaration du type pf (formules propositionnelles)*)

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
	f	->	affichePF2(f,false);;


let rec elimVraiFaux = function
	| Vrai -> Vrai
	| Faux -> Faux
	| Atome a -> Atome a
	| Neg f1 -> let f2 = elimVraiFaux f1 in(match f1 with
						| Vrai -> Faux
						| Faux -> Vrai
						| _ -> Neg(f2))
	| Et(f1,f2) -> let f3 = elimVraiFaux f1 and f4 = elimVraiFaux f2 in (
				match (f3,f4) with
				| (Vrai,f) -> f
				| (f,Vrai) -> f
				| (Faux,f) -> Faux
				| (f,Faux) -> Faux
				| (a,b) -> Et(a,b)
				)
	| Ou(f1,f2) -> let f3 = elimVraiFaux f1 and f4 = elimVraiFaux f2 in ( match (f3,f4) with 
				| (Vrai,f) -> Vrai
				| (f,Vrai) -> Vrai
				| (Faux,f) -> f
				| (f,Faux) -> f
				| (f1,f2) -> Ou(f1,f2))
;;

(*déclaration des fonction f, f1, f2 et f3*)
let f : pf = Et(Atome("P"),Ou( Faux, Et( Vrai, Atome("Q"))));;
let f1 : pf = Ou(Et(Vrai,Faux),Et(Vrai,Et(Faux,Et(Et(Vrai,Vrai),Faux))));;
let f2 : pf = Et(Et(Et(Et(Atome("P"),Faux),Ou(Faux,Vrai)),Ou(Ou(Atome("P"),Vrai),Et(Vrai,Atome("Q")))),Vrai);;
let f3 : pf = Et(Ou(Faux, Et(Atome("R"), Vrai)), Atome("P"));;

(*test de elimVraiFaux sur f, f1, f2 et f3*)
print_string "Test de elimVraiFaux :\n";;
print_string "f = ";;affichePF f;;print_string"\n";;
print_string "elimVraiFaux f = ";;affichePF(elimVraiFaux f);;print_string"\n";;
print_string "f1 = ";;affichePF f1;;print_string"\n";;
print_string "elimVraiFaux f1 = ";; affichePF(elimVraiFaux f1);;print_string"\n";;
print_string "f2 = ";;affichePF f2;;print_string"\n";;
print_string "elimVraiFaux f2 = ";;affichePF(elimVraiFaux f2);;print_string"\n";;
print_string "f3 = ";;affichePF f3;;print_string"\n";;
print_string "elimVraiFaux f3 = ";;affichePF(elimVraiFaux f3);;print_string"\n";;

print_string "\n\n===================================================\n\n";;


let rec elimIdempotence = function
	| Vrai -> Vrai
	| Faux -> Faux
	| Atome a -> Atome a
	| Neg f -> Neg(elimIdempotence f)
	| Ou(f1,f2) -> 	if f1 = f2 then f1 
					else begin
						let f3 : pf = elimIdempotence f1 in
						let f4 : pf = elimIdempotence f2 in
						if (f3 = f4) then f3 else Ou(f3,f4)
					end
	| Et(f1,f2) ->  if f1 = f2 then f1 
					else begin
						let f3 : pf = elimIdempotence f1 in
						let f4 : pf = elimIdempotence f2 in
						if (f3 = f4) then f3 else Et(f3,f4)
					end
;;

let f4 : pf = Et(Ou(Faux, Et(Vrai, Atome("Q"))), Et(Ou(Faux, Et(Vrai, Atome("Q"))), Ou(Faux, Et(Vrai, Atome("Q")))));;
let f4 : pf = Et(Ou(Faux, Et(Vrai, Atome("Q"))), Et(Ou(Faux, Et(Vrai, Atome("Q"))), Ou(Faux, Et(Vrai, Atome("Q")))));;

print_string "Test de elimIdempotence :\n";;
print_string "f4 = ";affichePF f4;;print_string"\n";;
print_string "elimIdempotence f4 = ";;affichePF(elimIdempotence f4) ;;print_string"\n";;

print_string "\n\n===================================================\n\n";;

let rec verifFNN : pf -> bool = function
	|Atome(a) -> true
	|Faux -> true
	|Vrai -> true
	|Neg Neg f -> false
	|Neg Atome f -> true
	|Neg Ou(f1,f2) -> false
	|Neg Et(f1,f2) -> false
	|Neg Vrai -> false
	|Neg Faux -> false
	|Ou(f1,f2) -> verifFNN f1 && verifFNN f2
	|Et(f1,f2) -> verifFNN f1 && verifFNN f2
;;

print_string "Test de verfiFNN :\n";;
print_string "verifFNN de ";;affichePF(Neg(Vrai));;print_string " = ";; if verifFNN (Neg(Vrai)) then print_string"true\n" else print_string"false\n";;
print_string "verifFNN de ";;affichePF(Et(Neg(Atome("D")), Faux));;print_string " = ";;if verifFNN (Et(Neg(Atome("D")), Faux)) then print_string"true\n" else print_string"false\n";;
print_string "verifFNN de ";;affichePF(Neg(Neg(Atome("D"))));;print_string " = ";;if verifFNN (Neg(Neg(Atome("D")))) then print_string"true\n" else print_string"false\n";;
print_string "verifFNN de ";;affichePF(Neg(Et(Atome("D"), Atome("P"))));;print_string " = ";;if verifFNN (Neg(Et(Atome("D"), Atome("P")))) then print_string"true\n" else print_string"false\n";;

print_string "\n\n===================================================\n\n";;

let rec (formeNN : pf -> pf) = function
	| Vrai -> Vrai
	| Faux -> Faux
	| Atome(a)-> Atome(a)
	| Neg(Atome(a)) -> Neg(Atome(a))
	| Neg(Faux) -> Vrai
	| Neg(Vrai) -> Faux
	| Neg(Neg(f)) -> formeNN(f)
	| Neg(Et(f1,f2)) -> Ou(formeNN(Neg(f1)),formeNN(Neg(f2)))
	| Neg(Ou(f1,f2)) -> Et(formeNN(Neg(f1)),formeNN(Neg(f2)))
	| Ou(f1,f2) -> Ou(formeNN(f1),formeNN(f2))
	| Et(f1,f2) -> Et(formeNN(f1),formeNN(f2))
;;

print_string "Test de formeNN sur les même formules que verifFNN:\n";;
affichePF(formeNN(Neg(Vrai)));;print_string"\n";;
affichePF(Et(Neg(Atome "D"), Faux));;print_string"\n";;
affichePF(Neg(Neg(Atome "D")));;print_string"\n";;
affichePF(Neg(Et(Atome ("D"), Atome ("P"))));;print_string"\n";;

print_string "\n\n===================================================\n\n";;

let f5 : pf = Et(Atome ("P"),Neg(Ou(Faux,Neg(Et(Neg(Atome ("Q")),Vrai)))));;

print_string "Test de formeNN sur f5 = ";;affichePF f5;;print_string"\n";;
print_string "verifFNN f5 = ";;if verifFNN f5 then print_string"true\n" else print_string"false\n";;
print_string "formeNN f5 = ";;affichePF(formeNN(f5));; print_string"\n";;
print_string "verifFNN (formeNN f5) = ";;if verifFNN(formeNN f5) then print_string"true\n" else print_string"false\n";;

print_string "\n\n===================================================\n\n";;

let (simplification : pf -> pf) = function 
	f -> formeNN(elimIdempotence(elimVraiFaux f));;

let f6 : pf = Et(Ou(Neg(Atome("P")),Faux),Neg(Et(Neg(Neg(Neg(Atome("P")))),Ou(Vrai,Faux))));;

print_string "Test de simplification:\n";;
print_string "f6 = ";;affichePF(f6);;print_string"\n";;
print_string"simplification f6 = ";;affichePF(simplification(f6));;print_string"\n";;

print_string "\n\n===================================================\n\n";;

let (isLitteral : pf -> bool) = function
    | Atome(a) -> true
    | Neg(Atome(a)) -> true
    | _ -> false
;;

let rec (isClause : pf -> bool) = function
    | Ou(f1,f2) -> (isClause(f1) && isClause(f2))
    | Et(f1,f2) -> false
    | f -> if isLitteral(f) then true else false
;;

let rec (isCNF : pf -> bool) = function
    | Et(f1,f2) -> (isCNF(f1) && isCNF(f2))
    | f -> if isClause(f) then true else false
;;

let f7 : pf = Et(Ou(Atome("P"),Atome"Q"),Et(Ou(Atome("P"),Neg(Atome("R"))),Ou(Atome("P"),Ou(Atome("Q"),Atome("R")))));;

print_string "Test de isCNF sur f7:\n";;
print_string "f7 = ";;affichePF(f7);;print_string"\n";;
print_string"isCNF f7 = ";;if isCNF(f7) then print_string"true\n" else print_string"false\n";;

print_string "\n\n===================================================\n\n";;

let rec (distrib : pf -> pf) = function
    | Ou(f1,Et(f2,f3)) -> Et(Ou(distrib(f1), distrib(f2)), Ou(distrib(f1), distrib(f3)))
    | Ou(Et(f1,f2),f3) -> Et(Ou(distrib(f1), distrib(f3)), Ou(distrib(f2), distrib(f3)))
    | Ou(f1,f2) -> Ou(distrib(f1), distrib(f2))
    | Et(f1,f2) -> Et(distrib(f1), distrib(f2))
    | Neg(f) -> Neg(distrib(f))
    | f -> f
;;

let f8 = Ou(Atome "P",Et(Ou(Neg(Atome "R"),Et(Atome "Q",Atome "R")),Atome "Q"));;
 
print_string "Test de distrib sur f8:\n";;
print_string "f8 = ";;affichePF(f8);;print_string "\n";;
print_string "distrib f8 = ";;affichePF(distrib f8);;print_string "\n";;

print_string "\n\n===================================================\n\n";;

let rec (formCNF : pf -> pf) = function
    | f1 -> let f2 = distrib(simplification(f1)) in
        if ((f1 = f2) || (isCNF(f2))) then f2 else formCNF(f2)
;;

print_string "Test de formCNF sur les formules f1 à f8:\n\n";;
print_string "f1 = ";; affichePF(f1);;print_string "\n";;
print_string "formCNF f1 = ";; affichePF(formCNF f1);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f1) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f2 = ";; affichePF(f2);;print_string "\n";;
print_string "formCNF f2 = ";; affichePF(formCNF f2);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f2) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f3 = ";; affichePF(f3);;print_string "\n";;
print_string "formCNF f3 = ";; affichePF(formCNF f3);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f3) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f4 = ";; affichePF(f4);;print_string "\n";;
print_string "formCNF f4 = ";; affichePF(formCNF f4);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f4) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f5 = ";; affichePF(f5);;print_string "\n";;
print_string "formCNF f5 = ";; affichePF(formCNF f5);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f5) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f6 = ";; affichePF(f6);;print_string "\n";;
print_string "formCNF f6 = ";; affichePF(formCNF f6);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f6) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f7 = ";; affichePF(f7);;print_string "\n";;
print_string "formCNF f7 = ";; affichePF(formCNF f7);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f7) then print_string"true\n\n" else print_string"false\n\n";;
print_string "f8 = ";; affichePF(f8);;print_string "\n";;
print_string "formCNF f8 = ";; affichePF(formCNF f8);; print_string "\n";;
print_string "isCNF f1 = ";; if verifFNN(formeNN f8) then print_string"true\n\n" else print_string"false\n\n";;
