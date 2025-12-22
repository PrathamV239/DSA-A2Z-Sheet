// Only Works on Sorted Array 
// Brute Remaining 


#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int RemoveDuplicates(vector <int> arr,int n){
int i = 0;

for(int j = 1; j < n; j++){

  if (arr[i] != arr[j]){
    arr[i+1] = arr[j];
    
    i++;
  }

}
return i+1;
}

int main (){

  vector <int> arr = {1,2,2,4,5,23,23,45,45};


  int n = arr.size();

  cout << "Non Duplicates are: "<< RemoveDuplicates(arr, n)<<endl;

}