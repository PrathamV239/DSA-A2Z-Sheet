#include <bits/stdc++.h>
using namespace std;


int InsertPosi(vector<int> nums, int target){

int n = nums.size();
int ans = n;
int low = 0;
int high = n-1;

while (low <= high){

  int mid = low+(high-low)/2;

  if(nums[mid] >= target){
    ans = mid;
    high = mid - 1;
  }
  else {
    low = mid + 1;
  }

}
return ans;
}



int main (){

  vector<int> nums ={1,2,2,2,3,4,45,67};
  int target = 3;
  int index;
  index = InsertPosi(nums, target);
  
  cout<<"Insert posi index is: "<<index<<endl;

return 0;
}