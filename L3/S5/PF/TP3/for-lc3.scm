#!r6rs

(import (rnrs))

(define (writeln/return x)
  (write x)
  (newline)
  x)

;;  Start

(writeln/return (cons 0 1))
(writeln/return (cons 0.1 0.1))
(writeln/return (cons (cons 0.1 0.1) 1))
(writeln/return (cons 0.1 '()))
;;(writeln/return (cons '()) 0.1)
(writeln/return (cons '() '()))
(define current-year 2016)
(define next-year (+ current-year 1))
(define academic-year (cons current-year next-year))
(define academic-year-0 (cons current-year 'next-year))
(define academic-year-1 (cons 'current-year 'next-year))
(define operations (cons + -))
(define symbols (cons '+ '-))
(define two-numbers (cons 0 1))
(define something (cons (cons 0.1 0.1) 1))

(writeln/return academic-year)
(writeln/return (quote academic-year))
(writeln/return 'academic-year)
(writeln/return 'undefined)
;;  (writeln/return undefined)
(writeln/return +)
(writeln/return '+)
;;  (writeln/return (0 . 1))
(writeln/return '(0 . 1))
;;  (writeln/return (+ . 1))
(writeln/return '(+ . 1))
(writeln/return (car academic-year))
(writeln/return (cdr academic-year))
;;  (writeln/return (car next-year))
(writeln/return academic-year-0)
(writeln/return (cdr academic-year-0))
(writeln/return academic-year-1)
(writeln/return ((car operations) (car two-numbers) (cdr two-numbers)))
;;  (writeln/return ((cdr symbols) (cdr two-numbers) (car two-numbers)))
(writeln/return (cons (cdr symbols) (car two-numbers)))
(writeln/return (cons (cdr operations) (cdr two-numbers)))
(writeln/return ((cdr operations) (cdr two-numbers)))
(writeln/return (car something))
(writeln/return (cdr (car something)))
;;  (writeln/return (car (cdr something)))

;; Playing with Pairs
;;(define v (cons v1 v2))
;;(define w (cons w1 w2))
(define scal-prod 
  (lambda (v w)
    (+ (* (car v) (car w)) (* (cdr v) (cdr w)))))

(define A (cons 1.0 2.0))
(define B (cons 2.0 1.0))

(writeln/return (scal-prod A B))

;;  (writeln/return '(A . ((String . ()) . ((() . of) . (Pearls . ())))))
;;  (writeln/return '((In . ()) . (() . the) . (Mood . ())))
;;  (writeln/return
;;   '((Walk . ((() . ()) . on)) . ((() . the) . ((Wild . (Side . **)) . ()))))

(writeln/return
 (cons (list 'Walking 'on 'the 'Moon) '()))

(writeln/return (list 'Keep (cons 'it '(up))))

(writeln/return
 (list (list 'Just 'a)
       (cons 'cast (cons 'away '()))))

(writeln/return
 (append (list 'I 'hope) (append '(that) '(someone))
         (cons 'gets '(my))))

(writeln/return
 (cons 'Message
       (append '((in a)) (list 'Bottle))))

;;;  ==========================================================================
;;;  Mini data bases

;;;  Constructor

(define (mk-work key-0 title-0 kind-0 year-0 special-effect? other-version?)
  ;; SYMBOL,STRING,SYMBOL,INTEGER,union(SYMBOL,{#f}),LOGICAL-VALUE -> WORK
  (list key-0 title-0 kind-0 year-0 special-effect? other-version?))

(define schnittke-works
  (list (mk-work 's1977 "Concerto Grosso No 1" 'orchestra 1977 'prepared-piano #t)
        (mk-work 's1972 "Suite in the Old Style" 'chamber/solo 1972 #f #t)
        (mk-work 's1993 "Symphony No 7" 'orchestra 1993 #f #f)
        (mk-work 's1986 "Peer Gynt" 'opera/ballet 1986 #f #t)
        (mk-work 's1979 "Symphony No 2 St Florian" 'orchestra 1979 #f #f)
        (mk-work 's1992 "Life with an Idiot" 'opera/ballet 1992 #f #f)
        (mk-work 's1985 "Concerto for Mixed Chorus" 'choral/vocal 1985 #f #f)
        (mk-work 's1985a "String Trio" 'chamber/solo 1985 'qt #t)
        (mk-work 's1984 "Concerto No 4 for Violin" 'orchestra 1984 'qt #f)
        (mk-work 's1992a "Concerto Grosso No 2" 'orchestra 1982 #f #f)
        (mk-work 's1980 "Gogol Suite" 'orchestra 1980 #f #f)
        (mk-work 's1971 "Double Concerto for Oboe, Harp and Strings" 'orchestra 1971 'play/sing #f)
        (mk-work 's1968 "Pianissimo" 'orchestra 1968 #f #f)
        (mk-work 's1980a "3 Madrigals" 'vocal/choral 1980 #f #f)
        (mk-work 's1985b "Ritual" 'orchestra 1985 #f #f)))

(define part-works
  (list (mk-work 'p1971 "An den Wassern zu Babel" 'choral/vocal 1971 #f #f)
        (mk-work 'p1986 "Arbos" 'chamber/solo 1986 #f #t)
        (mk-work 'p1977 "Fratres" 'chamber/solo 1977 #f #t)
        (mk-work 'p1994 "Litany" 'choral/vocal 1994 #f #f)
        (mk-work 'p1991 "Summa" 'chamber/solo 1991 #f #t)
        (mk-work 'p1969 "Symphony No 1" 'orchestra 1969 #f #f)
        (mk-work 'p1977a "Tabula rasa" 'orchestra 1977 'prepared-piano #f)
        (mk-work 'p1984 "Es sang vor langen Jahren" 'choral/vocal 1984 #f #f)
        (mk-work 'p1977b "Cantus in Memory of Benjamin Britten" 'orchestra 1977 #f #f)
        (mk-work 'p1980 "Pari Intervalo" 'chamber/solo 1980 #f #f)))

(define key car)
(define title cadr)
(define kind caddr)
(define year cadddr)
(define (special-effect work-0) (car (cddddr work-0)))
(define (other-version? work-0) (cadr (cddddr work-0)))

(writeln/return (memq 'a (list 'a 'b 'c 'd)))
(writeln/return (memq 'lol (list 'a 'b 'c 'd)))
(writeln/return (map special-effect schnittke-works))
(writeln/return (map key schnittke-works))

(define (unique-keys? wk-list)
  (let all-different? ((l (map key wk-list)))
    (if (null? l)
        #t
        (let ((l0 (cdr l)))
          (and (not (memq (car l) l0)) (all-different? l0))))))

(define (get-information key0 sel0 wk-list)
  (if (null? wk-list)
      #f
      (let ((first-wk (car wk-list)))
        (if (eq? (key first-wk) key0)
            (sel0 first-wk)
            (get-information key0 sel0 (cdr wk-list))))))

(writeln/return (get-information 's1992 title schnittke-works))
(writeln/return (get-information 's1971 special-effect schnittke-works))
(writeln/return (get-information 's1995 year schnittke-works))
(writeln/return (get-information 's1986 special-effect part-works))

(define (get-key x0 sel0 wk-list)
  (if (null? wk-list)
      #f
      (let ((first-wk (car wk-list)))
        (if (equal? (sel0 first-wk) x0);;on prend equal? au lieu de eq? car eq? est valable pour des symboles uniquement
            (key first-wk)
            (get-key x0 sel0 (cdr wk-list))))))

(writeln/return (get-key "Summa" title part-works))
(writeln/return (get-key "Sketches" title schnittke-works))

;;;  ==========================================================================
;;;  Merge Sort

(define (mergesort l rel-2?)
  ;;
  ;;  The lexical closure allows local functions to use the order relation
  ;;  "rel-2?".
  (define (merge-2-groups g0 g1)
    (cond ((null? g0) g1)
          ((null? g1) g0)
          (else (let ((first-0 (car g0))
                      (first-1 (car g1)))
                  (if (rel-2? first-0 first-1)
                      (cons first-0 (merge-2-groups (cdr g0) g1))
                      (cons first-1 (merge-2-groups g0 (cdr g1))))))))
  ;;
  (define (merge-groups group-list)
    (if (or (null? group-list) (null? (cdr group-list)))
        group-list
        (cons (merge-2-groups (car group-list) (cadr group-list))
              (merge-groups (cddr group-list)))))
  ;;
  (define (make-groups l0) 
    ;;  "l0" is a non-empty list.
    (let ((first (car l0)))
      (if (null? (cdr l0))
          (list (list first)) 
          (let ((next-groups (make-groups (cdr l0))))
            (if (rel-2? first (cadr l0))
                (cons (cons first (car next-groups)) (cdr next-groups))
                (cons (list first) next-groups))))))
  ;;
  (if (null? l)
      '()
      (let iter-merge-groups ((group-list (make-groups l)))
        (if (null? (cdr group-list))
            (car group-list)
            (iter-merge-groups (merge-groups group-list))))))

(writeln/return (mergesort '(1 5 4 7 8 4 6 0) <=))
(writeln/return (mergesort '(1 5 4 7 8 4 6 0) >=))

(define cp-list-example
  '((5 . 5) (6 . 0) (3 . 3) (6 . 1) (7 . 7) (1 . 1) (6 . 2)))

(define (position x l)
  (let thru ((l0 l)
             (current-position 0))
    (cond ((null? l0) #f)
          ((equal? (car l0) x) current-position)
          (else (thru (cdr l0) (+ current-position 1))))))

(define add-something
  (case-lambda
    ((x) (+ x 1))
    ((x y) (+ x y))))