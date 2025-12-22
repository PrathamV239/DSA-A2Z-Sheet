#include <iostream>
#include <vector>

using namespace std;

int CheckSorted(vector<int> &arr, int n){

  for(int i = 1; i < n; i++){
    if(arr[i]> arr[i-1]){


    }
    else {
      return false;
    }

  }
  return true;

}




int main(){

vector<int> arr = {3,4,5,0,7,8,9};

int n = arr.size();

cout << "The Array is Sorted: "<< CheckSorted(arr, n);

}