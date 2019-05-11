Lemma q1_10 : forall A B C: Prop,
(A -> B) /\ (B -> C) -> (A -> C).
Proof.
intros A B C H.
destruct H.
intro.
apply H0.
apply H.
apply H1.
Qed.

Lemma q1_11 :
forall A B: Prop, 
A \/ B -> B \/ A.
Proof.
intros A B H.
- destruct H as [HA | HB].
right.
apply HA.
left.
apply HB.
Qed.

Lemma q1_12 : forall A B C: Prop,
((A /\ B) -> C) -> A -> B -> C.
Proof.
intros.
apply H.
split.
apply H0.
apply H1.
Qed.

Lemma q1_13 : forall A B C: Prop,
(A -> B -> C) -> (A /\ B) -> C.
Proof.
intros.
apply H.
destruct H0.
apply H0.
destruct H0.
assumption.
Qed.

Lemma q1_14 : forall A B C: Prop,
(A /\ (B \/ C)) -> ((A /\ B) \/ (A /\ C)).
Proof.
intros.
destruct H.
destruct H0 as [H0a | H0b].
left.
split.
apply H.
apply H0a.
right.
split.
apply H.
apply H0b.
Qed.

Lemma q1_15 : forall A B C: Prop,
((A /\ B) \/ (A /\ C)) -> (A /\ (B \/ C)).
Proof.
intros.
destruct H as [Ha | Hb].
split.
apply Ha.
left.
apply Ha.
split.
apply Hb.
right.
apply Hb.
Qed.

Print q1_10.

Axiom tiers_exclu : forall A: Prop, A \/ ~A.

Lemma contraposee : forall A B: Prop,
(A -> B) <-> (~B -> ~A).
Proof.
split.
intros.
destruct (tiers_exclu A) as [H0a | H0b].
exfalso.
absurd B.
apply H0.
apply H.
apply H0a.
apply H0b.
intros.
destruct (tiers_exclu B) as [H1a | H1b].
apply H1a.
exfalso.
absurd A.
apply H.
apply H1b.
apply H0.
Qed.

Lemma doublenegation :
forall A : Prop, ~(~A)<->A.
split.
- intro.
destruct (tiers_exclu A).
assumption.
absurd A.
assumption.
destruct H.
assumption.
- intro.
destruct (tiers_exclu A).
intro.
destruct H1.
assumption.
destruct H0.
assumption.
Qed.

Lemma loidepierce :
forall A B : Prop, ((A->B)->A)->A.
intros A B H.
destruct (tiers_exclu A).
assumption.
apply H.
intros.
contradiction.
Qed.

Lemma dernier:
forall (A : Set) (B : A -> A -> Prop),
(exists y : A, (forall x : A, B x y)) -> (forall x : A, exists y : A, B x y).
Proof.
intros.
destruct H.
exists x0.
apply H.
Qed.