
Fixpoint map {A B : Set} (f: A -> B) (l:list A)  : list B :=
match l with
| nil => nil
| cons n q => cons (f n) (map f q)
end.

Definition o {A B C:Set} (g : B -> C) (f : A -> B) (x:A):=
(g (f x)).

Lemma q3 : forall (A:Set) (f g : A -> A) (l : list A),
map (o f g) l = map f (map g l).
Proof.
intros.
elim l.
simpl.
reflexivity.
intros.
simpl.
rewrite H.
unfold o.
reflexivity.
Qed.

Fixpoint append {A : Set} (l m:list A)  : list A :=
match l with
| nil => m
| cons n q => cons n (append q m)
end.

Fixpoint reverse2 {A : Set} (l m:list A)  : list A :=
match l with
| nil => m
| cons n q => reverse2 q (cons n m)
end.



Fixpoint reverse {A : Set} (l:list A) : list A :=
match l with
| nil => nil
| cons t q => append (reverse q) (cons t nil)
end.

Lemma app : forall {A : Set} (l:list A),
append l nil = l.
Proof.
intros.
induction l.
trivial.
simpl.
rewrite IHl.
trivial.
Qed.


Lemma commutApp : forall {A : Set} (l m n:list A),
append l (append m n) = append (append l m) n.
Proof.
intros.
revert m n.
induction l.
simpl.
trivial.
intros.
simpl.
rewrite IHl.
trivial.
Qed.

Lemma q5 : forall (A:Set) (l m: list A),
reverse (append l m) = append (reverse m) (reverse l).
Proof.
intros.
revert m.
induction l.
intros.
simpl.
rewrite app.
trivial.
intros.
simpl.
rewrite commutApp.
rewrite IHl.
trivial.
Qed.


Fixpoint length {A:Set} (l:list A) :=
match l with
| nil => 0
| cons n q => 1 + length q
end.

Lemma q7 : forall (A:Set) (l m : list A),
length (append l m) = length m + length l.
Proof.
intros.
elim l.
simpl.
trivial.
intros.
simpl.
rewrite H.
trivial.
Qed.

Lemma q8 : forall (A:Set) (l : list A),
length l = length (reverse l).
Proof.
intros.
elim l.
simpl.
trivial.
intros.
simpl.
rewrite q7.
simpl.
rewrite H.
trivial.
Qed.

Lemma q9 : forall (A:Set) (l : list A),
l = reverse (reverse l).
Proof.
intros.
elim l.
trivial.
intros.
simpl.
rewrite q5.
simpl.
rewrite <-H.
trivial.
Qed.

Lemma q10 : forall {A B: Set} (f: A->B) (l1 l2: list A),
map f (append l1 l2) = append (map f l1) (map f l2).
Proof.
intros.
elim l1.
trivial.
intros.
simpl.
rewrite H.
trivial.
Qed.

Lemma q11 : forall {A B: Set} (f: A->B) (l: list A),
map f (reverse l) = reverse (map f l).
Proof.
intros.
elim l.
trivial.
intros.
simpl.
rewrite <-H.
simpl.
rewrite q10.
trivial.
Qed.