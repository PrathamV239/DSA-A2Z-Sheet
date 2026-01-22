#include <bits/stdc++.h>
using namespace std;


//Brute force approach: First Occurance iterate from the start. Last Occurance:  Iterate the array in reverse.

//optimised
pair<int,int> FirstAndLast(vector<int> &nums, int target){

  int n = nums.size();

//First Occurance 
int low = 0;
int high = n-1;
int first = -1;

while (low <= high){

int mid = low +(high - low) /2;

if (nums[mid] == target){
first = mid ;
high = mid -1;

}
else if(nums[mid] < target){
  low = mid + 1;

}
else {
 high = mid -1;
}
}
// Last Occurance 

low =0;
high = n-1;
int last = -1;

while (low <= high){

  int mid = low +(high - low) /2;

  if (nums[mid] == target){
    last = mid ;
    low = mid+1;
  }  

  else if (nums[mid]<= target){
    low = mid +1;

  }

  else {
    high = mid -1;
  }

}
return {first,last};
}


int main(){
  vector <int> nums = {1,2,3,3,3,4,4,5,5,5,6};
  int target = 3;
  pair <int,int>result = FirstAndLast(nums,target);

  cout << "First Occurance is: "<<result.first<<endl;
  cout <<"Last Occurance is: "<< result.second<<endl;

return 0;
}