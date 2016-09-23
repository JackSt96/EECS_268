
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

		start = std::chrono::system_clock::now();


		sort(arr, size);

		end = std::chrono::system_clock::now();
		elapsed = (end - start);
		return elapsed.count();
	}

	template<typename T>
	void Sorts<T>::quickSortWithMedian(T arr[], int size)
	{

		quickSortRec(arr, 0, size-1, true);
	}

	template<typename T>
	void Sorts<T>::quickSort(T arr[], int size)
	{

		quickSortRec(arr, 0, size-1, false);
	}


	template<typename T>
	void Sorts<T>::mergeSort(T arr[], int size)
	{
	if(size<=1){
		return;
	}
	int leftSize = (size/2);
	int rightSize = (size-leftSize);
	T* left = arr;
	T* right = (arr+leftSize);
	mergeSort(left, leftSize);
	mergeSort(right, rightSize);
	merge(left, right, leftSize, rightSize);
	assert(Sorts<T>::isSorted(arr, size));
	}


	template<typename T>
	void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
	{
		if(size1+size2 <= 1){
		return;
	}
	T* tempArr = new T[size1+size2]; //dynamically created, because this is a static method.
	int ix=0;
	int iy=0;
	int currentIndex = 0;
	while(ix<size1 && iy<size2){//until we reach the end of one half

		if(*(a1+ix)>*(a2+iy)){
			tempArr[currentIndex] = *(a2+iy);
			iy++;
		}
		else{
			tempArr[currentIndex] = *(a1 +ix);
			ix++;
		}
		currentIndex++;
	}

	while(ix<size1){//this never executes if the first half finishes first
		tempArr[currentIndex] = *(a1+ix);
		ix++;
		currentIndex++;
	}
	while(iy<size2){//this never executes if the second half finishes first
		tempArr[currentIndex] = *(a2+iy);
		iy++;
		currentIndex++;
	}
	for(int i = 0; i<(size1+size2); i++){

		a1[i] = tempArr[i];

	}
	delete [] tempArr;

	}

	template<typename T>
	void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median){

	if(median && ((last+1)<3)){//base case, amended for use with median
		selectionSort(arr, (last+1));
		return;
	}
	if(first<last){
		int pivot = partition(arr, first, last, median);
		quickSortRec(arr, first, (pivot-1), median);
		quickSortRec(arr, (pivot+1), last, median);
		return;
	}

}

	template<typename T>
	void Sorts<T>::setMedianPivot(T arr[], int first, int last)
	{
	int mid = (last+1)/2;
	T temp [] = {arr[first], arr[mid], arr[last]};
	selectionSort(temp, 3);
	if(arr[first]==temp[1]){//if middle value is in first index
		swap(arr, mid, last);//place first at the end
	}
	else if(arr[mid]==temp[1]){
		swap(arr, mid, last);//place middle at the end
	}
	//else do nothing, the last is already at the end


}


	template<typename T>
	int Sorts<T>::partition(T arr[], int first, int last, bool median)
	{
		int pivotIndex = last;
	int leftIndex=first;
	int rightIndex = (pivotIndex-1);
	if(median){
		setMedianPivot(arr, first, last);
	}
	bool notDone = true;
	while(notDone){
			while((arr[leftIndex]<arr[pivotIndex])&&(leftIndex<(last+1))){
				leftIndex++;
			}
			while((arr[rightIndex]>= arr[pivotIndex])&&(rightIndex>0)){
				rightIndex--;
			}
			if(leftIndex<rightIndex){
				swap(arr, leftIndex, rightIndex);
			}
			else{
				notDone = false;
				swap(arr, leftIndex, pivotIndex);

			}

	}

	return leftIndex;

	}



#endif
