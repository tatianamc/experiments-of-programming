;____________________________Задание 1_______________________________;
; Проверить, являеться ли список списком чисел, или нет              ;
;____________________________________________________________________;
(defun t41(inList)
	(cond
		(
			(atom inList) 
			t
		)
		(
			(eq (atom (car inList)) nil)
			(and 
				(t41 (car  inList)) 
				(t41 (cdr inList))
			)
		)
		(
			(numberp (car inList)) 
			(t41 (cdr inList))
		)
		(
			t 
			nil
		)
	)
)

;____________________________Задание 2_______________________________;
; В списке чисел найти значение наименьшего из положительных чисел   ;
;____________________________________________________________________;
(defun t42(inList)
	(minPositive inList (firstPos inList))
)

(defun firstPos(inList)
	(cond 
		; (
			; (atom inList) 
			; (car inList)
		; )
		(
			(> (car inList) 0)
			(car inList) 
		)
		(
			t 
			(firstPos (cdr inList))
		)
	)
)

(defun minPositive(inList minPos)
	(cond 
		(
			(atom inList) 
			minPos
		)
		(
			(and (> (car inList) 0) (> minPos (car inList))) 
			(minPositive (cdr inList) (car inList)) 
		)
		(
			t 
			(minPositive (cdr inList) minPos)
		)
	)
)
;____________________________Задание 3_______________________________;
; Проверить, являеться ли простой список чисело монотонной           ;
; последовательностью                                                ;
;____________________________________________________________________;
(defun t43(inList) 
	(or 
		(incSequence (car inList) (cdr inList)) 
		(decSequence (car inList) (cdr inList))
	) 
)

(defun incSequence(ls inList)
	(cond
		(
			(atom inList) 
			t
		)
		(
			(eq (atom (car inList)) nil)
				(and (incSequence ls (car inList))
				(incSequence (las (Reversing inList)) (cdr inList)))
		)
		(
			(<= ls (car inList)) 
			(incSequence (car inList) (cdr inList))
		)
		(
			t 
			nil
		)
   )
)

(defun las(inList)
	(cond
		(
			(atom inList) 
			inList
		)
		(
			(eq (atom (car inList)) nil) 
			(las (car inList))
		)
		(
			t
			(car inList)
		)
	)
)

(defun decSequence(ls inList)
	(cond
		(
			(atom inList) 
			t
		)
		(
			(eq (atom (car inList)) nil)
				(and (decSequence ls (car inList))
				(decSequence (las (Reversing inList)) (cdr inList)))
		)
		(
			(>= ls (car inList)) 
			(decSequence (car inList) (cdr inList))
		)
		(
			t 
			nil
		)
	)
)

(defun Reversing(sp)
	(cond
		(
			(atom sp) 
			sp
		)
		(
			t
			(append 
				(Reversing (cdr sp)) 
				(cons 
					(
						Reversing (car sp)
					) 
					nil
				)
			)
		)
	)
)
;____________________________Задание 4_______________________________;
; Слить два упорядоченных по возрастанию списка чисел в один список  ;
;____________________________________________________________________;
(defun t44(inList1 inList2)
	(combine inList1 inList2)
)

(defun combine(inList1 inList2)
    (cond
		(
			(atom inList1) inList2 
		)
		(
			(atom inList2) inList1 
		)
		(
			(<= (car inList1) (car inList2)) 
			(cons (car inList1) (combine (cdr inList1) inList2))
		)
		(
			t
			(cons 
				(car inList2) (combine inList1 (cdr inList2))
			)
		)
    )
)

;____________________________Задание 5_______________________________;
; Дан список (a1,a2,..., aN). Вычислить значение max(a2,a4,...) +    ;
; + min(a1,a3,...).                                                  ;
;____________________________________________________________________;
(defun t45(inList)
	(+ 	(minUneven inList (car inList))
		(maxUneven (cdr inList) (cadr inList))
	)
)

(defun minUneven(inList minVal)
	(cond
		(
			(null (car inList)) 
			minVal
		)
		(
			(< (car inList) minVal)   
			(minUneven (cddr inList) (car inList)) 
		)
		(
			t   
			(minUneven (cddr inList) minVal) 
		)
	)
)

(defun maxUneven(inList maxVal)
	(cond
		(
			(null (car inList)) 
			maxVal
		)
		(
			(> (car inList) maxVal)   
			(maxUneven (cddr inList) (car inList)) 
		)
		(
			t   
			(maxUneven (cddr inList) maxVal) 
		)
	)
)
;____________________________Задание 6_______________________________;
; Дано А и натуральное N. Вычислить выражение A*(A-N)*(A-2*N)*(A-N^2);
;____________________________________________________________________;
(defun t46(A N)
	(* (* A (- A N)) (* (- A (* 2 N)) (- A (* N N)) ) )
)

;____________________________Задание 7_______________________________;
; Дано X и натуральное N. Вычислить sin(X), используя разложение в   ;
; ряд Тейлора. В разложении учитывать N членов ряда.                 ;
;____________________________________________________________________;
(defun t47(A N)
	(Summary (teilor A N 0) 0)
)
(defun pow(A pw)
	(cond
		(
			(eq pw 0) 
			1
		)
		(
			(eq pw 1) 
			A
		)
		(
			t 
			(* A (pow A (- pw 1)))
		)
	)
)
(defun fact(n) 
	(cond 
		(
			(zerop n) 
			1
		) 
		(
			t 
			(* n (fact (- n 1))))
		)
)

(defun teilor(A N index)
	(cond   
		(
			(< index N)
			(cons 
				(/ (* (pow -1 index) (pow A (+ (* 2 index) 1)) ) (fact (+ (* 2 index) 1))) 
				(teilor A N (+ index 1)) 
			)
		)
	)
)

(defun summary(inList sum)
	(cond
		(
			(atom inList) sum
		)
		(
			t 
			(summary (cdr inList) (+ sum (car inList))) 
		)
	)
)  
;____________________________Задание 8_______________________________;
; Вычислить с заданной точностью EPS выражение 1-1/2+1/3+1/4+...     ;
;____________________________________________________________________;
(defun t48(eps)
	(print (fn_t48 eps 1))
	(Summary (fn_t48 eps 1) 0)
)

(defun fn_t48(eps idx)
	(cond
		(
			(> (/ 1.0 idx) eps)
			(cons 
				(/ (pow -1.0 (- idx 1)) idx) 
				(fn_t48 eps (+ idx 1)) 
			)
		)
		(
			t 
			nil
		)
	)
)

;____________________________Задание 9_______________________________;
; Методом дихотомии (половинного деления) найти корень уравнения     ;
; x+ln(x+0.5)- 0.5 = 0 на отрезке [0, 2] с заданной точностью EPS.   ;
;____________________________________________________________________;
(defun t49(eps)
(decision eps 0 2 0)
)
(defun decision(eps a b c)
	(cond
        (
			(> (- b a) eps)
			(cond
				(
					(= (Func (/ (- b a) 2.0)) 0) 
					(decision eps a (/ (- b a) 2.0) (/ (- b a) 2.0))
				)
				(
					t 
					(decision eps (/ (- b a) 2.0) b (/ (- b a) 2.0))
				)
			)
        )
		(
			t 
			c
		)
    )
)
(defun Func(x)
   (- (+ x (log (+ x 0.5))) 0.5)
)
;___________________________Задание 10_______________________________;
;Найти произведение всех ненулевых чисел из заданного сложного списка;
;____________________________________________________________________;
(defun t410(inList)
(mul inList)
)
(defun mul(inList)
	(cond
		(
			(atom inList) 
			1
		)
		(
			(eq (atom (car inList)) nil) 
			(* (mul (car inList)) (mul (cdr inList)))  
		)
		(
			t
			(if (/= (car inList) 0)
				(* (car inList) (mul (cdr inList)) ) 
				(* 1 (mul (cdr inList)) ) 
			)
		)
    )
)