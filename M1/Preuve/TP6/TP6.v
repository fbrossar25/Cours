Require Import ZArith.
Open Scope Z_scope. (* remplace les opérateurs nat par Z *)

Inductive op : Set := myplus | mysub | mymul.

Inductive expr : Set :=
| E : expr -> op -> expr -> expr
| ZE : Z -> expr
| Par : (expr) -> expr.

Compute  (E (ZE (-1)%Z) myplus (ZE (-1)%Z)).


Definition t1 := (E (Par (E (ZE 2) myplus (ZE 7))) mymul (ZE 4)).
(* ((2-1)+(7*6))-2 *)
Definition x1 := (Par (E (ZE 2) mysub (ZE 1))).
Definition x2 := (Par (E (ZE 7) mymul (ZE 6))).
Definition t2 := (E (Par (E x1 myplus x2)) mysub (ZE 2)).

Fixpoint eval_expr (e:expr) : Z :=
 match e with
 | E l o r => match o with
             | myplus => (eval_expr l) + (eval_expr r)
             | mysub => (eval_expr l) - (eval_expr r)
             | mymul => (eval_expr l) * (eval_expr r)
             end
 | ZE x => x
 | Par exp => (eval_expr exp)
end.

Compute (eval_expr t1).
Compute (eval_expr t2).



