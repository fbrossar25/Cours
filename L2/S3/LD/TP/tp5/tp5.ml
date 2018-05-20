type literal = Pos of string | Neg of string;;
type clause = Disj of literal list;; 
let faux = Disj([]);;
type cnf = Conj of clause list;;
let vrai = Conj([]);;
let f1 : cnf = Conj([Disj([Pos "P";Pos "Q"]);Disj([Neg"R";Pos "Q"]);Disj([Pos "P";Pos "R"])]);;

let (printLit : literal -> unit) = function
	|	Neg (a)	->	print_string "¬";print_string a
	|	Pos (a)	->	print_string a
	;;

let rec (printLitList : literal list -> unit) = function
	|	[]			->	print_string "Faux"
	|	tete::[]	->	printLit (tete)
	|	tete::queue	->	printLit(tete); print_string " ∨ "; printLitList(queue)  
	;;

let (printClause : clause -> unit) = function Disj l	->	printLitList (l);;

let rec (printClauseList : clause list -> unit) = function
	|	[]			->	print_string "Vrai"
	|	tete::[]	->	printClause(tete)
	|	tete::queue	->	print_string"(";printClause(tete); print_string ") ∧ ("; printClauseList(queue);print_string")"
	;;

let rec (printCNF : cnf -> unit) = function
	|	Conj(l)	->	printClauseList (l)
	;;

print_string "f1 = ";printCNF (f1);print_string"\n";;

open List;;
let rec (elimDoubleRec : literal list * literal list -> literal list) = function
	|	tete::queue , save	->	if (mem tete queue) then elimDoubleRec(queue,save)
								else	elimDoubleRec(queue,tete::save)
	|	[],save				->	save
	;;

let (elimDouble : literal list -> literal list) = function l	->	(elimDoubleRec(l,[]));;

let rec (removeLiteralRec : literal * literal list * literal list -> literal list) = function
	|	toRemove,tete::queue,save	->	if not (toRemove = tete) then removeLiteralRec(toRemove,queue,tete::save)
										else removeLiteralRec(toRemove,queue,save)
	|	toRemove,[],save			->	save
	;;
																		
let (removeLiteral: literal * literal list -> literal list) = function toRemove,l	->	removeLiteralRec(toRemove,l,[]);;

let f2 : literal list = [Pos "P";Pos "Q";Pos "P"];;
print_string "f2 = ";printLitList (f2);print_string"\n";;
print_string "elimDouble (f2) = ";printLitList(elimDouble f2);print_string"\n";;
print_string "removeLiteral(Pos \"Q\",f2) = ";printLitList(removeLiteral(Pos "Q",f2));print_string"\n";;

let (elimDoubleClause : clause -> clause) = function Disj l -> Disj (elimDouble(l));;

let rec (elimDoubleClauseList : clause list -> clause list) = function
	|	tete::queue	->	elimDoubleClause(tete)::elimDoubleClauseList(queue)
	|	[]			->	[]
	;;

let rec (elimDoubleCNF : cnf -> cnf) = function Conj l -> Conj (elimDoubleClauseList(l));;

let (removeLiteralClause: literal * clause -> clause) = function toRemove , Disj l	->	Disj (removeLiteral(toRemove,l));;	

let rec (removeLiteralClauseList : literal * clause list -> clause list) = function
	|	toRemove,tete::queue	->	removeLiteralClause(toRemove,tete)::removeLiteralClauseList(toRemove,queue)
	|	toRemove,[]				->	[]
	;;
																		
let (removeLiteralCNF: literal * cnf -> cnf) = function toRemove , Conj l	->	Conj (removeLiteralClauseList(toRemove,l));;	

let f3 : cnf = Conj([Disj([Pos "P";Neg "Q";Pos "Q";Pos "P"]);Disj([Pos "Q";Pos "R";Neg "P"])]);;
print_string "f3 = ";printCNF(f3);print_string"\n";;
print_string "elimDoubleCNF (f3) = ";printCNF(elimDoubleCNF f3);print_string"\n";;
print_string "removeLiteralCNF(Pos \"Q\",f3) = ";printCNF(removeLiteralCNF(Pos "Q",f3));print_string"\n";;
