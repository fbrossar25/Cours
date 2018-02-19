Require Import ZArith.

Inductive gauss := g : Z -> Z -> gauss.
Definition g0 : gauss := g 0 0.
Definition g1 : gauss := g 1 0.
Definition gi : gauss := g 0 1.

Function gReal (g : gauss) := g .