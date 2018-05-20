(*BROSSARD Florian TD2 B*)

type literal = Pos of string | Neg of string;;
type clause = Disj of literal list;; 
let faux = Disj([]);;
type cnf = Conj of clause list;;
let vrai = Conj([]);;

open List;;

(*Affiche literal passé en paramètre*)
let (printLit : literal -> unit) = function 
	|	Neg (a)	->	print_string "¬";print_string a
	|	Pos (a)	->	print_string a
	;;

(*Appel recursivement printLit en parcourant une liste de litéraux*)
let rec (printLitList : literal list -> unit) = function
	|	[]			->	print_string "Faux"
	|	tete::[]	->	printLit (tete)
	|	tete::queue	->	printLit(tete); print_string " ∨ "; printLitList(queue)  
	;;

(*Affiche une clause*)
let (printClause : clause -> unit) = function Disj(l)	->	printLitList (l);;

(*Appel récursivement printClause en parcourant une liste de clause*)
let rec (printClauseList : clause list -> unit) = function
	|	[]			->	print_string "Vrai"
	|	tete::[]	->	printClause(tete)
	|	tete::queue	->	print_string"(";printClause(tete); print_string ") ∧ ("; printClauseList(queue);print_string")"
	;;

(*Affiche un formule cnf*)
let rec (printCNF : cnf -> unit) = function
	|	Conj(l)	->	printClauseList (l)
	;;

(*elimine les litéraux en double dans un liste de litéraux*)
let rec (elimDoubleRec : literal list * literal list -> literal list) = function
	|	tete::queue , save	->	if (mem tete queue) then elimDoubleRec(queue,save)
								else	elimDoubleRec(queue,tete::save)
	|	[],save				->	save
	;;

let (elimDouble : literal list -> literal list) = function l	->	(elimDoubleRec(l,[]));;

(*elimine un litéral en paramètre dans une liste de litéraux*)
let rec (removeLiteral : literal * literal list -> literal list) = function
	|	toRemove,tete::queue	->	if not (toRemove = tete) then removeLiteral(toRemove,queue)
										else tete::removeLiteral(toRemove,queue)
	|	toRemove,[]					->	[]
	;;


let (elimDoubleClause : clause -> clause) = function Disj(l) -> Disj (elimDouble(l));;

(*elimine les litéraux en double dans une clause contenus dans une liste de clause*)
let rec (elimDoubleClauseList : clause list -> clause list) = function
	|	tete::queue	->	elimDoubleClause(tete)::elimDoubleClauseList(queue)
	|	[]			->	[]
	;;

let rec (elimDoubleCNF : cnf -> cnf) = function Conj(l) -> Conj (elimDoubleClauseList(l));;

let (removeLiteralClause: literal * clause -> clause) = function toRemove , Disj(l)	->	Disj (removeLiteral(toRemove,l));;	

(*supprime un litéral en paramètres dans toutes clause d'une liste de clause*)
let rec (removeLiteralClauseList : literal * clause list -> clause list) = function
	|	toRemove,tete::queue	->	removeLiteralClause(toRemove,tete)::removeLiteralClauseList(toRemove,queue)
	|	toRemove,[]				->	[]
	;;
																		
let (removeLiteralCNF: literal * cnf -> cnf) = function toRemove , Conj(l)	->	Conj (removeLiteralClauseList(toRemove,l));;	


let f1 : cnf = Conj([Disj([Pos "P";Pos "Q"]);Disj([Neg"R";Pos "Q"]);Disj([Pos "P";Pos "R"])]);;
(*définition de f2 pour les tests des fonctions d'affichages*)
let f2 : literal list = [Pos "P";Pos "Q";Pos "P"];;
let f3 : cnf = Conj([Disj([Pos "P";Neg "Q";Pos "Q";Pos "P"]);Disj([Pos "Q";Pos "R";Neg "P"])]);;

(*tests des premières fonctions sur f1, f2 et f3*)
(*
print_string "f1 = ";printCNF (f1);print_string"\n\n";;
print_string "\n\nf2 = ";printLitList (f2);print_string"\n";;
print_string "elimDouble (f2) = ";printLitList(elimDouble f2);print_string"\n";;
print_string "removeLiteral(Pos \"Q\",f2) = ";printLitList(removeLiteral(Pos "Q",f2));print_string"\n";;
print_string "\n\nf3 = ";printCNF(f3);print_string"\n";;
print_string "elimDoubleCNF (f3) = ";printCNF(elimDoubleCNF f3);print_string"\n";;
print_string "removeLiteralCNF(Pos \"Q\",f3) = ";printCNF(removeLiteralCNF(Pos "Q",f3));print_string"\n";;

print_string "\n=======================================================\n\n";;
*)

(*DEBUT TP6 *)

(*rend une liste l de type a qui est la concaténation de deux list, l1 et l2, de type a*)
let rec (appendPerso : 'a list * 'a list -> 'a list) = function
	|	l1,[]			->	l1
	|	[],l2			->	l2
	|	l1,tete::queue	->	appendPerso(tete::l1,queue)
	;;

(*Renvoi la chaine de caractère d'un litéral*)
let (litString : literal -> string) = function
	|	Neg (a)	->	a
	|	Pos (a)	->	a
	;;

(*renvoie la list de chaine l sans doublons*)
let rec (elimDoubleStringListRec : string list * string list -> string list) = function
	|tete::queue,save -> if(mem tete queue) then elimDoubleStringListRec(queue,save)
						 else elimDoubleStringListRec(queue,tete::save)
	|[],save -> save
;;

let (elimDoubleStringList : string list -> string list) = function l -> elimDoubleStringListRec(l,[]);;

(*renvoie une liste de chaine de caractere correspondant à la liste des chaines de caractere d'une liste de litéraux*)
let rec (listVar : literal list -> string list) = function
	|	tete::queue	->	litString(tete)::listVar(queue)
	|	[]			->	[]

let (listVarDisj : clause -> string list) = function Disj(l) -> elimDoubleStringList(listVar(l));;

let rec (listVarDisjList : clause list -> string list) = function
	|	[]			->	[]
	|	tete::queue	->	appendPerso(listVarDisj(tete),listVarDisjList(queue))
	;;
	
let (listVarFormula : cnf -> string list) = function Conj(l) -> listVarDisjList(l);;

(*affiche une liste de chaine de caractere*)
let rec (printListVarRec : string list -> unit) = function
	|	tete::[]	->	print_string tete
	|	tete::queue	->	print_string tete;print_string", ";printListVarRec(queue)
	| 	_			->	print_string ""
	;;

let (printListVar : string list -> unit) = function l -> print_string"[";printListVarRec(l);print_string"]\n";;

print_string "List des variables de f3 : ";printListVar(listVarFormula(f3));;

print_string "\n=======================================================\n\n";;

(*renvoie true si le literal target en paramètre est dans la liste de litéraux passée en paramètre*)
let rec(isInLitList : literal * literal list -> bool) = function
	|	target,[]	->	false
	|	target,l	->	if (mem target l) then true else false
	;;

let (isInClause : string * literal list -> bool) = function target,l -> ((isInLitList(Pos(target),l)) || (isInLitList(Neg(target),l)));;

(*si le litéral target est dans la clause c passée en paramètre, alors la fonction rend Disj([])*)
let (rmClauseWithLit : string * clause -> clause ) = function target,Disj(l) -> if(isInClause(target,l)) then Disj([]) else Disj(l);;

(*renvoie true si la clause est vide*)
let (isDisjOfVoidList : clause -> bool) = function Disj(l) -> (l == []);;

(*parcours une liste clauses et supprime les clauses avec le litéral target*)
let rec (rmClauseWithLitClauseList : string * clause list -> clause list) = function
	|	target,[]			->	[]
	|	target,tete::queue	->	let a : clause = rmClauseWithLit(target,tete) in 
								if (isDisjOfVoidList(a)) then rmClauseWithLitClauseList(target,queue)
								else a::rmClauseWithLitClauseList(target,queue)
	;;
	
let (rmClauseWithLitCNF : string * cnf -> cnf) = function target,Conj(l) -> Conj (rmClauseWithLitClauseList(target,l));;

print_string "\n\nf3 = ";printCNF(f3);print_string"\n";;
print_string "rmClauseWithLitCNF(R,f3) = ";printCNF(rmClauseWithLitCNF("R",f3));print_string"\n";;

print_string "\n=======================================================\n\n";;

let (addResol : string * literal list * literal list * clause list -> clause list) = function v,c,d,l ->
				let a : literal list = removeLiteral(Pos(v),c) in
				let b : literal list = removeLiteral(Neg(v),d) in
				let c : literal list = appendPerso(a,b) in 
				if (c = []) then failwith "Contradiction trouvée, formule non staisfiable"
				else Disj(c)::l
	;;

let rec (dpVarLitListClauseList : string * literal list * clause list -> clause list) = function
	|	v,c,[]			-> []
	|	v,c,Disj(d)::queue	-> if isInLitList(Neg(v),d) then addResol(v,c,d,dpVarLitListClauseList(v,c,queue))
							   else Disj(d)::dpVarLitListClauseList(v,c,queue)
	;;
	

let rec (dpVarClauseList : string * clause list * clause list -> clause list) = function
	|  v,[],m 	->	[]
	|  v,Disj(c)::queue,m -> if (isInLitList(Pos(v),c)) then dpVarLitListClauseList(v,c,m)
							 else Disj(c)::dpVarClauseList(v,queue,m)
	;;


let rec (dpClauseList : string list * clause list * clause list -> clause list) = function
	| 	[],l,m 	->	[]
	| 	tete::queue,l,m -> let a : clause list = appendPerso(dpVarClauseList(tete,l,m),dpClauseList(queue,l,m)) in
						   rmClauseWithLitClauseList(tete,a)
	;;
	

let	(dpFormula : cnf * string list -> cnf) = function Conj(f),l -> Conj(dpClauseList(l,f,f));;
	

let (dp : cnf -> cnf) = function f -> dpFormula(f,listVarFormula(f));;

(*redéfinition de f2*)
let f2 : cnf = Conj([Disj([Pos "P";Pos "Q";Pos "P"]);Disj([Pos "P";Pos "Q";Neg "P"])]);;

let f4 : cnf = Conj([Disj([Pos "A"]);Disj([Neg "A"])]);;

(*Résultat faux mais code éxécutable*)

print_string"f1 = ";printCNF(f1);print_string"\n";;
print_string"f2 = ";printCNF(f2);print_string"\n";;
print_string"f3 = ";printCNF(f3);print_string"\n";;
print_string"f4 = ";printCNF(f4);print_string"\n\n";;

print_string"dp(f1) = ";printCNF(dp(f1));print_string"\n\n";;
print_string"dp(f2) = ";printCNF(dp(f2));print_string"\n\n";;
print_string"dp(f3) = ";printCNF(dp(f3));print_string"\n\n";;
print_string"dp(f4) = ";printCNF(dp(f4));print_string"\n\n";;

(*tests des fonctions*)

print_string"liste variable f4 = ";printListVar(listVarFormula(f4));;print_string"\n\n";;