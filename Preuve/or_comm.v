Lemma or_comm : forall A B : Prop, (A \/ B) <-> (B \/ A).
Proof.
  split.
  intros.
  destruct H.
  right.
  assumption.
  left.
  assumption.
  
  intros.
  destruct H.
  right.
  assumption.
  left.
  assumption.
  Show Proof.
Qed.