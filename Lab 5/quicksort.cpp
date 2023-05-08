#include <iostream>
#include <limits.h>
#include <chrono>
#include <iomanip>
#include <cstdlib>
using namespace std;

void recursiveQuicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right)/2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    recursiveQuicksort(arr, left, j);
    recursiveQuicksort(arr, i, right);
}

void iterativeQuicksort(int arr[], int left, int right) {
    int stack[right - left + 1];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while (top >= 0) {
        right = stack[top--];
        left = stack[top--];

        if (left >= right) {
            continue;
        }

        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        stack[++top] = left;
        stack[++top] = j;
        stack[++top] = i;
        stack[++top] = right;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    int lengths[12] = {3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};

    for (int i = 0; i < 12; ++i) { 


        int length = lengths[i];
        cout << "length : " << length << endl;
        int arr_recursive[length],arr_iterative[length];
        
        for (int j = 0; j < length; ++j) {
             arr_recursive[j]= rand() % 1001;
             arr_iterative[j] = arr_recursive[j];

        }
        int n = length;

        auto start_time_recursive = chrono::high_resolution_clock::now();
        recursiveQuicksort(arr_recursive , 0 , n-1);
        auto end_time_recursive = chrono::high_resolution_clock::now();
        
        double time_taken_recursive = chrono::duration_cast<chrono::duration<double>>(end_time_recursive - start_time_recursive).count() ;

        auto start_time_iterative = chrono::high_resolution_clock::now();
        iterativeQuicksort(arr_iterative, 0 , n-1);
        auto end_time_iterrative = chrono::high_resolution_clock::now();

        double time_taken_iterative = chrono::duration_cast<chrono::duration<double>>(end_time_iterrative - start_time_iterative).count() ;

        cout << setprecision(10)<< time_taken_recursive*10000000 << endl;
        cout << setprecision(10)<< time_taken_iterative*10000000 << endl;
    }



    return 0;
}
