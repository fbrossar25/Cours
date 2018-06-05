import java.util.Arrays;

public class QuickSort{
	enum SwapType {ARITH, BITWISE, NAIVE};
	
	public static void main(String [] args){
		int n = 1000000;
		int a[] = new int[n];
		int b[] = new int[n];
		for(int i=0; i<n; i++){
			a[i] = (int)((Math.random()-0.5) * Integer.MAX_VALUE);
			b[i] = a[i];
		}
		//System.out.println("Before : "+Arrays.toString(a));
		long begin, end, time = Long.MAX_VALUE;
		SwapType shorter = null;
		boolean isSorted;
		for(SwapType type : SwapType.values()){
			begin = System.nanoTime();
			qSort(a, type);
			end = System.nanoTime();
			
			if(end - begin < time){
				time = end - begin;
				shorter = type;
			}
			
			isSorted = true;
			for(int i=0; i<n-1; i++){
				if(a[i] > a[i+1]){
					isSorted = false;
				}
			}
			
			System.out.println(type.toString() + " time : " +((end - begin)/1000)+"µs -> " + (isSorted ? " Sorted" : " Not Sorted"));
			for(int i=0; i<n; i++){
				a[i] = b[i];
			}
		}
		
		System.out.println(shorter.toString()+" shortest");
	}
	
	public static void qSort(int a[], SwapType type){
		qSort(a, 0, a.length-1, type);
	}
	
	public static void qSort(int a[], int begin, int end, SwapType type){
		if(begin < end){
			int pivot = partition(a, begin, end, type);
			qSort(a, begin, pivot-1, type);
			qSort(a, pivot+1, end, type);
		}
	}
	
	public static int partition(int a[], int begin, int end, SwapType type){
		int pivot = a[end];  
	 
		int i = (begin - 1);
		int tmp;

		for (int j = begin; j < end; j++)
		{
			if (a[j] <= pivot)
			{
				i++;
				swap(a, i, j, type);
			}
		}
		swap(a, i+1, end, type);
		return i + 1;
	}
	
	public static void swap(int a[], int i, int j, SwapType type){
		switch(type){
			case ARITH: swapArith(a, i, j); break;
			case BITWISE: swapBitwise(a, i, j); break;
			default: swapNaive(a, i, j);
		}
	}
	
	public static void swapArith(int a[], int idxA, int idxB){
		if(idxA != idxB){
			a[idxA] = a[idxA] + a[idxB];
			a[idxB] = a[idxA] - a[idxB];
			a[idxA] = a[idxA] - a[idxB];
		}
	}
	
	public static void swapBitwise(int a[], int idxA, int idxB){
		if(idxA != idxB){
			a[idxA] = a[idxA] ^ a[idxB];
			a[idxB] = a[idxA] ^ a[idxB];
			a[idxA] = a[idxA] ^ a[idxB];
		}
	}
	
	public static void swapNaive(int a[], int i, int j){
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}