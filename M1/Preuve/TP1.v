Require Import Classical.

(* ∀A B C : Prop, (A → B ∧ B → C) → (A → C) *)
Lemma l10 :forall A B C : Prop, (A -> B) /\ (B -> C) -> (A -> C).
Proof.
  intros.
  destruct H.
  apply H1.
  apply H.
  assumption.
Qed.

(* ∀A B : Prop, A ∨ B → B ∨ A *)
Lemma l11 :forall A B : Prop, A \/ B -> B \/ A.
Proof.
  intros.
  destruct H.
  right.
  assumption. (* apply H. *)
  left.
  assumption. (* apply H. *)
Qed.

(* ∀A B C : Prop, ((A ∧ B) → C) → A → B → C *)
Lemma l12 :forall A B C : Prop, ((A /\ B) -> C) -> (A -> B -> C).
Proof.
  intros.
  apply H.
  split.
  assumption.
  assumption.
Qed.

(* ∀A B C : Prop, (A → B → C) → (A ∧ B) → C *)
Lemma l13 :forall A B C : Prop, (A -> B -> C) -> (A /\ B) -> C.
Proof.
  intros.
  apply H.
  destruct H0.
  assumption.
  destruct H0.
  assumption.
Qed.

(* ∀A B C : Prop,(A ∧ (B ∨ C)) → ((A ∧ B) ∨ (A ∧ C)) *)
Lemma l14 :forall A B C : Prop, (A /\ (B \/ C)) -> ((A /\ B) \/ (A /\ C)).
Proof.
  intros.
  destruct H.
  destruct H0.
  left.
  split.
  assumption.
  assumption.
  right.
  split.
  assumption.
  assumption.
Qed.

(* ∀A B C : Prop,((A ∧ B) ∨ (A ∧ C)) → (A ∧ (B ∨ C)) *)
Lemma l15 :forall A B C : Prop, ((A /\ B) \/ (A /\ C)) -> (A /\ (B \/ C)).
Proof.
  intros.
  split.
  destruct H.
  destruct H.
  assumption.
  destruct H.
  assumption.
  destruct H.
  left.
  destruct H.
  assumption.
  right.
  destruct H.
  assumption.
Qed.

Print l10.

Axiom tiers_exclu : forall A:Prop, A \/ ~A.

Lemma NNPP : forall p:Prop, ~ ~ p -> p.
Proof.
  unfold not in |- *; intros; elim (classic p); auto.
  intro NP; elim (H NP).
Qed.

(* ∀A B : Prop,(A → B) ←→ (¬B → ¬A) *)
Lemma Contraposée :forall A B : Prop, (A -> B) <-> (~B -> ~A).
Proof.
  intros.
  split.
  intros.
  intro.
  apply H0.
  apply H.
  assumption.
  intros.
  elim (tiers_exclu B).
  intros; simpl.
  assumption.
  intros.
  absurd A.
  apply H.
  apply H1.
  assumption.
Qed.

(*
Lemma double_neg : forall A : Prop, ~~A <-> A.
Proof.
  intros; simpl.
  split.
  intros.
  absurd A.
  elim (tiers_exclu A).
  intros.
  elim A.
*)

(*
Lemma Pierce : forall A B : Prop, ((A -> B) -> A) -> A.
Proof.
  intros; simpl.
  apply H.
  elim (tiers_exclu A).
  intros.
  assert (A -> B).
  apply H0.
*)