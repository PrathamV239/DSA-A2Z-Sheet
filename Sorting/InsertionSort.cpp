#include <iostream>
#include <vector>

using namespace std;


void InsertionSort (vector <int>& nums, int n ){

for (int i = 0; i <n; i++){
  int j = i;
  while (j > 0 && nums[j-1]> nums[j]){
    swap(nums[j], nums[j-1]);
    j--;
  }

}
cout << "After Sorting: \n";
for(int i =0; i<n;i++){
  cout << nums[i] <<" ";
   
}
cout << endl;
}


int main (){

  vector <int>nums = {23,45,67,13,9,56,43};

  int n = nums.size();
  cout << "Before sorting: \n";

  for (int i =0; i < n; i++){
    cout << nums[i]<<" ";
    
  }
cout << endl;

InsertionSort(nums,n);

}