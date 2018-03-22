(* resumé des commandes diapo 46 *)
Require Import ZArith.

Inductive gauss :Type :=
Cgauss : Z -> Z -> gauss.

Definition g0 := Cgauss 0 0.
Definition g1 := Cgauss 1 0.
Definition gi := Cgauss 0 1.

Definition cplus z1 z2 :=
  match z1, z2 with
    Cgauss a1 b1 , Cgauss a2 b2
    => Cgauss(a1+a2) (b1+b2)
  end.

Definition cmoins z1 z2 :=
  match z1, z2 with
    Cgauss a1 b1 , Cgauss a2 b2
    => Cgauss(a1-a2) (b1-b2)
  end.

Definition cfois z1 z2 :=
  match z1, z2 with
    Cgauss a1 b1 , Cgauss a2 b2
    => Cgauss((a1*a2)-(b1*b2)) (a1*b2+a2*b1)
  end.


Lemma addZero :forall a: gauss, cplus g0 a = a.
Proof.
  intros; simpl.
  destruct a.
  reflexivity.
Qed.
  

Open Scope Z_scope.

Lemma Gplus_comm :forall a b: gauss, cplus a b = cplus b a.
Proof.
  intros.
  elim a. (* destructure a avec tout les constructeurs possible *)
  elim b.
  intros. (* introduit les forall *)
  simpl. (* applique les fonctions si elles sont appliquables *) 
  rewrite (Zplus_comm z z1).  (* réécriture de (z z1) avec la Definition zplus_comm *)
  rewrite (Zplus_comm z0 z2).
  reflexivity. (* à droite à gauche même chose *)
Qed.

Lemma Gplus_assoc :forall a b c: gauss, (cplus (cplus a b) c) = (cplus a (cplus b c)).
Proof.
  intros.
  elim a.
  elim b.
  elim c.
  intros.
  simpl.
  rewrite (Zplus_assoc z3 z1 z).
  rewrite (Zplus_assoc z4 z2 z0).
  reflexivity.
Qed.