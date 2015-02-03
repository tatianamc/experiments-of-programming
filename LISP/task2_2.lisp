(defun d1 ()
(setq ls '(1 0 4 -1 4 -3 0 6 7))
;;;(print (car ls))
;;;(print (cdr ls))
(print "исходный список")
(print ls)
(print "1.1 список после удалением первого элемента")
;;;(setq ls (cdr ls))
(print (del_first ls))
(print "1.2 список после удалением последнего элемента")
(print (del_last ls))
(print "2.список после замены нулями отрицательных элементов")
(print (chenge_negative ls))
(print "3. список после удаления нулевых элементов")
(print (delete_zeros ls))
(print "4. дублирование всех вхождений атом в список")
(print (dublicate ls '4))
(print "5. считать количество вхождений атома")
(print (count1 ls '4))
T
)

(defun del_first(_list)
	(cdr _list)
)

(defun del_last(_list)
	(cond 
		((null (cadr _list)) nil)  
		(T (cons (car _list) (del_last(cdr _list))))
	)
)

(defun chenge_negative(_list)
(cond 
		(
			(null _list) nil                       ;(cons a (chng-a (cdr x) a))
		)  
		(
		    (< (car _list) '0) (cons '0 (chenge_negative (cdr _list)))
		)
		(
			T 
		   (cons (car _list) (chenge_negative(cdr _list)))
		)
	)
)

(defun delete_zeros(_list)
	(cond 
		(
			(null _list) nil
		)  
		(
		    (equal '0 (car _list)) (delete_zeros (cdr _list))
		)
		(
			T 
		   (cons (car _list) (delete_zeros(cdr _list)))
		)
	)
)

(defun dublicate(_list at)
	(cond 
		(
			(null _list) nil
		)  
		(
		    (equal at (car _list))  (cons (car _list) (cons (car _list) (dublicate(cdr _list) at)))
		)
		(
			T 
		   (cons (car _list) (dublicate(cdr _list) at))
		)
	)
)

(defun count1(_list at)
	(cond 
		(
			(null _list) nil
			0
		)  
		(
		
		    (eql (car _list) at) (+ 1 (count1 (cdr _list) at))
		)
		(
			T 
		   (count1 (cdr _list) at)
		)
	)
)
