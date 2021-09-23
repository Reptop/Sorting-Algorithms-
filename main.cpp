
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Bubble(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; i < size-j-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);  
      }
    } 
  }
}




int main() {
int input; 
cout << "1. bubble 2. quick" << endl; 
cin >> input; 
int test[] = {14, 32, 25, 5, 4, 23, 43, 5, 34};
int length = sizeof(test)/sizeof(test[0]);  
switch(input) {
  case 1:
  Bubble(test, length);
  cout << "Sorted Array: " << endl;
  printArray(test, length); 
  break; 
  case 2: 
  quickSort(test, 0, length-1);
  cout << "Sorted Array: " << endl;
  printArray(test, length);
  break;  
}
//cout << "Invalid input" << endl;
//main();  
return 0; 
} 
