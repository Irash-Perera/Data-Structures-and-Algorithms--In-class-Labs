#include <iostream>
#include <chrono>

using namespace std;


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];  // choosing pivot  
        int i = (low - 1);  

        for (int j = low;j<=high-1;j++) {
        
        if (arr[j] <= pivot) { // if an elemnt is less than pivot increase i by 1 and swap them
            i++;    
            swap(arr[i],arr[j]);
            }
        }
        //after reaching the pivot increase i by 1 and swap with pivot
        swap(arr[i + 1],arr[high]);
        int pi=i+1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 10; 
    int arr[n];

    
    srand(time(nullptr)); // set the seed to current time
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // random integer between 0 and 999
    }

    // sort the array and measure execution time
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // print sorted array and execution time
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nExecution time: " << duration.count() << " microseconds\n";

    return 0;
    
}
