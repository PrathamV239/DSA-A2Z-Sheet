#include <iostream>
#include <string>

using namespace std;

bool plaindromeCheck(string& s, int i){
  int n = s.length();
  if(i >= n/2)
    return true;
  if(s[i] == s[n-i-1])
    return plaindromeCheck(s, i+1);
  else 
    return false;
}


int main(){

  string ans = "madam";
  int i =0;
  cout << plaindromeCheck(ans, i);
  
}