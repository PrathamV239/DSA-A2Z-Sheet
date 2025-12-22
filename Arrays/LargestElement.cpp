#include <iostream>
#include <vector>
using namespace std;


int largestElemnt(vector<int> &arry, int n){
  int largest = arry[0];

  for (int i =0; i<=n; i++){
    if(arry[i] > largest){
      largest = arry[i];
    }   
  }
  return largest;
}


int main (){

  vector<int> arry =  {3,7,5,9,4};
  int n = arry.size()-1;
  
  cout << "Largest Element: "<< largestElemnt(arry, n)<< endl;
  return 0;

}