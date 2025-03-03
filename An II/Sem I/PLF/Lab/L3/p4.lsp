;;suma-atomilor(l1...ln) = 0 daca l atom
                          ;;l1 daca l1 numar
                          ;;Z suma-atomilor(li) i=1..n


(defun suma-atomilor (lst)
  (cond 
    ((numberp lst) lst)
    ((atom lst) 0)
    (t (apply #'+ (mapcar #'suma-atomilor lst)))
  )
)

(print (suma-atomilor '(1 (2 3) (4 (5 6)) 7)))
(print (suma-atomilor '(1 (a b) (2 (3 x)) 4)))
(print (suma-atomilor '()))
