Inductive btree : Set :=
| Leaf : btree
| Node : nat -> btree -> btree -> btree.

Print btree_ind.

Compute (Leaf).

Compute (Node 1 (Node 0 Leaf Leaf) Leaf ).

Fixpoint mirror (t:btree) :=
  match t with
  | Leaf => Leaf
  | Node n l r => (Node n (mirror r) (mirror l))
end.

Definition test := (Node 1 (Node 2 (Node 3 Leaf Leaf) (Node 4 Leaf Leaf)) (Node 5 (Leaf) (Node 6 Leaf Leaf))).


Compute mirror (Leaf).


Compute mirror (Node 1 (Node 0 Leaf Leaf) (Node 2 Leaf Leaf)).

Compute test.

Compute mirror test.


Compute mirror (mirror test).

Lemma double_mirror : forall a: btree, mirror (mirror a) = a.
Proof.
  intros; simpl.
  induction a.
  simpl.
  reflexivity.
  simpl.
  rewrite IHa1.
  rewrite IHa2.
  reflexivity.
Qed.

Fixpoint tmap (f:nat -> nat) (t:btree) : btree :=
  match t with
  | Leaf => Leaf
  | Node n l r => (Node (f n) (tmap f l) (tmap f r))
end.


Compute (tmap (fun n => 2 * n) test).

Lemma tmap_compose : forall (f g: nat -> nat) (a: btree), tmap f (tmap g a) = tmap (fun x => f (g x)) a.
Proof.
  intros; simpl.
  induction a.
  simpl.
  reflexivity.
  simpl.
  rewrite IHa1.
  rewrite IHa2.
  reflexivity.
Qed.

Require Export List.

Fixpoint btree_to_list (t:btree) :=
  match t with
  | Leaf => nil
  | Node n l r => (btree_to_list l)++n::nil++(btree_to_list r) (* Require Export List pour ++ et :: *)
end.

Compute (btree_to_list (Node 4 (Node 2 (Node 1 Leaf Leaf) (Node 3 Leaf Leaf)) (Node 6 (Node 5 Leaf Leaf) (Node 7 Leaf Leaf)))).

Lemma map_btree_list : forall (f : nat -> nat) (t : btree), (map f (btree_to_list t)) = (btree_to_list (tmap f t)).
Proof.
  intros; simpl.
  induction t.
  simpl.
  reflexivity.
  simpl.
  Check map_app.
  (*  
      map_app : forall (A B : Type) (f : A -> B) (l l' : list A),
      map f (l ++ l') = map f l ++ map f l'
  *)
  rewrite map_app.
  simpl.
  rewrite IHt1.
  rewrite IHt2.
  reflexivity.
Qed.

Fixpoint nb_labels (t:btree) : nat :=
  match t with
  | Leaf => 0
  | Node _ l r => 1 + nb_labels l + nb_labels r
end.

Definition t7 := (Node 1 (Node 2 (Node 4 Leaf Leaf) (Node 5 Leaf Leaf)) (Node 3 (Node 6 Leaf Leaf) (Node 7 Leaf Leaf))).


Compute nb_labels t7.

Compute length (btree_to_list t7).

Require Import Max.

Fixpoint height (t:btree) : nat :=
  match t with
  | Leaf => 1
  | Node _ l r => 1 + (max (height l) (height r))
end.

Compute height (Node 0 Leaf (Node 1 Leaf Leaf)).

Compute height (Node 0 Leaf (Node 1 (Node 2 (Node 3 Leaf (Node 4 Leaf Leaf)) Leaf) Leaf)).

(*
Require Import Arith.

Lemma height_lt_nb_labels : forall (t : btree), (height t) <= (nb_labels t).
Proof.
  intros; simpl.
  induction t.
  simpl.
  reflexivity.
  case_eq t1.
  Check max_dec. (* {Nat.max n m = n} + {Nat.max n m = m} wtf ???? *)
  Check plus_comm. (* n + m = m + n *)
  Check le_plus_trans. (* n <= m -> n <= m + p *)
  intros; simpl.
  rewrite le_plus_trans.
*)

Fixpoint btree_in (x: nat) (t: btree) : Prop := (* t contient x ? *)
match t with
| Leaf => False
| Node e l r => (btree_in x l) \/ e=x \/ (btree_in x r)
end.