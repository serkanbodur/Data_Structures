#include<iostream>
#include <time.h>
#define A 1000
#define B 10000
#define C 100000
using namespace std;
//Define temps to keep elements of array
int *temp1, *temp2, *temp3, *temp4, *temp5, *temp6, *temp7, *temp8, *temp9, *temp10, *temp11, *temp12;
int dizi1[1000], dizi2[10000], dizi3[100000];
double d[15];
//Create bubble sort function
//param int dizi[]
//param int elemanSayisi
void bubbleSort(int dizi[], int elemanSayisi)
{
	int temp;
	int i, j;
	for (i = 1; i < elemanSayisi; i++)
	{
		for (j = 0; j < elemanSayisi - i; j++)
		{
			//if new element greater than prev element swap
			if (dizi[j] > dizi[j + 1])
			{
				temp = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = temp;
			}
		}
	}
}
//Create selection sort function
//param int dizi[]
//param int elemanSayisi
void selectionSort(int dizi[], int elemanSayisi)
{
	int i, j, enKucuk, temp;

	
	for (i = 0; i < elemanSayisi - 1; i++)
	{
		enKucuk = i;
		for (j = i + 1; j < elemanSayisi; j++)
		{
			//iteration sorting when next element smaller than prev element
			//then appoint to "enKucuk" this element
			if (dizi[j] < dizi[enKucuk])
				enKucuk = j;
		}
		//Before pass next step make swap operation
		temp = dizi[i];
		dizi[i] = dizi[enKucuk];
		dizi[enKucuk] = temp;
	}
}
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void swap(int i, int j, int *a) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller to left of pivot and 
all greater elements to right of pivot */
void quicksort(int *arr, int left, int right) {
	int min = (left + right) / 2;


	int i = left;
	int j = right;
	int pivot = arr[min];

	while (left<j || i<right)
	{
		while (arr[i]<pivot)
			i++;
		while (arr[j]>pivot)
			j--;
		// If current element is smaller than or
		// equal to pivot
		if (i <= j) {
			swap(i, j, arr);
			i++;
			j--;
		}
		else {
			// Separately sort elements before
			// partition and after partition
			if (left<j)
				quicksort(arr, left, j);
			if (i<right)
				quicksort(arr, i, right);
			return;
		}
	}
}
int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
	return 0;
}

int main()
{
	int  i;
	clock_t timeStart, timeEnd;
	srand(time(NULL));
	//temp pointers open part in memory
	temp1 = new int[1000];
	temp2 = new int[10000];
	temp3 = new int[100000];
	temp4 = new int[1000];
	temp5 = new int[10000];
	temp6 = new int[100000];
	temp7 = new int[1000];
	temp8 = new int[10000];
	temp9 = new int[100000];
	temp10 = new int[1000];
	temp11 = new int[10000];
	temp12 = new int[100000];
	//Create random numbers and register to arrays
	//Then arrays appoint appropriate size of temp pointer 
	//Because of not sending ranked array
	for (i = 0;i < 1000;i++)
		dizi1[i] = rand();
	for (i = 0;i < 1000;i++)
	{
		temp1[i] = dizi1[i];
		temp4[i] = dizi1[i];
		temp7[i] = dizi1[i];
		temp10[i] = dizi1[i];
	}
	for (int i = 0;i < 10000;i++)
		dizi2[i] = rand();
	for (i = 0;i < 10000;i++)
	{
		temp2[i] = dizi2[i];
		temp5[i] = dizi2[i];
		temp8[i] = dizi2[i];
		temp11[i] = dizi2[i];
	}
	for (int i = 0;i < 100000;i++)
		dizi3[i] = rand();
	for (i = 0;i < 100000;i++)
	{
		temp3[i] = dizi3[i];
		temp6[i] = dizi3[i];
		temp9[i] = dizi3[i];
		temp12[i] = dizi3[i];
	}
	//Clock fit starting point and call appropriate 
	//function then clock get finishing point
	//register between start and finish time difference
	timeStart = clock();
	bubbleSort(dizi1, 1000);
	timeEnd = clock();
	d[1] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	bubbleSort(dizi2, 10000);
	timeEnd = clock();
	d[2] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	bubbleSort(dizi3, 100000);
	timeEnd = clock();
	d[3] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	insertionSort(temp4, A);
	timeEnd = clock();
	d[4] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	insertionSort(temp5, B);
	timeEnd = clock();
	d[5] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	insertionSort(temp6, C);
	timeEnd = clock();
	d[6] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	selectionSort(temp4, 1000);
	timeEnd = clock();
	d[7] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	selectionSort(temp5, 10000);
	timeEnd = clock();
	d[8] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	selectionSort(temp6, 100000);
	timeEnd = clock();
	d[9] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	quicksort(temp7, 0, 1000-1);
	timeEnd = clock();
	d[10] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	quicksort(temp8, 0, 10000-1);
	timeEnd = clock();
	d[11] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	quicksort(temp9, 0, 99999);
	timeEnd = clock();
	d[12] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	shellSort(temp10, A);
	timeEnd = clock();
	d[13] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	shellSort(temp11, B);
	timeEnd = clock();
	d[14] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	timeStart = clock();
	shellSort(temp12, C);
	timeEnd = clock();
	d[15] = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	//Registration values print to screen
	cout << "\t\t" << "N=1000\t\t" << "N=10000\t\t" << "N=100000" << endl;
	cout << "Bubble Sort\t" << d[1] << " sec\t" << d[2] << " sec\t" << d[3] << " sec " << endl;
	cout << "Selection Sort\t" << d[7] << " sec\t" << d[8] << " sec\t" << d[9] << " sec " << endl;
	cout << "Insertion Sort\t" << d[4] << " sec\t" << d[5] << " sec\t" << d[6] << " sec " << endl;
	cout << "Quick Sort\t" << d[10] << " sec\t\t"<< d[11] << " sec\t" << d[12] << " sec " << endl;
	cout << "My Sort\t\t" << d[13] << " sec\t\t" << d[14] << " sec\t" << d[15] << " sec " << endl;
	system("pause");
	return 0;
}