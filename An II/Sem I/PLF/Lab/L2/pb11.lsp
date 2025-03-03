(defun get-level (tree level)
  (cond
    ((null tree) nil)
    ((= level 0) (list (car tree))) 
    (t (append (get-level (cadr tree) (- level 1)) 
               (get-level (caddr tree) (- level 1)))))) 

;;get-level(l1,...,ln, nivel) = vida, daca arbore = null
;;                          l1, daca nivel = 0
;;                          get-level(stang(l1...ln), nivel-1) + get-level(drept(l1...ln), nivel-1)

(defun _max-level (tree max lvl level-max)  
  (cond
    ((null (get-level tree lvl)) (cons level-max max)) 
    ((> (length (get-level tree lvl)) (length max)) (_max-level tree (get-level tree lvl) (+ lvl 1) lvl)) 
    (t (_max-level tree max (+ lvl 1) level-max)))) 

;;l - reprezentarea sub forma de lista a arborelui, max - lista de noduri cu numar maxim, nivel - nivelul actual, nivel-maxim - nivelul maxim
;;_max-level(l1...ln,max, nivel, nivel-maxim) =  (nivel-maxim, max) , daca get-level(l1...ln, nivel) = nill
;;                                              _max-level(l1...ln, get-leveL(l1...ln, nivel), nivel+1, nivel), daca lungime(max) < lungime(get-level(l1...ln, nivel))
;;                                              _max-level(l1...ln,max, nivel+1, nivel-maxim), altfel

(defun max-level (tree)
  (_max-level tree '() 0 0))

(defun print-max-level (tree)
    (print (car (max-level tree))) 
    (print (cdr (max-level tree)))
) 

(print-max-level '(1 (2 (3) (4)) (5 (6) (7))))
(terpri)

(print-max-level '(1 (2 (3 () (4 (5) (6))) (7 (8 (9) (10)) (11 (12) (13)))) (14)))
(terpri)

(print-max-level '("A" ("B" ("H" () ("I" ("J")))) ("C" ("D" ("F" ("K")) ("G")) ("E"))))
(terpri)

(print-max-level '(1 (2)))
(terpri)
