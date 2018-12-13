Lemma Morgan1 : forall P Q :Prop, 
~(P \/ Q) <-> (~P) /\ (~Q).
Proof.
split.
intros.
split.
intro.
destruct H.
left.
apply H0.
intro.
destruct H.
right.
apply H0.
intros.
destruct H.
intro.
destruct H1.
destruct H.
apply H1.
destruct H0.
apply H1.
Qed.

Axiom tiers_exclu : forall A: Prop, A \/ ~A.

Lemma Morgan2 : forall P Q :Prop, 
~(P /\ Q) <-> (~P) \/ (~Q).
Proof.
intros.
split.
intros.
destruct (tiers_exclu P).
destruct (tiers_exclu Q).
destruct H.
split.
apply H0.
apply H1.
right.
apply H1.
left.
apply H0.
intros.
intro.
destruct H0.
destruct H.
contradiction.
contradiction.
Qed.

Lemma Morgan3 : forall (A : Set) (P : A->Prop),
(forall x:A, ~P x) <-> ~exists x:A, P x.
Proof.
intros.
split.
intro.
intro.
destruct H0.
absurd (P x).
apply H.
apply H0.
intros.
intro.
apply H.
exists x.
apply H0.
Qed.

Lemma Morgan3v2: forall (A:Set) (P:A->Prop), (forall x:A, ~P x) <-> ~(exists x:A, P x).
Proof.
split.
intros.
intro.
destruct H0.
apply H in H0.
assumption.
intros.
intro.
destruct H.
exists x.
assumption.
Qed.

Lemma Morgan4 : forall (A : Set) (P : A->Prop),
(exists x:A, ~P x) <-> ~forall x:A, P x.
Proof.
intros.
split.
intro.
intro.
destruct H.
absurd (P x).
apply H.
apply H0.
intros.
elim (tiers_exclu (exists x:A, ~P x)).
intros.
apply H0.
intro.
destruct H.
intro.
elim (tiers_exclu (P x)).
intro.
apply H.
intros.
destruct H0.
exists x.
apply H.
Qed.

Require Export Reals.

Open Scope R_scope.

Check pow.
Check Rpower.
Check INR.
Check Rlt_sqrt2_0.
Check Rpower_pow.

SearchPattern (_ /\ _).
SearchPattern (_ <-> _).

Lemma facile : forall x, (x * 1)%R = x%R.
Proof.
SearchRewrite (_ * 1)%R.
intro.
rewrite Rmult_1_r.
reflexivity.
Qed.
SearchRewrite (Rpower (Rpower _ _) _).

Parameter rat : R->Prop.
Axiom h1 : rat 2.
Axiom h2 : ~rat (sqrt(2)).
Axiom h3 : (sqrt 2) * (sqrt 2) = 2.

Lemma th2 : exists x, exists y, ~rat x /\ ~rat y /\ rat (Rpower x y).
Proof.
intros.
destruct (tiers_exclu (rat (Rpower (sqrt(2)) (sqrt(2))))).
exists (sqrt(2)).
exists (sqrt(2)).
split.
apply h2.
split.
apply h2.
assumption.
exists (Rpower (sqrt(2)) (sqrt(2))).
exists (sqrt(2)).
split.
intro.
contradiction.
split.
apply h2.
Check Rpower_mult.
rewrite Rpower_mult.
rewrite h3.
pattern 2%R at 2; replace 2%R with (INR 2).
rewrite Rpower_pow.
simpl.
rewrite facile.
rewrite h3.
apply h1.
Check Rlt_sqrt2_0.
apply Rlt_sqrt2_0.
Check INR.
simpl.
trivial.
(*split.*)
Qed.