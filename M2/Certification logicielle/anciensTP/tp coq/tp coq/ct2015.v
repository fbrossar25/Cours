Require Import Bool.
Require Import List.
 
Fixpoint filter {A: Set} (p: A -> bool) (l: list A) : list A :=
match l with
nil => nil
| t::q => if (p t) then t::(filter p q) else (filter p q)
end
.
 
Lemma exo2 : forall {A: Set} (p: A -> bool) (l1 l2 : list A), (filter p l1) ++ (filter p l2) = filter p l1 ++ l2.
Proof.
intros.
elim l1.
elim l2.
trivial.
simpl.
admit.
admit.
 
Inductive quadtree :=
Empty
|Feuille : bool -> quadtree
|Noeud : quadtree -> quadtree -> quadtree -> quadtree -> quadtree
.
 
Fixpoint rv (q: quadtree) : quadtree :=
match q with
Empty => Empty
|Feuille b => Feuille (negb b)
|Noeud q1 q2 q3 q4 => Noeud (rv q1) (rv q2) (rv q3) (rv q4)
end.
 
Lemma exo8 : forall (q: quadtree), rv (rv q) = q.
Proof.
intros.
elim q.
trivial.
simpl.
destruct b ; reflexivity.
intros.
simpl.
rewrite H.
rewrite H0.
rewrite H1.
rewrite H2.
trivial.
Qed.
 
Fixpoint quart (q: quadtree) : quadtree :=
match q with
Empty => Empty
|Feuille b => Feuille b
|Noeud q1 q2 q3 q4 => Noeud q2 q3 q4 q1
end.
 
Lemma exo10 : forall (q: quadtree), quart (quart (quart (quart q))) = q.
Proof.
intros.
elim q.
simpl.
trivial.
simpl.
trivial.
intros.
simpl.
trivial.
Qed.