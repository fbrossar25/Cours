Require Import Lt.
Require Export ArithRing.

Fixpoint myplus (a b:nat) : nat :=
  match b with
  | 0 => a
  | (S b) => (S (myplus a b) )
end.

Compute (myplus 1 (myplus 2 1)).

Lemma myplus_assoc : forall a b c : nat, myplus (myplus a b) c = myplus a (myplus b c).
Proof.
  intros.
  induction c.
  simpl.
  reflexivity.
  simpl.
  rewrite IHc.
  reflexivity.
Qed.

Lemma myplus_0 : forall a : nat, myplus a 0 = a.
Proof.
  intros.
  simpl.
  reflexivity.
Qed.


Lemma myplus_O_m : forall m:nat, myplus O m = m.
Proof.
  intros.
  induction m.
  simpl.
  reflexivity.
  simpl.
  rewrite IHm.
  reflexivity.
Qed.

Lemma myplus_Sn_m : forall n m :nat, myplus (S n) m = S (myplus n m).
Proof.
  intros.
  induction m.
  simpl.
  reflexivity.
  simpl.
  rewrite IHm.
  reflexivity.
Qed.

Lemma myplus_comm : forall a b : nat, myplus a b = myplus b a.
Proof.
  intros.
  induction a.
  simpl.
  rewrite myplus_O_m.
  reflexivity.
  simpl.
  rewrite myplus_Sn_m.
  rewrite IHa.
  reflexivity.
Qed.

Fixpoint sommation (f : nat -> nat) (n : nat) : nat :=
  match n with
  | 0 => 0
  | S n => (f (S n)) + (sommation f n)
end.

Compute (sommation (fun n => n) 5).

Definition id (n:nat) := n.

Compute (sommation id 5).

Lemma sommation_id : forall n : nat, sommation (fun x => x) n * 2 = n * (n + 1).
Proof.
  intros. simpl.
  induction n.
  simpl.
  reflexivity.
  simpl.
  Search (_ + _ * _).
  rewrite PeanoNat.Nat.mul_add_distr_r.
  rewrite IHn.
  ring.
Qed.





