Inductive liste {A:Type} : Type :=
| nil : liste
| cons : A -> liste -> liste.

Fixpoint length {A:Type} (l:@liste A) :=
  match l with
  |nil => 0
  |cons h t  => S (length t)
end.

Compute (length (cons 1 nil)).

Compute (length (cons 1 (cons 1 nil))).

Fixpoint map {A B:Type} (l:@liste A) (f : A -> B) :=
  match l with
  | nil => nil
  | cons h t => (cons (f h) (map t f))
end.

Definition double (n: nat) := 2 * n.
Definition decr (n : nat) := n - 1.

Compute (map (cons 1 (cons 1 nil)) double).

Lemma length_map : forall (A B C:Type) (l:liste) (f:A->B), (length (map l f)) = (length l).
Proof.
  intros.
  elim l.
  simpl.
  reflexivity.
  intros.
  simpl.
  rewrite H. (* réécrit la proposition avec H *)
  reflexivity.
Qed.

Definition compose {A B C:Type} (f : B -> C) (g : A -> B) (x : A) := (f (g x)).

Compute (compose decr double 2).
Compute (compose double decr 2).

Lemma compose_assoc : forall (A B C D: Type) (f : C -> D) (g : B -> C) (h : A -> B), (compose (compose f g) h) = (compose f (compose g h)) .
Proof.
  intros.
  unfold compose.
  reflexivity.
Qed.

Lemma compose_map : forall (A B C : Type) (f : B -> C) (g : A -> B) (l: liste), (map l (compose f g)) = (map (map l g) f).
Proof.
  intros.
  elim l.
  simpl.
  reflexivity.
  intros.
  simpl.
  rewrite H.
  unfold compose.
  reflexivity.
Qed.

Arguments nil.
Arguments cons.
Arguments length.
Arguments map.
Arguments compose.

Fixpoint append {A : Type} (l1 l2 :@liste A) : liste :=
  match l1 with
  | nil => l2
  | cons h tl1 => (cons h (append tl1 l2))
end.

Compute (append (cons 1 (cons 2 nil)) (cons 3 (cons 4 nil))).

Lemma map_append : forall (A B : Type) (f : A -> B) (l1 l2 : liste), (map (append l1 l2) f) = (append (map l1 f) (map l2 f)).
Proof.
  intros.
  elim l1.
  simpl.
  reflexivity.
  intros.
  simpl.
  rewrite H.
  reflexivity.
Qed.
