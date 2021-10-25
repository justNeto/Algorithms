#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

/*
Bubble Sort(arr, size)
		for i=0 to n-i-1
			for j=0 to n-i-2
				if arr[j]>arr[j+1]
					Swap arr[j] and arr[j+1]

*/
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
void selectionSort(int * & arreglo, int size)
{
    int startFrom = 0; // 12, 3, 4, 1, 0

    while (startFrom != size-1) // 0 != 4, 1 != 4
    {
        int min = arreglo[startFrom]; // 12, 3
        // search for maximum number between startFrom - size
        for (int i = startFrom+1; i < size; i++) // 1-> 5-0-1 = 4, 2 -> 4
        {
            if (arreglo[i] < min) // 3 < 12? yes
            {
                min = arreglo[i]; // min = 3,1,0
            }
        }
        swap(min, arreglo[startFrom]); //swaps 12 with 0
        startFrom++; // startFrom = 1
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

int main() {
	// Array declarations
	int size1, size2, size3, size4, size5, size6;
	size1 = 100;
	int * arr1 = new int[size1];
	size2 = 1000;
	int * arr2 = new int[size2];
	size3 = 10000;
	int * arr3 = new int[size3];
	size4 = 100000;
	int * arr4 = new int[size4];
	size5 = 1000000;
	int * arr5 = new int[size5];
	size6 = 10000000;
	int * arr6 = new int[size6];

	// Clock to measure
	clock_t t;
	int f;
	
	int size = 11;
	int * arreglo = new int[10];
	fill_random(arreglo, 10);
	print_array(arreglo, 10);

	cout << "Hello World!\n";

	t = clock();
	quickSort(arreglo, 0, size -1);
	t = 2;
	t = clock() - t;
	printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

	print_array(arreglo, 10);

	return 0;
}