#include <iostream>
#include <vector>

using namespace std;


void Merge(vector <int>&nums, int low, int mid, int high){

  vector <int> temp;
  int left = low;
  int right = mid+1;
  
  while (left <= mid && right <= high){
    if (nums[left] <= nums[right]){
      temp.push_back(nums[left++]);
    }
    else{
      temp.push_back(nums[right++]);
    }

  }
  while(left <=mid){
    temp.push_back(nums[left++]);
 
  }

  while(right <= high){
    temp.push_back(nums[right++]);

  }

  for(int i = low; i<= high; i++){
    nums[i] = temp[i - low];
  }
}


void mergeSort(vector <int>& nums, int low, int high){

if(low >= high) return;

int mid =(high +low)/2;
 mergeSort(nums, low, mid);

 mergeSort(nums,mid+1, high );

 Merge(nums, low,mid, high);


}
int main (){

  vector<int> nums = {34,56,78,54,34,23,1,4};

  int n= nums.size();
mergeSort(nums, 0, n-1);
    for (int x : nums)
        cout << x << " ";
    cout << endl;
    return 0;




}