#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector <int>&nums, int n){
  
for (int i = n-1; i >=0; i--){

  int didSwap = 0;
  for (int j = 0; j <= i-1; j++){
    if (nums[j] > nums[j+1])
    {
      swap(nums[j], nums[j+1]);
      didSwap =1;
    }
  }
if (didSwap == 0) break;
}

cout << "After Sorting: \n";
for (int i = 0; i<n; i++){
  cout<< nums[i]<< " ";
}
cout << endl;
}



int main (){
  vector <int> nums = {13,34,24,5,6,78,9};
  int n = nums.size();
  
  cout<<"Before Sort: \n";
  for (int i = 0; i <n ; i++){
    cout<<nums[i]<<" ";
  }
  cout << endl;

BubbleSort(nums, n);
}
