Require Import List.

Inductive alpha : Set := 
  | M : alpha
  | U : alpha
  | I : alpha.

Definition word := list alpha.

Inductive lang : word -> Prop :=
  | Ax : lang (M::I::nil)
  | R1 : forall(x:word), lang (x++(I::nil)) -> lang (x++(I::U::nil))
  | R2 : forall(x:word), lang (M::x) -> lang (M::(x++x))
  | R3 : forall(x y:word), lang (x++(I::I::I::y)) -> lang (x++(U::y)).

Inductive Z3 : Set :=
| Z0 | Z1 | Z2.

Definition succ z := 
match z with
  | Z0 => Z1
  | Z1 => Z2
  | Z2 => Z0
end.

Definition plus (x y : Z3) := 
match x with
  | Z0 => y
  | Z1 => succ y
  | Z2 => succ (succ y)
end.

Lemma succ3 : forall x:Z3, succ (succ (succ x)) = x.
Proof.
intros.
induction x;simpl;reflexivity.
Qed.

Lemma plus_succ : forall x y:Z3, plus (succ x) y = succ (plus x y).
Proof.
intros.
induction x;simpl;trivial.
induction y;simpl;trivial.
Qed.

Lemma double_non_O : forall x:Z3, x <> Z0 -> plus x x <> Z0.
Proof.
intros.
induction x.
simpl.
apply H.
simpl.
discriminate.
simpl.
discriminate.
Qed.

Fixpoint occur (l:word) : Z3 :=
match l with
| nil => Z0
| I::x => succ (occur x)
| _::x => occur x
end.

Lemma plus_plus : forall a b, occur (a ++ b) = plus (occur a) (occur b).
Proof.
intros.
induction a.
simpl.
trivial.
destruct a; trivial.
simpl.
rewrite plus_succ.
rewrite <- IHa.
trivial.
Qed.

Lemma lang_I : forall l, lang l -> occur l <> Z0.
Proof.
intros.
induction H.
simpl.
discriminate.
simpl in *.
rewrite plus_plus in *.
simpl in *.
trivial.
simpl in *.
rewrite plus_plus in *.
apply double_non_O.
assumption.