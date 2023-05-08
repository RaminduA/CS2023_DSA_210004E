#include <iostream>
#include <iomanip>
using namespace std;

void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right)/2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j]>pivot) {
            j--;
        }
        if (i<=j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

void runningMedian(int arr[], int size) {
    for (int i=1; i<=size; i++) {
        quicksort(arr, 0, i-1);
        
        double median;

        if (i % 2 != 0) {
            median = (double)arr[i/2];
        } else {
            median = (double)(arr[i/2 - 1] + arr[i/2])/2.0;
        }

        cout << setprecision(1) << fixed << median << endl;
    }
}

int main() {

    cout << "Enter Array Length : ";
    int n;
    cin >> n;

    int arr[n];
        
    for (int i=0; i<n; ++i) {
        arr[i] = rand() % 30;
    }

    for(int i=0; i<n; i++)
      cout << arr[i] << " ";
  	cout << endl;

    runningMedian(arr, n);
    return 0;
}
