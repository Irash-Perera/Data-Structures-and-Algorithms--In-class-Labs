#include <iostream>
#include <chrono>
#include <stack>

using namespace std;

void quickSort(int arr[], int low, int high) {
    stack<int> stack;

    stack.push(low);
    stack.push(high);

    // Keep popping from stack while is not empty
    while (!stack.empty()) {
        // Pop high and low
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        // Set pivot element at its correct position in sorted array
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot) {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi=(i + 1);

        // If there are elements on left side of pivot, push left side to stack
        if (pi - 1 > low) {
            stack.push(low);
            stack.push(pi - 1);
        }

        // If there are elements on right side of pivot, push right side to stack
        if (pi + 1 < high) {
            stack.push(pi + 1);
            stack.push(high);
        }
    }
}

int main() {
    int n = 10; // size of array
    int arr[n];

    // generate random elements
    srand(time(nullptr)); // set the seed to current time
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10; // random integer between 0 and 999
    }

    // sort the array and measure execution time
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // print sorted array and execution time
    for(int temp:arr){
        cout<<temp<<" ";
    }
    cout<<endl;
   
    cout << "\nExecution time: " << duration.count() << " microseconds\n";

    return 0;
}
