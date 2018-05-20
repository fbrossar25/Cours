let (plus : int * int -> int) = function (x,y) -> x + y;;
plus (6,8);;
let rec (factoriel : int -> int) =
function x -> if x <= 1 then 1
else x * factoriel (x-1)
;;
factoriel 5;;
let rec (sum : int -> int) = 
	function x -> if x <= 1 then 1
				else x + sum (x-1)
;;
sum 5;;
