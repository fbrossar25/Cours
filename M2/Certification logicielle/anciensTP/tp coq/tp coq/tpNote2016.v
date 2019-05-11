Require Import Arith.
Require Import Omega.

Lemma q1 : forall A B C : Prop,
A \/ B -> (A->C) -> (B-> ~B) -> C.
Proof.
intros.
apply H0.
destruct H.
assumption.
exfalso.
apply H1.
assumption.
assumption.
Qed.

Parameter X : Set.
Parameter R : X -> X -> Prop.

Lemma q2: 
(exists y, forall x, R x y) -> forall x, exists y, R x y.
Proof.
intros.
destruct H.
exists x0.
apply H.
Qed.

Lemma Q3 :
forall (x:Set) (H : x -> Prop) (M : x -> Prop),
forall cesar, H cesar -> (forall x, H x -> M x) -> M cesar.
Proof.
intros.
apply H1.
apply H0.
Qed.

Inductive ab :=
| Feuille : nat -> ab
| Noeud : ab -> ab -> ab.

Definition arbre4 := Noeud (Noeud (Feuille 0) (Feuille 1)) (Noeud (Feuille 0) (Feuille 1)).

Fixpoint nb_feuilles a :=
match a with 
| Feuille f => 1
| Noeud a1 a2 => nb_feuilles a1 + nb_feuilles a2
end.

Fixpoint hauteur a :=
match a with
| Feuille f => 1
| Noeud a1 a2 => 1 + max (hauteur a1) (hauteur a2)
end.

Fixpoint puissance (a b:nat) : nat :=
match b with
| 0 => 1
| S p => puissance a p * a
end.

Lemma puissance_zero : forall n,
n>0 -> puissance 0 n = 0.
Proof.
induction n.
- intros.
inversion H.
- intros.
simpl.
inversion H.
trivial.
rewrite IHn.
trivial.
assumption.
Qed.

Lemma puissance_croissante :
forall x n m,
x>0 -> n <= m ->
puissance x n <= puissance x m.
intros.
induction H0.
trivial.
simpl.
elim (mult_O_le (puissance x m) x).
intro.
rewrite H1 in H.
inversion H.

intro.
transitivity (puissance x m).
assumption.
replace (puissance x m * x) with (x * puissance x m) by ring.
assumption.
Qed.

Lemma nb_feuilles_petit : forall (a: ab),
nb_feuilles a <= puissance 2 (hauteur a).
Proof.
intros.
induction a.
- simpl.
auto.
- simpl.
transitivity (puissance 2 (hauteur a1) + puissance 2 (hauteur a2)).
apply (Plus.plus_le_compat);assumption.

replace (puissance 2 (max (hauteur a1) (hauteur a2)) * 2) with
(puissance 2 (max (hauteur a1) (hauteur a2)) + puissance 2 (max (hauteur a1) (hauteur a2))) by ring.

apply (Plus.plus_le_compat).
apply puissance_croissante.
auto.
apply Max.le_max_l.

apply puissance_croissante.
auto.
apply Max.le_max_r.
Qed.

