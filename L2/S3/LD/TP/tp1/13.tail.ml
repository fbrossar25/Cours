let tail = function
| []	-> failwith "tail sur une liste vide"
| tete::queue -> queue
;;
(*
cette fonction renvoie la queue de la liste 
c�d la liste moins la t�te de la liste 
(la liste priv�e de son premier �lement)
*)
