let head = function
| []	-> failwith "head sur une liste vide"
| tete::queue -> tete
;;
