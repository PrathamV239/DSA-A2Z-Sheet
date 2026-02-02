#include <iostream>
#include <vector>

using namespace std;


void SelectionSort(vector<int> &nums, int n){

for (int i = 0; i < n-1; i++){

  int mini = i;
  for (int j = i+1; j < n; j++){
    if (nums [mini]> nums[j]){
      mini = j;
    }

  }
  if (nums[mini] != i){
    swap(nums[mini], nums[i]);
  }

}
cout << "The array after sorting:\n";
for (int i = 0; i < n; i++){
cout << nums[i]<< " ";
}
cout <<"\n";
}



int main (){

vector <int> nums = {13,46,24,54,67,9};

int n = nums.size();

cout <<"The array before Sorting: \n";
for (int i = 0; i < n; i++){
cout << nums[i]<< " ";
}
cout <<"\n";

SelectionSort(nums,n);

}