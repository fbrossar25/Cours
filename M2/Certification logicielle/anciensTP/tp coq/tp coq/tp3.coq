Require Export Reals.

Inductive gauss : Set :=
CGauss: Z -> Z -> gauss.

Definition g0 := CGauss 0 0.
Definition g1 := CGauss 1 0.
Definition gi := CGauss 0 1.

Definition Gplus (x: gauss) (y: gauss) := 
match x, y with 
|CGauss xa xb, CGauss ya yb => CGauss (Zplus xa ya) (Zplus xb yb) end.

Definition Gminus (x: gauss) (y: gauss) := 
match x, y with 
|CGauss xa xb, CGauss ya yb => CGauss (Zminus xa ya) (Zminus xb yb) end.

Definition Gmultiply (x: gauss) (y: gauss) := 
match x, y with 
|CGauss xa xb, CGauss ya yb => CGauss (Zminus (Zmult xa ya) (Zmult ya yb)) (Zplus (Zmult xa yb) (Zmult xb ya)) end.

Lemma gauss0plusg1 : forall a:gauss, Gplus g0 a = a.
Proof.
intros.
elim a.
unfold g0.
intros.
simpl.
reflexivity.
Qed.

Axiom Zplus_comm : forall a b : Z, Zplus a b = Zplus b a.
Axiom Zplus_assoc : forall a b c : Z, Zplus (Zplus a b) c = Zplus a (Zplus b c).
Axiom Zmult_comm : forall a b : Z, Zmult a b = Zmult b a.

Lemma Gplus_comm : forall (a:gauss) (b:gauss), Gplus a b = Gplus b a.
Proof.
intros.
elim a. 
elim b.
intros.
unfold Gplus.
rewrite Zplus_comm.
replace (Zplus z2 z0) with (Zplus z0 z2).
trivial.
rewrite Zplus_comm.
trivial.
Qed.

Lemma Gplus_assoc : forall (a:gauss) (b:gauss) (c:gauss), Gplus (Gplus a b) c = Gplus a (Gplus b c).
Proof.
intros.
elim a. 
elim b.
elim c.
intros.
unfold Gplus.
rewrite Zplus_assoc.
replace (Zplus z4 (Zplus z2 z0)) with (Zplus(Zplus z4 z2) z0).
trivial.
rewrite Zplus_assoc.
trivial.
Qed.

Inductive jour : Set :=
| Lundi : jour
| Mardi : jour
| Mercredi : jour
| Jeudi : jour
| Vendredi : jour
| Samedi : jour
| Dimanche : jour.

Definition jour_suivant (j:jour) : jour :=
match j with
| Lundi => Mardi
| Mardi => Mercredi
| Mercredi => Jeudi
| Jeudi => Vendredi
| Vendredi => Samedi
| Samedi => Dimanche
| Dimanche => Lundi end.

Definition jour_precedent (j:jour) : jour :=
match j with
| Lundi => Dimanche
| Mardi => Lundi
| Mercredi => Mardi
| Jeudi => Mercredi
| Vendredi => Jeudi
| Samedi => Vendredi
| Dimanche => Samedi end.

Lemma joursuivantprecedent : forall j:jour, jour_suivant (jour_precedent j) = j.
Proof.
intros.
elim j;simpl; reflexivity.
Qed.

Lemma jourprecedentsuivant : forall j:jour, jour_precedent (jour_suivant j) = j.
Proof.
intros.
elim j;simpl; reflexivity.
Qed.


Fixpoint iter (n:nat) (f : jour -> jour) (j:jour) := 
match n with
| 0 => j
| S k => iter (k) f (f j) end.

Lemma preuve_iter_suivant : forall j:jour,
iter 7 jour_suivant j = j.
Proof.
intros.
elim j;simpl;reflexivity.
Qed.

Lemma preuve_iter_precedent : forall j:jour,
iter 7 jour_precedent j = j.
Proof.
intros.
elim j;simpl;reflexivity.
Qed.

Lemma q6 : forall (j:jour) (n:nat) (m:nat) (f: jour->jour),
iter (n + m) f j = iter n f (iter m f j).
Proof.
intros.
revert j.
elim m.
simpl.
rewrite <- plus_n_O.
reflexivity.
elim n.
intros.
simpl.
reflexivity.
intros.
simpl.
replace (n0 +S n1) with (S n0+ n1).
apply H0.
rewrite <- plus_n_Sm.
trivial.
Qed.

Lemma q7 : forall (j:jour) (n:nat),
iter (7 * n) jour_suivant j = j.
Proof.
intros.
elim n.
rewrite mult_0_r.
simpl.
reflexivity.
intros.
rewrite <- mult_n_Sm.
rewrite q6.
rewrite preuve_iter_suivant.
trivial.
Qed.

