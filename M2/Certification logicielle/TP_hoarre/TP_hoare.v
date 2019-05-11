Require Export ZArith.
Require Export String.
Require Export List.

Open Scope Z_scope.

Inductive aexpr: Type := 
 Avar : string -> aexpr
|Anum : Z -> aexpr
|Aplus : aexpr -> aexpr -> aexpr
|Aminus : aexpr -> aexpr -> aexpr
|Amul : aexpr -> aexpr -> aexpr
.

Inductive bexpr: Type :=
  Blt : aexpr -> aexpr -> bexpr
| Bgt : aexpr -> aexpr -> bexpr
| Beq : aexpr -> aexpr -> bexpr.

Inductive instr: Type :=
 Assign : string -> aexpr -> instr
|Seq : instr -> instr -> instr
|While : bexpr -> instr -> instr
|Skip : instr
|If : bexpr -> instr -> instr -> instr
.

Definition env := list(string*Z).

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
|Ae_mul : forall e e1 e2 v1 v2, aeval e e1 v1 ->
                                 aeval e e2 v2 ->
                                 aeval e (Amul e1 e2) (v1 * v2)
.


Inductive beval : env -> bexpr -> bool -> Prop :=
 Be_lt1 : forall e e1 e2 v1 v2, aeval e e1 v1 ->
                                aeval e e2 v2 ->
                                v1 < v2 ->
                                beval e (Blt e1 e2) true
|Be_lt2 : forall e e1 e2 v1 v2, aeval e e1 v1 ->
                                aeval e e2 v2 ->
                                v1 >= v2 ->
                                beval e (Blt e1 e2) false
.


Inductive e_update : env->string->Z->env->Prop :=
| s_up1 : forall r x v v', e_update ((x,v)::r) x v' ((x,v')::r)
| s_up2 : forall r r' x y v v', e_update r x v' r' ->
            x <> y -> e_update ((y,v)::r) x v' ((y,v)::r').

Parameter incr_init_var : env -> string -> env -> Prop.

Inductive exec : env->instr->env->Prop :=
| SN_Skip : forall E, exec E Skip E
| SN_Assign : forall E E' x e v, aeval E e v -> e_update E x v E' ->
                           exec E (Assign x e) E'
| SN_Seq : forall E E' E'' i1 i2,
    exec E i1 E' -> exec E' i2 E'' -> exec E (Seq i1 i2) E''
| SN_While_1 : forall E E' E'' b i,
    beval E b true -> exec E i E' -> exec E' (While b i) E'' -> 
                      exec E (While b i) E''
| SN_While_2 : forall E b i,
    beval E b false -> exec E (While b i) E
.

Open Scope string_scope.

Parameter init : env -> string -> env -> Prop.

Definition incr (v:string):= Assign v (Aplus (Avar v) (Anum 1)).

Lemma test: exec (("x",1):: nil) (incr "x") (("x",2):: nil).
Proof.
unfold incr.
apply SN_Assign with (v:=2).
replace 2 with (1+1) by ring.
apply Ae_plus.
apply Ae_var1.
apply Aeint.
apply s_up1.
Qed.


Inductive sos_step : env->instr->instr->env->Prop :=
  SOS_Assign : forall E E' x e v,
   aeval E e v -> e_update E x v E' ->
   sos_step E (Assign x e) Skip E'
| SOS_Skip : forall E i, sos_step E (Seq Skip i) i E
| SOS_Seq : forall E E' i1 i1' i2,
               sos_step E i1 i1' E' ->
               sos_step E (Seq i1 i2)(Seq i1' i2) E'
| SOS_While1 :
     forall E b i, beval E b true ->
       sos_step E (While b i) (Seq i (While b i)) E
| SOS_While2 :
     forall E b i, beval E b false ->
       sos_step E (While b i) Skip E
.

Hint Resolve SOS_Assign SOS_Skip SOS_Seq SOS_While1 SOS_While2.


Inductive sos_star : env->instr->instr->env->Prop :=
  SOS_zero_step : forall E i, sos_star E i i E
| SOS_step_star : forall E E' E'' i i' i'',
             sos_step E i i' E' -> sos_star E' i' i'' E'' ->
             sos_star E i i'' E''.

Hint Resolve SOS_zero_step SOS_step_star.

Lemma sos_star_trans :
   forall r r' r'' i i' i'',
    sos_star r i i' r' -> sos_star r' i' i'' r'' ->
    sos_star r i i'' r''.
Proof.
intros.
induction H.
assumption.
eapply SOS_step_star.
eassumption.
eapply IHsos_star.
auto.
Qed.

Lemma sos_sequence_aux : forall r i is r',
  sos_star r i is r' -> is = Skip ->
  forall i' i'' r'', sos_star r' i' i'' r'' ->
  sos_star r (Seq i i') i'' r''.
Proof.
intros r i is r' H.
induction H.
intros.
subst.
eauto.
intros.
subst.
eauto.
Qed.


Lemma sos_sequence : forall E E' E'' i i',
  sos_star E i Skip E' -> sos_star E' i' Skip E'' ->
  sos_star E (Seq i i') Skip E''.
Proof.
intros.
eapply sos_sequence_aux;eauto.
Qed.


Lemma sn_imp_sos :
 forall E E' i, exec E i E' -> sos_star E i Skip E'.
Proof.
  intros.
 induction H.
(* Cas 1
E : env
______________________________________(1/5)
sos_star E Skip Skip E
*)
  intros.
  apply SOS_zero_step.
(* Cas 2
E : env
E' : env
x : string
e : aexpr
v : Z
H : aeval E e v
H0 : e_update E x v E'
______________________________________(1/4)
sos_star E (Assign x e) Skip E'
*)
intros.
assert (T:sos_step E (Assign x e) Skip E').
eapply SOS_Assign.
apply H.
assumption.
eapply SOS_step_star.
apply T.
apply SOS_zero_step.
(* Cas 3 
3 subgoals
E : env
E' : env
E'' : env
i1 : instr
i2 : instr
H : exec E i1 E'
H0 : exec E' i2 E''
IHexec1 : sos_star E i1 Skip E'
IHexec2 : sos_star E' i2 Skip E''
______________________________________(1/3)
sos_star E (Seq i1 i2) Skip E''
*)
intros.
eapply sos_sequence.
apply IHexec1.
apply IHexec2.

(* Cas 4
2 subgoals
E : env
E' : env
E'' : env
b : bexpr
i : instr
H : beval E b true
H0 : exec E i E'
H1 : exec E' (While b i) E''
IHexec1 : sos_star E i Skip E'
IHexec2 : sos_star E' (While b i) Skip E''
______________________________________(1/2)
sos_star E (While b i) Skip E''
*)

assert (sos_step E (While b i) (Seq i (While b i)) E).
apply SOS_While1.
auto.

assert (sos_star E (Seq i (While b i)) Skip E'').
eapply sos_sequence.
apply IHexec1.
apply IHexec2.

eapply SOS_step_star.
apply H2.
apply H3.

(* Cas 5 
E : env
b : bexpr
i : instr
H : beval E b false
______________________________________(1/1)
sos_star E (While b i) Skip E
*)
intros.
assert (sos_step E (While b i) Skip E).
apply SOS_While2.
assumption.
eapply SOS_step_star.
apply H0.
apply SOS_zero_step.

Qed.


Inductive assert : Type :=
  a_b : bexpr -> assert 
| a_not: assert -> assert 
| a_conj:  assert -> assert -> assert
| a_imp : assert -> assert -> assert.


Fixpoint subst (e:aexpr)(s:string)(v:aexpr) {struct e} : aexpr :=
  match e with
    Avar s' =>
      if string_dec s s' then v else e
  | Anum n => Anum n
  | Aplus e1 e2 => Aplus (subst e1 s v) (subst e2 s v)
  | Aminus e1 e2 => Aminus (subst e1 s v) (subst e2 s v)
  | Amul e1 e2 => Amul (subst e1 s v) (subst e2 s v)  
  end.

Definition b_subst (b:bexpr) (s:string) (v:aexpr) : bexpr :=
  match b with
   Blt e1 e2 => Blt (subst e1 s v)(subst e2 s v)
 | Beq e1 e2 => Beq (subst e1 s v)(subst e2 s v)
 | Bgt e1 e2 => Bgt (subst e1 s v)(subst e2 s v)
  end.

Fixpoint a_subst (a:assert)(s:string)(v:aexpr) {struct a} :assert :=
  match a with
    a_b e => a_b (b_subst e s v)
  | a_not a => a_not (a_subst a s v)
  | a_conj a1 a2 => a_conj(a_subst a1 s v)(a_subst a2 s v)
  | a_imp a1 a2 => a_imp(a_subst a1 s v)(a_subst a2 s v)
  end.


Fixpoint af (g:string->Z)(a:aexpr) {struct a} : Z :=
  match a with
    Avar s => g s
  | Anum n => n
  | Aplus e1 e2 => af g e1 + af g e2
  | Aminus e1 e2 => af g e1 - af g e2 
  | Amul e1 e2 => af g e1 * af g e2
  end.

Definition bf (g:string->Z)(b:bexpr) : Prop :=
 match b with
   Blt e1 e2 => af g e1 < af g e2
 | Beq e1 e2 => af g e1 = af g e2
 | Bgt e1 e2 => af g e1 > af g e2
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

(*
Inductive instr: Type :=
 Assign : string -> aexpr -> instr
|Seq : instr -> instr -> instr
|While : bexpr -> instr -> instr
|Skip : instr
.

Inductive bexpr: Type :=
  Blt : aexpr -> aexpr -> bexpr
| Beq : aexpr -> aexpr -> bexpr.

Inductive assert : Type :=
  a_b : bexpr -> assert 
| a_not: assert -> assert 
| a_conj:  assert -> assert -> assert
| a_imp : assert -> assert -> assert.

Inductive bexpr: Type :=
  Blt : aexpr -> aexpr -> bexpr
| Beq : aexpr -> aexpr -> bexpr.

*)

Inductive ax_sem : assert -> instr -> assert -> Prop :=
    HoareSkip : forall P, ax_sem P Skip P
  | HoareAssign : forall x E P, ax_sem (a_subst P x E) (Assign x E) P
  | HoareSeq : forall C1 C2 P R Q, (ax_sem P C1 R)
                                    -> (ax_sem R C2 Q)
                                    -> (ax_sem P (Seq C1 C2) Q)
  | HoareWhile : forall P B C, ax_sem (a_conj P (a_b B)) C P -> 
                                            ax_sem P (While B C) (a_conj P (a_not (a_b B)))
  | HoareIf : forall B P Q T S, ax_sem (a_conj (a_b B) P) S Q
                                -> ax_sem (a_conj (a_not (a_b B)) P) T Q
                                -> ax_sem P (If B S T) Q
  | HoareCons : forall P P' Q Q' S, valid (a_imp P P') -> ax_sem P' S Q' -> ax_sem P S Q 
.


(* Montrer que {x > 0} x := x + 1 {x > 0} 
 A compléter.
*)

Lemma l1 : forall x : Z, ax_sem (a_b (Bgt (Avar "x") (Anum 0))) (Assign "x" (Aplus (Avar "x") (Anum 1))) (a_b (Bgt (Avar "x") (Anum 0))).
Proof.
  intros.
  apply HoareCons with (P' := (a_b (Bgt (Avar "x") (Anum 0)))) (Q' := (a_b (Bgt (Avar "x") (Anum 0)))).
  apply .
Qed.

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






