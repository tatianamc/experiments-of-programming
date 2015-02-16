package by.nesterione.experiments.core.concurents.forkfr;

import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;


public class SimpleForkJoin {
	public static void main(String[] args) {
		//создать пул задач
		ForkJoinPool fjp = new ForkJoinPool();
		double[] nums = new double[100000];
		for(int i = 0; i < nums.length; i++) {
			nums[i] = i;
		}
		
		System.out.println("A portion of the original");
		for(int i = 0 ; i<10;i++) {
			System.out.println(nums[i]);
		}
		
		SqrtTransform task = new SqrtTransform(nums, 0, nums.length);
		//запуситить главный ForkJoinTask
		fjp.invoke(task);
		
		System.out.println("A portion of the transformed^");
		for(int i = 0 ; i<10;i++) {
			System.out.println(nums[i]);
		}
	}
}

//Пример стротегии "разделяй и властуй"
class SqrtTransform extends RecursiveAction {
	// Пороговое значение взятое с головы
	final int seqThreshold = 1000;
	
	double[] data;
	
	//Определяет часть обрабатываемых данных
	int start, end;
	
	SqrtTransform(double[] vals, int start, int end) {
		this.data = vals;
		this.start = start;
		this.end = end;
	}
	
	// Осуществляет паралельное вычисление
	protected void compute() {
		//Если количество элементов ниже порогового
		//то выполнить обработку последовательно
		if((end-start)< seqThreshold) {
			//Преобразовать каждый элемент в его квадратный корень
			for(int i = start; i < end; i++) {
				data[i] = Math.sqrt(data[i]);
			}
		} else {
			//Иначе продолжить разделение на подзадачи
			int middle = (start + end) / 2;
			
			//Запусить новые задачи, используя разделеннные на 
			// части данные 
			invokeAll(new SqrtTransform(data, start, middle),
					new SqrtTransform(data, middle, end));
		}
	}
}
