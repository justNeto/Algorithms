#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>

using namespace std;

// swap
// Function that swaps two elements of an array
template <typename T>
void swap(T * pA, T * pB) {
    T temp = *pA;                     //O(1)
    *pA = *pB;                          //O(1)
    *pB = temp;                         //O(1)
}

// Insertion Sort
void insertionSort(int * & arreglo, int size)
{
    int i, j, k;
    for (i = 1; i < size; i++)
    {
        j = arreglo[i];
        k = i - 1;

        while (k >= 0 && arreglo[k] > j)
        {
            arreglo[k + 1] = arreglo[k];
            k = k - 1;
        }
        arreglo[k + 1] = j;
    }
}

// Selectionsort
void selectionSort(int * & arreglo, int size)
{
    int startFrom = 0; // 12, 3, 4, 1, 0

    while (startFrom != size-1) // 0 != 4, 1 != 4
    {
        int min = arreglo[startFrom]; // 12, 3
		int minIndex = startFrom;
        // search for maximum number between startFrom - size
        for (int i = startFrom+1; i < size; i++) // 1-> 5-0-1 = 4, 2 -> 4
        {
            if (arreglo[i] < min) // 3 < 12? yes
            {
                min = arreglo[i]; // min = 3,1,0
				minIndex = i;
            }
        }
        swap(arreglo[minIndex], arreglo[startFrom]); //swaps 12 with 0
        startFrom++; // startFrom = 1
    }
}

// Bubblesort
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

void mergeSort(int* & arr, int size) { // O(n log(n))

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
void countingSort(int * & arreglo, int size) // O(n)
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
                arreglo[currIndex] = j;
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

void turn_negative(int *& arreglo, int size){ // O(n)
	for(int i = 0; i < size; i++){
		arreglo[i] -= 1000;
	}
	return;
}

void turn_positive(int *& arreglo, int size){ // O(n)
	for(int i = 0; i < size; i++){
		arreglo -= 1000;
	}
	return;
}

void time_measurement(int *& arr, int size){

	// Tests Insertion Sort
	fill_random(arr, size);

	auto start = std::chrono::high_resolution_clock::now();
	cout << "Insertion sort" << endl;
	insertionSort(arr, size);
    std::cout << "Desordenado: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
	
	start = std::chrono::high_resolution_clock::now();
	insertionSort(arr, size);
	std::cout << "Ordenado Ascendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	start = std::chrono::high_resolution_clock::now();
	turn_negative(arr, size);
	insertionSort(arr, size);
	std::cout << "Ordenado Descendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	// Tests Selection Sort
	fill_random(arr, size);

	start = std::chrono::high_resolution_clock::now();
	cout << "\nSelection sort" << endl;
	selectionSort(arr, size);
    std::cout << "Desordenado: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
	
	start = std::chrono::high_resolution_clock::now();
	selectionSort(arr, size);
	std::cout << "Ordenado Ascendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	start = std::chrono::high_resolution_clock::now();
	turn_negative(arr, size);
	selectionSort(arr, size);
	std::cout << "Ordenado Descendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	// Tests Bubble Sort
	fill_random(arr, size);

	start = std::chrono::high_resolution_clock::now();
	cout << "\nBubble sort" << endl;
	bubbleSorted(arr, size);
    std::cout << "Desordenado: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
	
	start = std::chrono::high_resolution_clock::now();
	bubbleSorted(arr, size);
	std::cout << "Ordenado Ascendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	start = std::chrono::high_resolution_clock::now();
	turn_negative(arr, size);
	bubbleSorted(arr, size);
	std::cout << "Ordenado Descendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	// Tests Quick Sort
	fill_random(arr, size);

	start = std::chrono::high_resolution_clock::now();
	cout << "\nQuick sort" << endl;
	quickSort(arr,0, size-1);
    std::cout << "Desordenado: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
	
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr,0, size-1);
	std::cout << "Ordenado Ascendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	start = std::chrono::high_resolution_clock::now();
	turn_negative(arr, size);
	quickSort(arr,0, size-1);
	std::cout << "Ordenado Descendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	// Tests Merge Sort
	fill_random(arr, size);

	start = std::chrono::high_resolution_clock::now();
	cout << "\nMerge sort" << endl;
	mergeSort(arr, size);
    std::cout << "Desordenado: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
	
	start = std::chrono::high_resolution_clock::now();
	mergeSort(arr, size);
	std::cout << "Ordenado Ascendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	start = std::chrono::high_resolution_clock::now();
	turn_negative(arr, size);
	mergeSort(arr, size);
	std::cout << "Ordenado Descendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	// Tests Counting Sort
	fill_random(arr, size);

	start = std::chrono::high_resolution_clock::now();
	cout << "\nCounting sort" << endl;
	countingSort(arr, size);
    std::cout << "Desordenado: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
	
	start = std::chrono::high_resolution_clock::now();
	countingSort(arr, size);
	std::cout << "Ordenado Ascendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";

	start = std::chrono::high_resolution_clock::now();
	turn_negative(arr, size);
	countingSort(arr, size);
	std::cout << "Ordenado Descendente: " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start).count() << " ns\n";
}

int main() {
	// Array declarations
	int size1, size2, size3, size4, size5, size6;

	// Aray of 100 elements
	size1 = 100;
	int * arr1 = new int[size1];

	// Aray of 1000 elements
	size2 = 1000;
	int * arr2 = new int[size2];

	// Aray of 10000 elements
	size3 = 10000;
	int * arr3 = new int[size3];

	// Aray of 100000 elements
	size4 = 100000;
	int * arr4 = new int[size4];

	// Aray of 1000000 elements
	size5 = 1000000;
	int * arr5 = new int[size5];

	// Aray of 10000000 elements
	size6 = 10000000;
	int * arr6 = new int[size6];

	cout << "Hello World!" << endl;

	//cout << "\nArrays of 100 elements" << endl;
	//time_measurement(arr1, size1);
	cout << "\nArrays of 1000 elements" << endl;
	time_measurement(arr2, size2);
	//cout << "\nArrays of 10000 elements" << endl;
	//time_measurement(arr3, size3);
	//cout << "\nArrays of 100000 elements" << endl;
	//time_measurement(arr4, size4);
	//cout << "\nArrays of 1000000 elements" << endl;
	//time_measurement(arr5, size5);
	//cout << "\nArrays of 10000000 elements" << endl;
	//time_measurement(arr6, size6);

	return 0;
}
