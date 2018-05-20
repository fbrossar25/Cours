let rec(pair : int -> bool) = function n ->
	if n <= 0 then true else impair(n-1)
and (impair : int -> bool) = function n ->
	if n <= 0 then false else pair(n-1)
;;

//rend toujours false si n < 0
//pair(nombre paire) rendra vrai
//pair(nombre impaire) rendra faux
//impair(nombre paire) rendra faux
//impair(nombre impaire) rendra vrai
