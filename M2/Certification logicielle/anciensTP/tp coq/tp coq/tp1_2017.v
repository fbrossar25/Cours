Require Export ZArith.
Require Export String.
Require Export List.

Open Scope Z_scope.

Inductive aexpr: Type := 
 Avar : string -> aexpr
|Anum : Z -> aexpr
|Aplus : aexpr -> aexpr -> aexpr
|Aminus : aexpr -> aexpr -> aexpr
|Amul : aexpr -> aexpr -> aexpr.

Definition f1 := Aplus(Aplus (Avar "x") (Anum 3)) (Avar "y").

Inductive bexpr: Type :=
  Blt : aexpr -> aexpr -> bexpr
| Beq : aexpr -> aexpr -> bexpr.

Definition b1 := Blt (Anum 5) (Aplus (Avar "x") (Anum 3)).

Inductive instr: Type :=
 Assign : string -> aexpr -> instr
|Seq : instr -> instr -> instr
|While : bexpr -> instr -> instr
|Skip : instr
|If : bexpr -> instr -> instr -> instr
.


Inductive assert : Type :=
  a_b : bexpr -> assert 
| a_not: assert -> assert 
| a_conj:  assert -> assert -> assert
| a_imp : assert -> assert -> assert.


Fixpoint subst (e:aexpr)(s:string)(v:aexpr) {struct e} : aexpr :=
  match e with
  | Avar s' => if string_dec s s' then v else e
  | Anum n => Anum n
  | Aplus e1 e2 => Aplus (subst e1 s v) (subst e2 s v)
  | Aminus e1 e2 => Aminus (subst e1 s v) (subst e2 s v)
  | Amul e1 e2 => Amul (subst e1 s v) (subst e2 s v)  
  end.

Definition b_subst (b:bexpr) (s:string) (v:aexpr) : bexpr :=
  match b with
 | Blt e1 e2 => Blt (subst e1 s v)(subst e2 s v)
 | Beq e1 e2 => Beq (subst e1 s v)(subst e2 s v)
  end.

Fixpoint a_subst (a:assert)(s:string)(v:aexpr) {struct a} :assert :=
  match a with
  | a_b e => a_b (b_subst e s v)
  | a_not a => a_not (a_subst a s v)
  | a_conj a1 a2 => a_conj(a_subst a1 s v)(a_subst a2 s v)
  | a_imp a1 a2 => a_imp(a_subst a1 s v)(a_subst a2 s v)
  end.


Fixpoint af (g:string->Z)(a:aexpr) {struct a} : Z :=
  match a with
  | Avar s => g s
  | Anum n => n
  | Aplus e1 e2 => af g e1 + af g e2
  | Aminus e1 e2 => af g e1 - af g e2 
  | Amul e1 e2 => af g e1 * af g e2
  end.

Definition bf (g:string->Z)(b:bexpr) : Prop :=
 match b with
   Blt e1 e2 => af g e1 < af g e2
 | Beq e1 e2 => af g e1 = af g e2
 end.

Fixpoint i_a  (g:string->Z)(a:assert) {struct a}: Prop :=
  match a with
    a_b e => bf g e
  | a_not a => ~ i_a  g a
  | a_conj a1 a2 => i_a g a1 /\ i_a g a2
  | a_imp a1 a2 => i_a g a1 -> i_a g a2
  end.


Definition valid  (a:assert) :=
  forall (g:string->Z), i_a g a.


Inductive ax_sem : assert -> instr -> assert -> Prop :=
  | HoareSkip : forall P, ax_sem P Skip P
  | HoareSeq : forall P Q R C1 C2, ax_sem P C1 R -> ax_sem R C2 Q -> ax_sem P (Seq C1 C2) Q
  | HoareAffect : forall P x E, ax_sem (a_subst P x E) (Assign x E) P
  | HoareCond : forall P B S T Q, ax_sem (a_conj (a_b B) P) S Q -> ax_sem (a_conj (a_not (a_b B)) P) T Q 
                                                                -> ax_sem P (If B S T) Q
  | HoareWhile : forall P B C, ax_sem (a_conj (a_b B) P) C P 
                                  -> ax_sem P (While B C) (a_conj P (a_not (a_b B)))
  | HoareCons : forall P S Q P' Q', valid (a_imp P' P) -> ax_sem P S Q 
                                                      -> valid (a_imp Q' Q) 
                                                      -> ax_sem P' S Q' 
.

Definition question_ex : 

Lemma question_ex : forall x, ax_sem (a_b (Blt (Anum 0) (Avar x))) (Assign x (Anum 0)) (a_b (Blt (Anum 0) (Avar x))).
Proof.

(* Montrer que {x > 0} x := x + 1 {x > 0} *)

Lemma question_i : forall x, ax_sem (a_b (Blt (Anum 0) (Avar x))) (Assign x (Anum 0)) (a_b (Blt (Anum 0) (Avar x))).
Proof.
intros.
unfold ax_sem.

(* Montrer que {x > 0} x := x + 2; x := x − 1 {x > 0} 
 A compléter.
*)

(*
 Definir le programme : 
1x:=3; if x < 4 then x:=x+1 else (x:=x+1;x:=x+1)
*)

(* Montrer que dans tout environnement definissant x, l’execution du programme précédent 
produit un environnement ou x vaut 4. *)

(* 
Définir le programme :
x:=3; while x < 5 do x:=x+1 done
*)

(*
 Montrer que dans tout environnement definissant x, l’execution du programme précédent
produit un environnement ou x vaut 5.
*)

Definition pseudo_true := a_b (Beq (Avar "x") (Avar "x")).

(* Montrer le lemme suivant: *)

Lemma always_true: forall i P, ax_sem P i pseudo_true.
Proof.
(* A compléter *)
Qed.


