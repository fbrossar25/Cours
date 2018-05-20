#!r6rs

(import (rnrs))

(define (writeln/return x)
  ;;  Fonction tr�s utile pour pouvoir afficher un r�sultat suivi d'un passage
  ;;  � la ligne, tout en pouvant r�cup�rer ce r�sultat dans une variable. Les
  ;;  trois expressions suivantes sont �valu�es en s�quence et la valeur de la
  ;;  derni�re est retourn�e.
  (write x)
  (newline)
  x)

(define (fact n)
  (if (zero? n) 1 (* n (fact (- n 1)))))

(define alternate-series
  '*insert-your-version*)

(define (exponential-minus-v2 x)
  (let ((minus-x (- x)))
    (alternate-series (lambda (n) (inexact (/ (expt minus-x n) (fact n))))
		     1e-4)))

(define (first-mystery n)
  (if (< n 10) n (+ (first-mystery (div n 10)) (mod n 10))))

(define (second-mystery n p)
  ;;
  (define (rec-mystery n0 p0)
    ;;  Une forme sp�ciale "define" interne � une d�finition est �quivalente �
    ;;  l'utilisation d'une forme sp�ciale "letrec*" :
    (if (zero? (mod n0 p0)) (rec-mystery (div n0 p0) p0) n0))
  ;;
  ;;  Principal call:
  (if (or (zero? p) (zero? n)) n (rec-mystery n p)))