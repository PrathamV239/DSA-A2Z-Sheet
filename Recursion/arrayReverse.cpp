#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int i){
  int n = arr.size();
    if(i >= n/2) return;
  swap(arr[i], arr[n-i-1]);
   reverseArray(arr,i+1);
}

int main(){
vector<int> nums = {1,2,3,4,5,6,7};
 reverseArray(nums,0);

 for(int x : nums)
        cout << x << " ";
}