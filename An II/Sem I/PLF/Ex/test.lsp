;;Se consideră o listă neliniară. Să se scrie o funcţie care să aibă ca rezultat lista iniţială in care atomii de pe nivelul k au fost
;;înlocuiți cu 0 (nivelul superficial se consideră 1). Se va folosi o funcție MAP.
;;Exemplu pentru lista (a (1 (2 b)) (c (d)))
;;a) k=2 => (a (0 (2 b)) (0 (d))) b) k=1 => (0 (1 (2 b)) (c (d))) c) k=4 =>lista nu se modifică

(defun inlocuire(L N K)
    (cond
        ((AND (atom L) (= K N)) 0)
        ((AND (atom L) (not (= K N))) L)
        (T (mapcar #' (lambda(X)
                (inlocuire X (+ N 1) K))
                (L)
        ))
    )
)

;;Să se substituie valorile numerice cu o valoare e dată, la orice nivel al unei liste neliniare. Se va folosi o funcție MAP.
;;Exemplu , pentru lista (1 d (2 f (3))), e =0 rezultă lista (0 d (0 f (0))).

(defun subs(L E)
    (cond
        ((AND (atom L) (numberp L)) E)
        ((AND (atom L) (not(numberp L))) L)
        (t (mapcar #'(lambda(X)
                    (subs X E)
        )L))
    )
)

(print(subs '(1 d (2 f (3))) 0))


(defun inlocuire_arbore (tree lvl e)
  (cond
    ;; Dacă arborele este nil (gol), nu facem nimic
    ((null tree) nil)
    
    ;; Dacă nodul este atom și se află pe nivel impar, îl înlocuim cu `e`
    ((and (atom tree) (= (mod lvl 2) 1))  e)
    
    ;; Dacă nodul este atom dar nu este pe nivel impar, îl păstrăm
    ((atom tree) tree)
    
    ;; Dacă nodul este o listă, procesăm recursiv rădăcina și subarborii
    (t (mapcar #'(lambda (subtree) (inlocuire_arbore subtree (+ lvl 1) e)) tree))))


(print (inlocuire_arbore '(a(b(g)) (c(d(e)) (f))) 1 0))



(defun cauta(l e)
    (cond
        ((null l)NIL)
        ((AND (atom (car l)) (equal (car l) e)) T)
        ((listp (car l))(OR (cauta (car l) e) (cauta (cdr l) e)))
        (T(cauta (cdr l) e))
    )
)

(defun drum(l e)
    (cond 
        ((AND (atom l) (not (equal l e))) nil)
        ((AND (atom l) (equal l e)) e)
        ((AND (listp l) (cauta l e))
            (append(list (car l)) (mapcan #' (lambda(X) (drum X e))l))
        )
    )
)

(print(drum '("A" ("B" ("C") ("D")) ("E")) "D"))

(defun elimina(l niv)
(cond
(
(AND (atom l) (not (numberp l)) (equal (mod niv 2) 1))
l
)
(
(AND (atom l) (not (numberp l)) (equal (mod niv 2) 0))
NIL
)
(
(AND (atom l) (numberp l))
l
)
(T
(mapcar #'(lambda (x)
(
elimina x (+ niv 1)
)
)
l
)
)
)
)

(print (elimina '(1 ("a" (3)  ("c") (4 ("Z")))) 0))