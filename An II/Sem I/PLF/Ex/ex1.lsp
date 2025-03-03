(defun inlocuire(a e nivel)
  (cond
    ((AND (atom a) (equal (mod nivel 2) 1) e))
    ((AND (atom a) (equal (mod nivel 2) 0) a))
    (t
      (mapcar #'(lambda(X)
        (inlocuire X e (+ 1 nivel)))a
      )
    )
  )
)

(print(inlocuire '() -1 -1))

(defun Fct(X) #'(lambda(y)(mapcar y (cddr X))))
(print(funcall (Fct(QUOTE((1)(2)(3)(4)))) #'CAR))

(print(cdr'((3) (4))))

(defmacro F(X Y)(SET X (+ Z 1)))
(SETQ Y 1)
(SETQ X 'Y)
(SETQ Z 1)
(F Y Z)
(print Y)