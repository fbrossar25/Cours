(*BROSSARD Florian - M2 ILC - 2018/2019*)

Require Export ZArith.
Require Export String.
Require Export List.
Require Export Omega.


Open Scope Z_scope.

(*-------Expressions arithmétiques---------------*)
Inductive aexpr: Type := 
 Avar : string -> aexpr
|Anum : Z -> aexpr
|Aplus : aexpr -> aexpr -> aexpr
|Aminus : aexpr -> aexpr -> aexpr
.

(*----- exemple d'expression aithmétiques-------*)
Definition e1 : aexpr := Aplus (Aplus (Avar "x") (Anum 3)) (Avar "y").

(*------ expression boolénnes-------------------*)
Inductive bexpr: Type :=
        Blt : aexpr -> aexpr -> bexpr
      | Beq : aexpr -> aexpr -> bexpr.

(*------- instructions--------------------------*)
Inductive instr: Type :=
 Assign : string -> aexpr -> instr
|Seq : instr -> instr -> instr
|While : bexpr -> instr -> instr
|If : bexpr -> instr -> instr -> instr
|Skip : instr
|Increment : string -> aexpr -> instr
.

(*---------- environnement 
  vision constructive : liste de couples identifiant, valeur
 ------------------------------------------------*) 
Definition env := list(string*Z).

(*--------- évaluation arithmétique
    proposition inductive : par exemple, Aeint dit que
    aeval e (Anum n) vaut n pour tout environnement e et tout entier n
-------------------------------------------------*)
Inductive aeval : env -> aexpr -> Z -> Prop :=
 Aeint : forall e n, aeval e (Anum n) n
|Ae_var1 : forall e x n, aeval ((x,n)::e) (Avar x) n
|Ae_var2 : forall e x y v v', x<>y -> aeval e (Avar x) v -> 
                                      aeval ((y,v')::e) (Avar x) v
|Ae_plus : forall e e1 e2 v1 v2, aeval e e1 v1 ->
                                 aeval e e2 v2 ->
                                 aeval e (Aplus e1 e2) (v1 + v2)
|Ae_minus : forall e e1 e2 v1 v2, aeval e e1 v1 ->
                                 aeval e e2 v2 ->
                                 aeval e (Aminus e1 e2) (v1 - v2)
.

(*-------- assertion : 
         transformer une expr. bool. en formule logique
         + négation, conjonction ....
--------------------------------------------------------*)
Inductive assert : Type :=
  Hbexpr : bexpr -> assert
| Hneg : assert -> assert
| Hconj : assert -> assert -> assert
| Himpl : assert -> assert -> assert
.

(* -----substritution d'une variable par une expression
    1- dans une expression arithmétique
--------------------------------------------------------*)
Fixpoint asubst (a : aexpr) (v : string) (a' : aexpr) :=
        match a with
        Avar vp => if string_dec v vp then a' else a
     |  Anum _ => a
     | Aplus e1 e2 => Aplus (asubst e1 v a') (asubst e2 v a')
     | Aminus e1 e2 => Aminus (asubst e1 v a') (asubst e2 v a')
   end.
(*--------------------------------------------------------
    2- dans une expression booléenne
 --------------------------------------------------------*)
Fixpoint bsubst (b : bexpr) (v : string) (a' : aexpr) :=
       match b with 
             Blt a1 a2 => Blt (asubst a1 v a') (asubst a2 v a')
           | Beq a1 a2 => Beq (asubst a1 v a') (asubst a2 v a')
       end.

(*-------------------------------------------------------
    3- dans une assertion
 --------------------------------------------------------*)
Fixpoint Hsubst (h : assert) (v : string) (a' : aexpr) :=
        match h with
            Hbexpr b => Hbexpr (bsubst b v a')
          | Hneg h1 => Hneg (Hsubst h1 v a')
          | Hconj h1 h2 => Hconj (Hsubst h1 v a') (Hsubst h2 v a')
          | Himpl h1 h2 => Himpl (Hsubst h1 v a') (Hsubst h2 v a')
        end.

(*----- évaluation d'une expr arith. dans un env. 
            -> retourne un entier
--------------------------------------------------------*)
Fixpoint Zeval (g : string -> Z) (a : aexpr) :=
        match a with
             Avar x => (g x)  
           | Anum v => v
           | Aplus a1 a2 => (Zeval g a1) + (Zeval g a2)
           | Aminus a1 a2 => (Zeval g a1) - (Zeval g a2)
        end.
(*--------évalutaion d'une expr. bool. dans un env.
           -> retourne une Prop
---------------------------------------------------------*)
Definition Zbevalp (g : string -> Z) (b : bexpr) :=
          match b with
              Blt a1 a2 => (Zeval g a1) < (Zeval g a2)
            | Beq a1 a2 => (Zeval g a1) = (Zeval g a2)
          end.

Check Zbevalp.

(*---------évaluation dune assertion dans un env.
            -> retourne une Prop
----------------------------------------------------------*)
Fixpoint Heval (g : string -> Z) (h : assert) :=
        match h with
           Hbexpr b => Zbevalp g b
          | Hneg h1 => not (Heval g h1)
          | Hconj h1 h2 =>  (Heval g h1) /\ (Heval g h2)
          | Himpl h1 h2 => (Heval g h1) -> (Heval g h2)
        end.

(*----------------------------------------------------
    une assertion est valide si son évaluation est une
    prop. vraie dans tout environnement
--------------------------------------------------------*)
Definition valid p := forall g : string -> Z, Heval g p.

(*------------------------------------------------------
     Définition inductive des triplets de Hoare
   i.e de toutes les formules {p1} I {p2} qu'on peut
   obtenir avec les règles de la logique de Hoare
   chaque item est une règle qu'on peut appliquer 
   pour faire une démonstration.
--------------------------------------------------------*)
Inductive LHoare : assert ->  instr -> assert -> Prop :=    
       H_skip : forall p : assert, LHoare p Skip p    
     | H_seq : forall p r q : assert, forall c1 c2 : instr, 
               LHoare p c1 r -> LHoare r c2 q -> LHoare p (Seq c1 c2) q
     | H_assign : forall p : assert, forall x : string, forall e : aexpr,
               LHoare (Hsubst p x e) (Assign x e) p
     | H_increment : forall p : assert, forall x : string, forall e :aexpr,
               LHoare (Hsubst p x (Aplus (Avar x) e)) (Increment x e) p
     | H_if : forall p q : assert, forall b : bexpr, forall s t : instr,
               LHoare (Hconj (Hbexpr b) p) s q ->
               LHoare (Hconj (Hneg (Hbexpr b)) p) t q ->
               LHoare p (If b s t) q 
     | H_while : forall P, forall B, forall C,
               LHoare (Hconj P (Hbexpr B)) C P ->
               LHoare P (While B C) (Hconj P (Hneg (Hbexpr B)))
     | H_cons : forall p' p q q' : assert, forall s : instr,
                valid (Himpl p' p) ->
                LHoare p s q         ->
                valid (Himpl q q') ->
                LHoare p' s q' 
. 


(*------- Exemples et preuves -------------------------*)
Definition x_gt_0 := (Hbexpr (Blt (Anum 0) (Avar "x"))).
Definition x_gt_1 := (Hbexpr (Blt (Anum 1) (Avar "x"))).
Definition x_eq_2 := (Hbexpr (Beq (Anum 2) (Avar "x"))).
Definition x_eq_5 := (Hbexpr (Beq (Anum 5) (Avar "x"))).
Definition x_plus_1 := (Aplus (Avar "x") (Anum 1)).
Definition x_plus_2 := (Aplus (Avar "x") (Anum 2)).
Definition x_minus_1 := (Aminus (Avar "x") (Anum 1)).

Lemma exemple1 : LHoare x_gt_0 (Assign "x" x_plus_1) x_gt_0.
Proof.
assert (LHoare (Hsubst x_gt_0 "x" x_plus_1) (Assign "x" x_plus_1) x_gt_0).
apply H_assign.
simpl.
apply H_cons with (p := (Hsubst x_gt_0 "x" x_plus_1)) (q := x_gt_0).
unfold valid.
intro.
simpl.
omega.
trivial.
unfold valid.
intro.
simpl.
omega.
Qed.



(*----- fin du sujet---------------------------------------------*)
(*---------------------------------------------------------------

  quelques lemmes et leur preuve donnés à titre d'exemple

----------------------------------------------------------------*)
Lemma exemple2 : LHoare x_gt_0 (Seq (Assign "x" x_plus_2) (Assign "x" x_minus_1)) x_gt_0.
Proof.
assert (LHoare (Hsubst x_gt_1 "x" x_plus_2) (Seq (Assign "x" x_plus_2) (Assign "x" x_minus_1)) x_gt_0).
apply H_seq with (r:= x_gt_1).
apply H_assign.
assert (LHoare (Hsubst x_gt_0 "x" x_minus_1) (Assign "x" x_minus_1) x_gt_0).
apply H_assign.
apply H_cons with (p := Hsubst x_gt_0 "x" x_minus_1) (q := x_gt_0).
unfold valid.
intro.
simpl in *.
omega.
exact H.
unfold valid.
intro.
simpl in *.
omega.
apply H_cons with (p:= Hsubst x_gt_1 "x" x_plus_2) (q := x_gt_0).
unfold valid; intro; simpl in *; omega.
exact H.
unfold valid; intro; simpl in *; omega.
Qed.


(*
 Definir le programme : 
 x:=3; if x < 4 then x:=x+1 else (x:=x+1;x:=x+1)
*)

Definition pgm3 := Seq (Assign "x" (Anum 3)) 
                       (If (Blt (Avar "x") (Anum 4)) 
                             (Assign "x" x_plus_1)
                             (Seq (Assign "x" x_plus_1) (Assign "x" x_plus_1) )).

(* Montrer que dans tout environnement definissant x, 
   l'execution du programme précédent 
   produit un environnement où x vaut 4. *)

Lemma jusif : LHoare (Hbexpr (Beq (Avar "x")(Anum 3))) 
                     (If (Blt (Avar "x") (Anum 4)) 
                             (Assign "x" x_plus_1)
                             (Seq (Assign "x" x_plus_1) (Assign "x" x_plus_1) ))
                    (Hbexpr (Beq (Avar "x")(Anum 4))).
Proof.
apply H_if.
apply H_cons with (p:= Hsubst (Hbexpr (Beq (Avar "x") (Anum 4))) "x" x_plus_1) 
                  (q := (Hbexpr (Beq (Avar "x") (Anum 4)))).
unfold valid.
intro.
simpl in *.
omega.
apply H_assign.
unfold valid.
intro.
simpl in *.
omega.
apply H_cons with (p:= Hsubst (Hbexpr (Beq (Anum 5) (Anum 4))) "x" x_plus_1) 
                  (q := (Hbexpr (Beq (Anum 5) (Anum 4)))).
unfold valid.
intro.
simpl in *.
omega.
apply H_seq with (r := Hsubst (Hbexpr (Beq (Anum 5) (Anum 4))) "x" x_plus_1).
apply H_assign.
apply H_assign.
unfold valid. intro. simpl in *. omega.
Qed.


(*
Il faut ajouter un axiome A3 :

(A3) ---------------------------
     {p[x<-x+exp]} x += exp {p}
     
Et ajouter un constructeur aux types inductifs instr et LHoare
*)

Lemma exo1 : LHoare x_eq_2 (Increment "x" x_plus_1) x_eq_5.
Proof.
assert (LHoare (Hsubst x_eq_2 "x" x_plus_1) (Increment "x" x_plus_1) x_eq_5).
apply H_increment.
Qed.
