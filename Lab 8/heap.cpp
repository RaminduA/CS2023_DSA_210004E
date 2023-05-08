#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root){
    int largest = root;     // Initialize largest as root
    int left = 2*root + 1;  // left child index
    int right = 2*root + 2; // right child index

    // if left child is larger than root
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }        

    // if right child is larger than largest so far
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    // if largest is not root
    if(largest!=root){
        swap(arr[root], arr[largest]);
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n){
    // build heap (rearrange array)
    for (int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for(int i=n-1; i>=0; i--){
        // move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// main program
int main(){
   int n = 10; // size of the array
   int heap_arr[n];

   // assign random values to the array
   srand(time(NULL));
   for(int i=0; i<n; i++){
      heap_arr[i] = rand() % 100; // generates a random number between 0 and 99
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}