;;;
;;;  Выделить первую цифру натурального N
;;;
(defun firstNumberN( N)
	(cond 
		(
			(< N 10) (print "первое число") N
		) 
		(T
			(firstNumberN (truncate N 10))
		) 
	)
)

;;;
;;;  Получить все делители натурального N
;;;
(defun devidersNumberN(N)
	(devidersNumberNin N 1)
)

(defun devidersNumberNin(N d)
	(cond 
		(
		    (< (/ N 2) d) 
			(list N)
		)
		(
			( = 0 (rem N d))  (cons d (devidersNumberNin N (+ d 1)))
		)
		(T
			(devidersNumberNin N (+ d 1))
		) 
	)
)

;;;
;;;  Подсчитать число и сумму цифр целого N
;;;
(defun countAndSumN(N)
	(cond 
		(
			(< N 10) (cons 1 (rem N 10)) ;;
		) 
		(T
			 (cons (+ 1 (car (countAndSumN (truncate N 10)))) 
				   (+ (rem N 10) (cdr (countAndSumN (truncate N 10))))
				)
		) 
	)
)


;;;
;;;  Найти все общие делители натуральных M и N
;;;
(defun allDelNM(N M)
	
	(allDelNMin N M 1)
)

(defun allDelNMin(N M d)
	(cond 
		(
		    (< N d) 
			nil
		)
		(
		    (< M d) 
			nil
		)
		(
			( = (rem N d) (rem M d) 0) (cons d (allDelNMin N M (+ d 1)))
		)
		(T
			(allDelNMin N M (+ d 1))
		) 
	)
)

;;;
;;;  Найти нибольший общий делитель чисел из заданного списка
;;;

(defun NOD(_list)
	(NODin _list (_min _list))
)

(defun NODin(_list d)
	(cond 
		(
		    (= d 1) 
			(list 1)
		)
		(
			( = 0 (remlist _list d))  d
		)
		(T
			(NODin _list (- d 1))
		) 
	)
)

(defun remlist (_list del)
	(cond 
		(
			(null (car _list)) 0
		)
		(
			(=  (rem (car _list) del) 0)
			(remlist (cdr _list) del)
		)
		(
			T
			1
		)		
	)
)

(defun _min(_list)
	(mmin _list (car _list))
)

(defun mmin(_list Mil)
	(cond 
		(
			(null (car _list)) Mil
		)  
		( 
			(< (car _list) Mil) (mmin (cdr _list) (car _list))
		)
		(
			T (car _list) (mmin (cdr _list) Mil)
		)
	)
)


;(defun cs(N)
;	(cond 
;		(
;			(< N 10) (rem N 10) ;;
;		) 
;		(T 
;			(+ (rem N 10) (cs (truncate N 10)))
;				
;		) 
;	)
;)