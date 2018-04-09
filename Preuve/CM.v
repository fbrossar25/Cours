Require Import Arith.

Inductive even : nat -> Prop :=
  even_0 : even 0
  | even_s : forall n : nat, even n -> even (S(S n)).
  
Inductive odd : nat -> Prop :=
    odd_1 : odd 1
  | odd_s : forall n : nat, odd n -> (odd (S(S n))).


Definition even' (n : nat) : Prop := exists k : nat, n = k*2.

Lemma equiv : forall n, even n <-> even' n.
Proof.
  split.
  intros; induction H.
  exists 0.
  reflexivity.
  unfold even' in IHeven.
  elim IHeven.
  intros k Hk.
  exists (S k).
  rewrite Hk.
  simpl.
  reflexivity.
  
  intros H.
  elim H.
  intros.
  rewrite H0.
  clear H0.
  induction x.
  apply even_0.
  simpl.
  apply even_s.
  assumption.
Qed.

Parameter A : Set.

Parameter R : A -> A -> Prop.

Inductive Rstar (R: A->A->Prop) : A->A->Prop :=
    Rstar_refl : forall a:A, Rstar R a a
  | Rstar_R : forall a b:A, R a b -> Rstar R a b
  | Rstar_trans : forall a b c:A, Rstar R a b -> Rstar R b c -> Rstar R a c.

Inductive Rhash (R: A->A->Prop) : A->A->Prop :=
    Rhash_refl : forall a:A, Rhash R a a
  | Rhash_trans : forall a b c, R a b -> Rhash R b c -> Rhash R a c.

Definition sym (R:A->A->Prop) : Prop :=
  forall a b, R a b <-> R b a.
  
Lemma l1 : sym R -> sym (Rstar R).
Proof.
  intros H.
  unfold sym.
  split.
  intros H'; induction H'.
  apply Rstar_refl.
  Show 2.
  apply Rstar_R.
  apply H.
  assumption.
  apply Rstar_trans with (b := b);
  assumption.
  
  intros H'; induction H'.
  apply Rstar_refl.
  apply Rstar_R.
  apply H.
  assumption.
  apply Rstar_trans with (b := b);
  assumption.
Qed.

Eval compute in (plus (S 0) (S (S (S 0)))).
Require Import List.
Check app.
Eval compute in (app (cons 3 nil) (cons 7 (cons 8 nil))).
Eval compute in (app nil nil).

Lemma m1 : forall a b, Rhash R a b -> Rstar R a b.
Proof.
  intros a b H; induction H.
  apply Rstar_refl.
  apply Rstar_trans with (b:=b).
  apply Rstar_R.
  assumption.
  assumption.
Qed.

Lemma m2 : forall a b, R a b -> Rhash R a b.
Proof.
  intros.
  apply Rhash_trans with (b:=b).
  assumption.
  apply Rhash_refl.
Qed.

Definition transitive (R:A->A->Prop) : Prop :=
  forall a b c:A, R a b -> R b c -> R a c.

Lemma m3 : transitive (Rhash R).
Proof.
Admitted.

Lemma l2 : forall a b:A, Rstar R a b <-> Rhash R a b.
Proof.
  intros.
  split.
  intros H; induction H.
  apply Rhash_refl.
  apply m2; assumption.
  apply m3 with (b:=b); assumption.
  apply m1.
Qed.

(*
Inductive even : nat -> Prop :=
  | even_0 : even 0
  | een_s : forall n : nat, even n -> (even (S n))
with odd : nat -> Prop :=
    odd_s: forall n : nat, odd n -> (odd (S n)).
    *)