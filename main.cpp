#include <iostream>
#include <chrono>
#include <math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// Insertion Sort

// Selectionsort

// Bubblesort
// swap
// Function that swaps two elements of an array
template <typename T>
void swap(T * pA, T * pB) {
    T temp = *pA;                     //O(1)
    *pA = *pB;                          //O(1)
    *pB = temp;                         //O(1)
}

// bubbleSort
// Sorts array by comparing two neighbor values at a time
template <typename T>
void bubbleSorted (T unordered [], int size) {
    bool swapped = true;    //O(1)
    while (swapped) {       //O(n)
        swapped = false;    //O(1)
        for(int i = 1; i < size; i++) {                 //O(n)
            if(unordered[i] < unordered[i-1]) {         //O(1)
                swap(unordered[i], unordered[i-1]);     //O(1)
                swapped = true;                         //O(n)
            }
        }
    } 
}

// Quicksort
void swapQS(int * posA, int * posB)
{
	int aux = *posA;
	*posA = *posB;
	*posB = aux;
}

int partition(int * & arreglo, int low, int high)
{
	int pivote = arreglo[high];
	int index = (low - 1);
	for(int j = low; j <= high-1; j++)
	{
		if(arreglo[j] <= pivote)
		{
			index++;
			swap(arreglo[j], arreglo[index]);
		}
	}
	swap(arreglo[high], arreglo[index+1]);
	return index+1;
}

void quickSort(int * & arreglo, int low, int high)
{
	if(low < high)
	{
		int pivote = partition(arreglo, low, high);
		quickSort(arreglo, low, pivote -1);
		quickSort(arreglo, pivote + 1, high);
	}
}

// Mergesort
int* split(int* & arr, int lowerBound, int upperBound) {
  int size = upperBound - lowerBound;
  int *res = new int[size];
  for (int i = 0; i < size; i++) {
    res[i] = arr[lowerBound + i];
  }
  return res;
}

void mergeSort(int* & arr, int size) {

  if (size <= 1) {
    return;
  }

  int * arr1 = split(arr, 0, size/2);
  mergeSort(arr1, size/2);

  int * arr2 = split(arr, size/2, size);
  mergeSort(arr2, size - size/2);

  int size1 = size/2;
  int size2 = size - size/2;

  int index1 = 0;
  int index2 = 0;
  int i = 0;

  while (index1 < size1 && index2 < size2) {
    if(arr1[index1] < arr2[index2]) {
      arr[i] = arr1[index1];
      i++;
      index1++;
    } else {
      arr[i] = arr2[index2];
      i++;
      index2++;
    }
  }

  while (i < size) {
    if (index1 < size1) {
      arr[i] = arr1[index1];
      index1++;
    } else {
      arr[i] = arr2[index2];
      index2++;
    }
    i++;
  }

  //print(arr, size);

  delete [] arr1;
  delete [] arr2;
}

// Countingsort
void countingSort(int * & arreglo, int size)
{
    int *arrAux = new int[1000]{};
    int currIndex = 0;

    for (int i = 0; i < size; i++)
    {
        int current = arreglo[i]; // gets the current index value of the input array
        arrAux[current]++; // adds one in the counter array at the position of the number
    }

    for (int j = 0; j < 1000; j++)
    {
        if (arrAux[j] > 0)
        {
            while (arrAux[j] != 0)
            {
                arreglo[currIndex] = arrAux[j];
                arrAux[j]--;
                currIndex++;
            }
        }

        if (currIndex == size)
        {
            break;
        }
    }
}

/*
Bubble Sort(arr, size)
		for i=0 to n-i-1
			for j=0 to n-i-2
				if arr[j]>arr[j+1]
					Swap arr[j] and arr[j+1]

*/

void fill_random(int * & arreglo, int size)
{
   srand (time(NULL));
    for (int i = 0; i < size; ++i) {
        arreglo[i] = rand() % 1000;
    }
}

void print_array(int * & arreglo, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arreglo[i] << " : ";
    }
    cout << endl;
}

int main() {
	/*
	// Array declarations
	int size1, size2, size3, size4, size5, size6;

	// Aray of 100 elements
	size1 = 100;
	int * arr1 = new int[size1];
	fill_random(arr1, size1);
	//print_array(arr1, size1);

	// Aray of 1000 elements
	size2 = 1000;
	int * arr2 = new int[size2];
	fill_random(arr2, size2);
	//print_array(arr2, size2);

	// Aray of 10000 elements
	size3 = 10000;
	int * arr3 = new int[size3];
	fill_random(arr3, size3);
	//print_array(arr3, size3);

	// Aray of 100000 elements
	size4 = 100000;
	int * arr4 = new int[size4];
	fill_random(arr4, size4);
	//print_array(arr4, size4);

	// Aray of 1000000 elements
	size5 = 1000000;
	int * arr5 = new int[size5];
	fill_random(arr5, size5);
	//print_array(arr5, size5);

	// Aray of 10000000 elements
	size6 = 10000000;
	int * arr6 = new int[size6];
	fill_random(arr6, size6);
	//print_array(arr6, size6);
	*/

	cout << "Hello World!" << endl;
	int size = 8;
	int * arr = new int[size];
	fill_random(arr, size);

	cout << "Insertion sort" << endl;
	print_array(arr,size);
	mergeSort(arr, size);
	print_array(arr, size);
	fill_random(arr, size);

	cout << "Selection sort" << endl;
	print_array(arr,size);
	mergeSort(arr, size);
	print_array(arr, size);
	fill_random(arr, size);

	cout << "Bubble sort" << endl;
	print_array(arr,size);
	bubbleSorted(arr, size);
	print_array(arr, size);
	fill_random(arr, size);

	cout << "Quick sort" << endl;
	print_array(arr,size);
	quickSort(arr, 0, size-1);
	print_array(arr, size);
	fill_random(arr, size);

	cout << "Merge sort" << endl;
	print_array(arr,size);
	mergeSort(arr, size);
	print_array(arr, size);
	fill_random(arr, size);

	cout << "Counting sort" << endl;
	print_array(arr,size);
	countingSort(arr, size);
	print_array(arr, size);
	fill_random(arr, size);

	return 0;
}
