type paire = MkPaire of int * int;;
let (max : paire -> int) = function MkPaire (x,y) ->
	if x > y  then x
	else if y > x then y
	else x
	;;
