Require Import Arith.

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

Fixpoint reverse {A : Type} (l :@liste A) :=
  match l with
  | nil => nil
  | cons h t => (append (reverse t) (cons h nil))
end.

Compute (reverse (cons 1 (cons 2 (cons 3 (cons 4 nil))))).

Lemma map_reverse : forall (A B : Type) (f : A -> B) (l : liste), (map (reverse l) f) = (reverse (map l f)).
Proof.
  intros.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite map_append.
  simpl.
  rewrite IHl.
  reflexivity.
Qed.



Lemma append_nil : forall {A : Type} (l : @liste A), (append l nil) = l.
Proof.
  intros.
  elim l.
  simpl.
  reflexivity.
  intros.
  simpl.
  rewrite H.
  reflexivity.
Qed.

Lemma append_assoc : forall {A:Type}, forall (l1 l2 l3:@liste A), 
(append l1 (append l2 l3)) = (append (append l1 l2) l3).
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


Lemma  reverse_append : forall {A : Type} (l1 l2 :@liste A), reverse (append l1 l2) = append (reverse l2) (reverse l1).
Proof.
  intros.
  induction l1.
  simpl.
  rewrite append_nil.
  reflexivity.
  simpl.
  rewrite IHl1.
  rewrite append_assoc.
  reflexivity.
Qed.

Lemma append_reverse : forall {A : Type} (l1 l2 :@liste A), append (reverse l2) (reverse l1) = reverse (append l1 l2).
Proof.
  intros.
  induction l1.
  simpl.
  rewrite append_nil.
  reflexivity.
  simpl.
  rewrite reverse_append.
  rewrite append_assoc.
  reflexivity.
Qed.

Lemma double_reverse : forall {A : Type} (l :@liste A), reverse (reverse l) = l.
Proof.
  intros.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite reverse_append.
  simpl.
  rewrite IHl.
  reflexivity.
Qed.

Lemma append_length : forall {A : Type} (l1 l2:@liste A), (length (append l1 l2)) = (length l1) + (length l2).
Proof.
  intros; simpl.
  induction l1.
  simpl.
  reflexivity.
  simpl.
  rewrite IHl1.
  reflexivity.
Qed.

Lemma reverse_length : forall {A : Type} (l:@liste A), (length (reverse l)) = (length l).
Proof.
  intros; simpl.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite append_length.
  simpl.
  rewrite IHl.
  (*
  Search (_ + 1 = _).
  rewrite Nat.add_1_r.
  *)
  ring.
Qed.

Fixpoint foldr {A B : Type} (f: A -> B -> B) (z : B) (l : liste) : B :=
  match l with
  | nil => z
  | cons h t => (f h (foldr f z t))
end.

Lemma l16 : forall (A B : Type) (f: A -> B -> B) (z : B) (l1 l2 : liste), foldr f z (append l1 l2) = foldr f (foldr f z l2) l1.
Proof.
  intros; simpl.
  induction l1.
  simpl.
  reflexivity.
  simpl.
  rewrite IHl1.
  reflexivity.
Qed.

Lemma l17: forall (A B : Type) (f: A -> B -> B) (z : B) (l : liste), foldr (fun h q => cons (f h) q) nil l = map l f.
Proof.
  intros; simpl.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite IHl.
  reflexivity.
Qed.

Lemma l18 : forall (A B: Type) (f : A -> B -> B) (l :@liste A),
(foldr (fun h q => S q) 0 l) = length l.
Proof.
  intros; simpl.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite IHl.
  reflexivity.
Qed.

Lemma l19 : forall {A B: Type} (f : A -> B -> B) (l :@liste A),
(foldr (fun h q => (append (cons h nil) q)) nil l) = l.
Proof.
  intros; simpl.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite IHl.
  reflexivity.
Qed.

Lemma l20 : forall {A B: Type} (f : A -> B -> B) (l :@liste A),
(foldr (fun h q => (append q (cons h nil))) nil l) = reverse l.
Proof.
  intros; simpl.
  induction l.
  simpl.
  reflexivity.
  simpl.
  rewrite IHl.
  reflexivity.
Qed.

Fixpoint foldl {A B : Type} (f: B -> A -> B) (z : B) (l : liste) : B :=
  match l with
  | nil => z
  | cons h t => (f (foldl f z t) h)
end.

Axiom l22 : forall {A B: Type} (f : A -> B -> B) (l :@liste A) (z : B),
foldr f z (reverse l) = foldl (fun x y => f y x) z l.

Fixpoint zip {A : Type} (l1 l2 : @liste A) :=
  match l1,l2 with
  | nil, _ => nil
  | _ , nil => nil
  | (cons h1 t1),(cons h2 t2) => (cons (h1,h2) (zip t1 t2))
end.

Compute zip (cons 1 (cons 2 (cons 3 nil))) (cons 11 (cons 12 nil)).
Compute zip (cons 11 (cons 12 nil)) (cons 1 (cons 2 (cons 3 nil))).

Lemma zip_length : forall (A : Type) (l1 l2 : @liste A), length (zip l1 l2) = length (zip l2 l1).
Proof.
  intros; simpl.
  induction l1.
  induction l2.
  simpl.
  reflexivity.
  simpl.
  reflexivity.
  simpl.
  elim l2.
  simpl.
  reflexivity.
  intros; simpl.
  
