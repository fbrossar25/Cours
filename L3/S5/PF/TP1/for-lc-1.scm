#!r6rs

(import (rnrs))          ;  Importation en vrac de tous les modules de la
;  biblioth�que initiale: nous verrons plus tard
;  comment proc�der plus pr�cis�ment. Comme vous
;  l'avez devin�, ceci est un commentaire.

(write (+ 2016 (* (+ 22 1) (/ 14 (- 9 2)))))  ;  (*)

(newline)
(write "Hello world!")
(newline)
(display "Hello world!")
(newline)

(write ((lambda (x y) (* x y y)) 2016 2015))  ;  (**)

(newline)

(define crash          ;  (***)  Pour bien montrer que Scheme n'�value pas sous
  (lambda () (/ 0)))   ;  la forme sp�ciale "lambda".

(define derive-wrt
  (lambda (f1 h)
    (lambda (x) (/ (- (f1 (+ x h)) (f1 x)) h))))

(write ((derive-wrt (lambda (x) (* x x)) 0.0001) 2))
(newline)

(write ((derive-wrt + 0.0001) 2))  ;  (****)

(define fact
  (lambda (n) (if (zero? n) 1 (* n (fact (- n 1))))))

(newline)
(write (fact 6))
(newline)

(define pi (* 4 (atan 1)))  ;  "atan" est la fonction "Arc tangente" en Scheme.

(define power
  (lambda (U I f0) (* U I (cos (* 2 pi f0)))))

(define fq->power
  (lambda (f0)
    (let ((coefficient (cos (* 2 pi f0))))
      (lambda (U I) (* coefficient U I)))))

(define expr1 (+ (* 4.1 9.8) (/ (* 2 pi) 3)))

(define expr2 (+ (exp pi) (log (sin 2.1)) (sin (+ (/ 1 pi) pi))))

(write expr1)
(newline)
(write expr2)
(newline)

(write 2016)
(newline)
(write (lambda () 2016))
(newline)
(write ((lambda () 2016)))
(newline)
;(write ((derive-wrt (lambda (x y) (+ (* 2 x) y)) 0.0001) 2))
;(newline)

(define volume-at
  (lambda (t V0 lambda-b)
    (* V0 (+ 1 (* lambda-b t)))))

(define body->volume-at
  (lambda (lambda-b)
    (lambda (t V0)
      (* V0 (+ 1 (* lambda-b t))))))

(define gas-volume-at
  (body->volume-at (/ 273.15)))
(write (gas-volume-at 30 1))
(newline)

(define average-with
  (lambda (x)
    (lambda(y)
      (/ (+ x y) 2))))

(define average-with-ten (average-with 10))

(define average
  (lambda (x y)
    (/ (+ x y) 2.0)))

(write (average 10 5))
(newline)

(define close-enough?
  (lambda (x y epsilon)
    (< (abs (- x y)) epsilon)))

(write (close-enough? 2.0 2.1 0.5))
(newline)
(write (close-enough? 2.0 2.1 0.01))
(newline)

(define dichotomy
  (lambda (f1 r1 r2 epsilon)
    ;;
    (define look-for-root
      (lambda (f1 negative-point positive-point epsilon)
        (let ((middle-point (average negative-point positive-point)))
          (if (close-enough? negative-point positive-point epsilon)
              middle-point
              (let ((middle-point-image (f1 middle-point)))
                (cond ((negative? middle-point-image)
                       (look-for-root f1 middle-point positive-point epsilon))
                      ((positive? middle-point-image)
                       (look-for-root f1 negative-point middle-point epsilon))
                      (else middle-point)))))))
    ;;
    (let ((r1-image (f1 r1))
          (r2-image (f1 r2)))
      (if (negative? (* r1-image r2-image))
          (if (negative? r1-image)
              (look-for-root f1 r1 r2 epsilon)
              (look-for-root f1 r2 r1 epsilon))
          (begin
            (display "Can't, sorry, folks")
            (newline)
            #t)))))

(write (dichotomy (lambda (x) (- (* x x) 2)) 1.0 2.0 1e-4))