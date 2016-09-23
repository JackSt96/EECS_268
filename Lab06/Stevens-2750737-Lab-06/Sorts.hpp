
#ifndef SORTS_HPP
#define SORTS_HPP
#include "Sorts.h"

/*	template<typename T>
	static void Sorts<T>::printArray(T arr[], int size)
	{
	  for (int i=0; i<size-1; i++)
	  {  std::cout << array[i] << ', ';}
	  std::cout << array[(size-1)] << ']\n';
	}*/

	template<typename T>
	void Sorts<T>::bubbleSort(T arr[], int size)
	{
	bool swapped = true;
      int j = 0;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < size - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        swap(arr,i,(i+1));
                        swapped = true;
                  }
			}
	}
	  
		assert( Sorts<T>::isSorted(arr, size) );
		

	}
	
	
	template<typename T>
	void Sorts<T>::swap(T arr[], int a, int b)
	{
		T tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
	}
	
	
	template<typename T>
	void Sorts<T>::bogoSort(T arr[], int size)
	{
		std::default_random_engine generator(time(nullptr));
	
	
		while(!(isSorted(arr, size))){
			shuffle(arr, size, generator);
		}
		
		
		assert( Sorts<T>::isSorted(arr, size) );
	}
	
	
	template<typename T>
	void Sorts<T>::insertionSort(T arr[], int size)
	{
		int targetIndex;
		for(int i= 1 ; i<size; i++){ 

			targetIndex = i;			
			while((arr[targetIndex]<arr[targetIndex-1])&&(targetIndex>0)){
				swap(arr, targetIndex, (targetIndex-1));			
				targetIndex--;
			}
		}
		
		assert( Sorts<T>::isSorted(arr, size) );
	}
	
	
	template<typename T>
	void Sorts<T>::selectionSort(T arr[], int size)
	{
		for(int i = 0; i< size; i++){
			T lowValue = arr[i];
			int lowIndex = i;

			for(int j = i; j< size; j++){

				if(arr[j]<lowValue){
					lowValue = arr[j];
					lowIndex = j;
				}
			}
			swap(arr, i, lowIndex);
		}
		
		
		assert( Sorts<T>::isSorted(arr, size) );
	}
	
	
	template<typename T>
	bool Sorts<T>::isSorted(T arr[], int size)
	{
		bool check = true;
		for(int i = 0; i < size-1; i++)
		{
			if(arr[i]<=arr[i+1])
			{
				check = true;
			}
			else
				return false;
		}
		return check;
	}
	
	
	template<typename T>
	void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
	{
		std::uniform_int_distribution<int> distribution(0, size-1);
		int random = distribution(generator);	
		for(int i = 0; i<size; i++)
		{
			swap(arr, i, random);
			random = distribution(generator);
		}
	}
	
	
	template<typename T>
	int* Sorts<T>::createTestArray(int size, int min, int max)
	{
		int* array = new int [size];
		std::default_random_engine generator(time(nullptr));
		std::uniform_int_distribution<int> distribution(min,max);
		for(int i = 0; i <size; i++)
		{
			array[i] = distribution(generator);
		}
		return array;
	}
	
	
	template<typename T>
	double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
	{
		std::chrono::system_clock::time_point start;
		std::chrono::system_clock::time_point end;
		std::chrono::duration<double> elapsed;
	
		std::cout << "Starting bubble sort.\n";
		start = std::chrono::system_clock::now();
		
		
		sort(arr, size);
		
		end = std::chrono::system_clock::now();
		elapsed = (end - start);
		return elapsed.count();
	}
	
	
	
	
#endif