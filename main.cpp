#include <iostream>
#include <cstring>
using namespace std;


void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
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

void quickSort() {

} 


void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " "; 
  }
  
}

int main() {
//int input; 
//cout << "1. bubble 2. quick"; 
//cin >> input; 
int test[] = {14, 32, 25, 5, 4, 23, 43, 5, 34}; 
int length = sizeof(test)/sizeof(test[0]);  
Bubble(test, length);
cout << "Sorted Array: " << endl;
printArray(test, length);
return 0; 
} 