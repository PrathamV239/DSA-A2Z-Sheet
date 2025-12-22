#include <iostream>
#include <vector>

using namespace std;


int LowerBound(vector<int> mines, int target){


  int low = 0;
  int high = mines.size() -1;
  int ans = mines.size();

  while (low <= high){
    int mid = low +(high-low)/2;

    
    if (mines[mid]>= target){
      ans = mid;
      high = mid -1;


    }

    else {
      low = mid +1;
    }
  }

  return ans;

}