#!r6rs
(import (rnrs))

(define f
  (lambda (x y)
    (+ (* 2 x) y)))

(define result
  (let ((x 0)
        (y 1))
    (let ((x y)
          (y x))
      (f x y))))

(define pi (* 4 (atan 1)))  ;  "atan" est la fonction "Arc tangente" en Scheme.
 
(define expr1 (+ (* 4.1 9.8) (/ (* 2 pi) 3)))

(define expr2 (+ (exp pi) (log (sin 2.1)) (sin (+ (/ 1 pi) pi))))