//Extended Essay Code 

#include <bits/stdc++.h>
#include <fstream>
#include <chrono>  
using namespace std;
using namespace std::chrono;

// A utility function to swap two elements
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high) {
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
	
	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
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
void quickSort(int arr[], int low, int high) {
	if (low < high) {
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
void printArray(int arr[], int size) {
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
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printmerge(int A[], int size) {
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
int testy[1000000]; //global array; I hate using global variables man...

int main() {
ifstream file("dataset.txt");
if(file.is_open()) {
        for(int i = 0; i < 1000000; ++i) {
            file >> testy[i];
        }
    }
int input;
cout << "1. bubble 2. quick 3. mergesort" << endl; 
cin >> input; 
int len = 1000000; 
switch(input) {
  case 1: {
  auto start = high_resolution_clock::now();
  Bubble(testy, len);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  cout << "Sorted Array: " << endl;
  printArray(testy, len); 
  cout << "Duration: " << duration.count() << " nanoseconds"; 
  break; 
}
  case 2: {
  auto start = high_resolution_clock::now();
  quickSort(testy, 0, len-1);
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<nanoseconds>(stop - start);
  cout << "Sorted Array: " << endl;
  printArray(testy, len);
  cout << "Duration: " << duration.count() << " nanoseconds"; 
  break;  
}
  case 3: {
  auto start = high_resolution_clock::now();
  mergeSort(testy, 0, len-1);
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<nanoseconds>(stop - start);
  cout << "Sorted Array: " << endl;
  //printmerge(testy, len); 
  cout << "Duration: " << duration.count() << " nanoseconds"; 
  break; 
  } 
}

return 0; 
} 
