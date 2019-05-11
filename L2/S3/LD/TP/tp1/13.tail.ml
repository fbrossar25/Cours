let tail = function
| []	-> failwith "tail sur une liste vide"
| tete::queue -> queue
;;
(*
cette fonction renvoie la queue de la liste 
càd la liste moins la tête de la liste 
(la liste privée de son premier élement)
*)
