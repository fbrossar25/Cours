Require Export Reals.


Inductive nat : Set :=O : nat | S : nat->nat.
Fixpoint myplus (n m:nat) : nat :=
match m with
| O => n
| S p => S (myplus (n) (p))
end.


Lemma q2 : forall a b c : nat,
myplus (myplus a b) c = myplus a (myplus b c).
Proof.
intros.
revert a.
revert b.
elim c.
simpl.
reflexivity.
intros.
simpl.
rewrite <- H.
simpl.
trivial.
Qed.

Lemma myplus_Sn_m : forall n m :nat, 
myplus (S n) m = S (myplus n m).
Proof.
intros.
revert n.
elim m.
simpl.
trivial.
intros.
simpl.
rewrite H.
trivial.
Qed. 

Lemma myplus_O_m : forall m:nat, 
myplus O m = m.
Proof.
intros.
elim m.
simpl.
trivial.
intros.
simpl.
rewrite H.
reflexivity.
Qed.

Lemma myplus_comm : forall a b : nat, 
myplus a b = myplus b a. 
Proof.
intros.
elim b.
simpl.
rewrite myplus_O_m.
reflexivity.
intros.
rewrite myplus_Sn_m.
simpl.
rewrite H.
reflexivity.

Fixpoint sommation (f : nat -> nat) (n : nat) := 
match n with
| O => f O
| S k => myplus (f n) (sommation f k) end.




