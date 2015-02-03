;____________________________Задание 1_______________________________;
; Удалить первый и последний элемент без учета скобок                ;
;____________________________________________________________________;
(defun t321 (inList)
	(Reversing 
		(delFirst 
			(Reversing
				(delFirst inList)
			)
		)
	)
)

(defun delFirst(inList)
	(cond
		(
			(eq (atom (car inList)) nil)
			(append 
				(delFirst (car inList)) 
				(cons (cdr inList) nil)
			)
		)	
		(
			t
			(cdr inList)
		)
	)
)

;____________________________Задание 2_______________________________;
; Произвольный список вида (a1,a2, ak) разбить на два подсписка      ;
; (a1,a3,a5...) и (a2,a4,a6...)                                      ;
;____________________________________________________________________;
(defun t322(inList)
   (cons (fList 1 inList) (cons(sList 1 inList) nil))
)

(defun fList(idx inList)
	(cond
		(
			(null (car inList)) 
			nil
		)
		(
			(eq (rem idx 2) 0)   
			(fList (+ idx 1) (cdr inList))  
		)
		(
			t   
			(cons (car inList)  (fList (+ idx 1) (cdr inList)))  
		)
	)
)

(defun sList(idx inList)
	(cond
		(
			(null (car inList)) 
			nil
		)
		(
			(eq (rem idx 2) 0) 
			(cons (car inList)  (sList (+ idx 1) (cdr inList)))
		)
		(
			t   
			(sList (+ idx 1) (cdr inList))
		)
	)
)

;____________________________Задание 3_______________________________;
; Из произвольного списка удалить все отрицательные элементы         ;
;____________________________________________________________________;
(defun t323(inList)
	(delNegative inList)
)

(defun delNegative(inList)
	(cond
		(
			(atom inList) 
			inList
		)
		( 
			(and (numberp (car inList)) (< (car inList) 0) (atom (car inList)))
			(delNegative (cdr inList))
		)
		(	
			t 
			(cons (delNegative (car inList)) (delNegative (cdr inList)))
		)
	)
)

;____________________________Задание 4_______________________________;
; Реверсировать произвольный список (включая подсписки)              ;
;____________________________________________________________________;
(defun t324(inList)
	(Reversing inList)
)

(defun Reversing(inList)
	(cond
		(
			(atom inList) 
			inList
		)
		(
			t
			(append 
				(Reversing (cdr inList)) 
				(cons 
					(
						Reversing (car inList)
					) 
					nil
				)
			)
		)
	)
)
;____________________________Задание 5_______________________________;
; Из произвольного списка удалить все латинские буквы, расположенные ;
; между буквами d и k                                                ;
;____________________________________________________________________;
(defun t325(inList)
	(delLiterals inList)
)
(defun delLiterals(inList)
	(cond
		(
			(atom inList) 
			inList
		)
		(
			(eq (atom (car inList)) nil)
			(append
			(cons (delLiterals (car inList)) nil)
			(delLiterals (cdr inList))
			)
		)
		(
			(and (char< #\d (car inList)) (char> #\k (car inList)))
				(delLiterals (cdr inList))
		)
		(
			t
			(cons (car inList) (delLiterals (cdr inList)))
		)
	)
)