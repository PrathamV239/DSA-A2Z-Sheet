#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index for smaller elements
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);   
        quickSort(arr, pivotIndex + 1, high);  
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    cout << "Before sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "After sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}