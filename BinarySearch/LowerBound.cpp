#include <iostream>
#include <vector>

using namespace std;


int LowerBound(vector<int> nums, int target){
int n = nums.size();
  
int low =0; int high = n-1;
int ans =n;


while (low <= high){

  int mid = low + (high - low) / 2;

  if(nums [mid] >= target ){
    ans = mid;
   high = mid -1;
  }
  else {
    low = mid +1;
  }
}
return ans;
}


int main (){

vector<int> nums = {1,2,2,2,2,2,4,5};
int target = 2;
int index;
index = LowerBound(nums,target);

cout << "The index for lower bound is: "<<index << endl;


return 0;
}