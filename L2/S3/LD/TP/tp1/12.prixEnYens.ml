type prix = Euro of int
          | Yen of int
	;;
let (prixEnYens : prix -> int) = function 
    |Euro(x) -> 157 * x
    |Yen(x) -> x
    ;;
let truc = Euro(5);;
let machin = Yen(100);;
prixEnYens truc;;
prixEnYens machin;;
