#include <bits/stdc++.h>
using namespace std;

 void SelectionSort(vector<int>& nums, int n ) {
   

    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(nums[i], nums[mini]);
        }
    }
 
  cout << "After selection sort: \n";
  for(int i =0; i<n;i++){
    cout << nums[i] << " ";
  }
  cout << "\n";

 }



int main(){

 // Initialize array
    vector <int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    // Print array before sorting
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";


    SelectionSort(arr,n);

    return 0;

}