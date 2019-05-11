Require Import PeanoNat.

Inductive jour : Set :=
| lundi : jour
| mardi : jour
| mercredi : jour
| jeudi : jour
| vendredi : jour
| samedi : jour
| dimanche : jour.

Definition jour_suivant (j:jour) : jour :=
  match j with
  | lundi => mardi
  | mardi => mercredi
  | mercredi => jeudi
  | jeudi => vendredi
  | vendredi => samedi
  | samedi => dimanche
  | dimanche => lundi
end.

Definition jour_precedent (j:jour) : jour :=
  match j with
  | lundi => dimanche
  | mardi => lundi
  | mercredi => mardi
  | jeudi => mercredi
  | vendredi => jeudi
  | samedi => vendredi
  | dimanche => samedi
end.

Lemma jour_suiv_prec : forall (j:jour), (jour_suivant(jour_precedent j)) = j.
Proof.
  intros.
  elim j; simpl; reflexivity.
  (* applique les règles elim j. simpl. reflexivity. sur tout les sugoals *)
Qed.

Lemma jour_prec_suiv : forall (j:jour), (jour_precedent(jour_suivant j)) = j.
Proof.
  intros.
  elim j; simpl; reflexivity.
Qed.


Fixpoint iter (n:nat) (f:jour -> jour) (j:jour) :=
  match n with
  | 0 => j
  | S n => f (iter n f j)
end.

Lemma iter_7_suiv : forall (j:jour), (iter 7 jour_suivant j) = j.
Proof.
  intros.
  simpl.
  elim j; simpl; reflexivity.
Qed.

Lemma iter_7_prec : forall (j:jour), (iter 7 jour_precedent j) = j.
Proof.
  intros.
  simpl.
  elim j; simpl; reflexivity.
Qed.

Lemma iter_n_plus_m : forall (n m:nat) (f : jour -> jour) (j : jour), iter (n + m) f j = iter n f (iter m f j).
Proof.
  intros.
  induction n.
  simpl.
  reflexivity.
  induction m.
  simpl.
  rewrite IHn.
  reflexivity.
  simpl.
  rewrite IHn.
  reflexivity.
Qed.

Lemma iter_0 : forall (f : jour -> jour) (j : jour), iter 0 f j = j.
Proof.
  intros.
  simpl.
  reflexivity.
Qed.

Lemma iter_mult_7_suiv : forall (j:jour) (n:nat), (iter (7*n) jour_suivant j) = j.
Proof.
  intros.
  induction n.
  simpl.
  reflexivity.
  intros.
  Search (_*S _).
  rewrite Nat.mul_succ_r. (* dans PeanoNat *)
  rewrite iter_n_plus_m.
  rewrite iter_7_suiv.
  rewrite IHn.
  reflexivity.
Qed.
