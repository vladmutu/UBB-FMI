(defun cmmdc (a b)
    (cond
        ((= a 0) b)
        ((= b 0) a)
        ((= a b) a)
        ((> a b) (cmmdc (mod a b) b ))
        (t (cmmdc b a ))
    )
)

(defun cmmmc (a b)
    (cond
        ((= a 0) b)
        ((= b 0) a)
        (t (floor (* a b) (cmmdc a b)))
    )
)

(defun cmmmc_list (l e)
    (cond
        ((null l) e)
        ((numberp (car l)) (cmmmc_list (cdr l) (cmmmc e (car l))))
        (t (cmmmc_list (cdr l) e))
    )
)

(defun main (l)
    (cmmmc_list l 1)
)


(write (cmmdc 6 21))
(terpri)
(write (cmmmc 12 7))
(terpri)
(write (main (list 2 2 (list 1 4 5) " " "pufi" 5)))