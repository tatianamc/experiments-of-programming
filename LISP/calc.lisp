(defun calc()
	(print "Калькулятор")
	(print "______________________________")
	(print "| Поддерживаемые операции:   |") 
	(print "|____________________________|")
	(print "|     op1 + op2              |")
	(print "|     op1 - op2              |")
	(print "|     op1 * op2              |")
	(print "|     op1 / op2              |")
	(print "|     sin (op1)              |")
	(print "|     cos (op1)              |")
	(print "|     tan (op1)              |")
	(print "|     ctan (op1)             |")
	(print "|____________________________|")
	(print "")
	(print "Для вычисления введите выражение")
	(print "отделяя числа и знаки операций пробелом")
	(print "Пример ввода:")
	(print "(2 + 7 - 9 / 3 + sin ( 1 + 4) + sin (cos (2)))")
	
	(loop
		(print "вычислить >>")
		(let ((ls (read)))   
			(print "Результат") 
			(print (cal ls))
		)
	)
)
; (expt x (/ 1 n))
(defun isFunc(fn)
	(cond
		(
			(eq fn 'sin)
			t
		)
		(
			(eq fn 'cos)
			t
		)
		(
			(eq fn 'tan)
			t
		)
		(
			(eq fn 'ctan)
			t
		)
		(
			t
			nil
		)
	)
)

(defun calcFunc(fn ls)
	(cond
		(
			(eq fn 'sin)
			(cal (sin1  ls))
		)
		(
			(eq fn 'cos)
			(cal (cos1  ls))
		)
		(
			(eq fn 'tan)
			(cal (tan1  ls))
		)
		(
			(eq fn 'ctan)
			(cal (ctan1  ls))
		)
		(
			t
			nil
		)
	)
)

(defun cal(ls)
  ; (print ls)
	(cond
		(
			(atom ls)
			ls
		)
		(
			(atom (cdr ls))
			(car ls)
		)
		(
			(eq (atom (car ls)) nil)
			(cal (cons (cal (car ls)) (cdr ls)))
		)
		(
			(eq (car ls) 'sin)
		    (cal (cons (sin1 (cdr ls)) (cddr ls)))
		)
		(
			(eq (car ls) 'cos)
			(cal (cons (cos1 (cdr ls)) (cddr ls)))
		)
		(
			(eq (car ls) 'tan)
			(cal (cons (tan1 (cdr ls)) (cddr ls)))
		)
		(
			(eq (car ls) 'ctan)
			(cal (cons (ctan1 (cdr ls)) (cddr ls)))
		)
		(
			(eq (cadr ls) '*)
			(cal (mul1 ls))
		)
		(
			(eq (cadr ls) '/)
			(cal (div1 ls))
		)
		(
			(or (eq (cadddr ls) '*) (eq (cadddr ls) '/))
			(cond
				(
					(eq (cadddr ls) '*)
					(cal (cons (car ls) (cons (cadr ls) (cons (mul1 (cddr ls)) nil))))
				)
				(
					(eq (cadddr ls) '/)
					(cal (cons (car ls) (cons (cadr ls) (cons (div1 (cddr ls)) nil))))
				)
			)
		)
		(
			(eq (cadr ls) '+)
			(add1 ls)
		)
		(
			(eq (cadr ls) '-)
			(sub1 ls)
		)
	)
)

(defun add1(ls)
	(cond
		(
			(eq (atom (caddr ls)) nil)
			(cal (cons (+ (car ls) (cal (caddr ls)) ) (cdddr ls)))
		)
		(
			(eq  (isFunc (caddr ls)) t)
			(cal (cons (+ (car ls) (calcFunc (caddr ls) (cdddr ls))) (cddddr ls)))
		)
		(
			(numberp (caddr ls))
			(cal (cons (+ (car ls) (caddr ls)) (cdddr ls)))
		)
		
		(
			t
			"Ошибка add: неправильное выражение"
		)
	)
)
(defun sub1(ls)
	(cond
		(
			(eq (atom (caddr ls)) nil)
			(cal (cons (- (car ls) (cal (caddr ls)) ) (cdddr ls)))
		)
		(
			(eq  (isFunc (caddr ls)) t)
			(cal (cons (- (car ls) (calcFunc (caddr ls) (cdddr ls))) (cddddr ls)))
		)
		(
			(numberp (caddr ls))
			(cal (cons (- (car ls) (caddr ls)) (cdddr ls)))
		)
		(
			t
			"Ошибка sub: неправильное выражение"
		)
	)
)

(defun mul1(ls)
	(cond
		(
			(eq (atom (car ls)) nil)
			(cal (cons (*  ( cal(car ls) ) (cal (caddr ls)) ) (cdddr ls)))
		)
		(
			(eq (atom (caddr ls)) nil)
			(cal (cons (* (car ls) (cal (caddr ls)) ) (cdddr ls)))
		)
		(
			(eq  (isFunc (caddr ls)) t)
			(cal (cons (* (car ls) (calcFunc (caddr ls) (cdddr ls))) (cddddr ls)))
		)
		(
			(numberp (caddr ls))
			(cal (cons (* (car ls) (caddr ls)) (cdddr ls)))
		)
		(
			t
			"Ошибка mul: неправильное выражение"
		)
	)
)

(defun div1(ls)
	(cond
		(
			(eq (atom (car ls)) nil)
			(cal (cons (/  ( cal(car ls) ) (cal (caddr ls)) ) (cdddr ls)))
		)
		(
			(eq (atom (caddr ls)) nil)
			(cal (cons (/ (car ls) (cal (caddr ls)) ) (cdddr ls)))
		)
		(
			(eq  (isFunc (caddr ls)) t)
			(cal (cons (/ (car ls) (calcFunc (caddr ls) (cdddr ls))) (cddddr ls)))
		)
		(
			(numberp (caddr ls))
			(cal (cons (/ (car ls) (caddr ls)) (cdddr ls)))
		)
		(
			t
			"Ошибка div: неправильное выражение"
		)
	)
)

(defun sin1(ls)
	(cond
		(
			(eq (atom (car ls)) nil)
			(sin (cal (car ls))) 
		)
		(
			t
			"Ошибка sin: неправильное выражение"
		)
	)
)

(defun cos1(ls)
	(cond
		(
			(eq (atom (car ls)) nil)
			(cos (cal (car ls)))
		)
		(
			t
			"Ошибка cos: неправильное выражение"
		)
	)
)

(defun tan1(ls)
	(cond
		(
			(eq (atom (car ls)) nil)
			(tan (cal (car ls)))
		)
		(
			t
			"Ошибка tan: неправильное выражение"
		)
	)
)

(defun ctan1(ls)
	(cond
		(
			(eq (atom (car ls)) nil)
			(/ (cos (cal (car ls))) (sin (cal (car ls))))
		)
		(
			t
			"Ошибка ctan: неправильное выражение"
		)
	)
)