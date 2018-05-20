let tail = function
| []	-> failwith "tail sur une liste vide"
| tete::queue -> queue
;;
let head = function
| []	-> failwith "head sur une liste vide"
| tete::queue -> tete
;;
let pairs = [0;2;4;6];;
head (tail(tail pairs));; (*rend - : int = 4*)
tail (head (tail(tail pairs)));;(*Error : This expression has type int but an expression was expected of type 'a list*)
(*cette erreur est due au fait que head rend un entier et pas une liste*)
tail (tail(tail pairs));;(*rend - : int = 6*)
tail (tail (tail (tail (tail pairs))));;(*Exception : Failure "tail sur une liste vide"*)
