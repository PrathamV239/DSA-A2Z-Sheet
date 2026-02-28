#include <iostream>

using namespace std;
  
 // Parameterised recursion

void ParameterisedSum(int i, int sum){
  if(i < 1){
    cout<<sum<<endl;
    return;
  }
  ParameterisedSum(i-1, sum + i);
}

int main(){
  int n = 4;
  int sum =0;
  ParameterisedSum(n,sum);
}

// ---------------------------------------------------xxxx----------------------------------------------------------------

//Functional Recusion

int FunctionalSum(int n){
  if (n==0) return 0;
  return n + FunctionalSum(n-1);
}


int main(){
  int n = 4;
  cout << FunctionalSum(n);
}


