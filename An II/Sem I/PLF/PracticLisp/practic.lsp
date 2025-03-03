(defun inverseaza(l)
    (cond
        ((null l) nil)
        (t(append (inverseaza(cdr l)) (list (car l))))
    )
)

(defun succesor(l rest)
    (cond
        ((and (null l) (= rest 0)) nil)
        ((null l) (list rest))
        (t (append
            (list (mod (+ (car l) rest) 10))
            (succesor (cdr l) (cond 
                                (( >= (+ (car l) rest) 10) 1)
                                (t 0)
            ))
        ))
    )
)

(defun succesor_wrapper(l)
    (print (inverseaza(succesor (inverseaza l) 1)))
)

(succesor_wrapper '(1 6 3 5 9 9))
(succesor_wrapper '(1 2 3))
(succesor_wrapper '(9 9))
(succesor_wrapper '(2 1 9))