#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool isValid ( string s){
  stack<char> st;

  for (char c : s){
    if (c == '(' ||c == '[' || c== '{'){
      st.push(c);
    }

    else {
      if (st.empty()){
        return false;
      }

      char top = st.top();
      st.pop();
      if(c== '}' && top != '{') return false;
      if (c == ')' && top != '(') return false;
      if (c == ']' && top != '[') return false;
    }

  }

  return st.empty();
}

int main(){
string s1 = "()[{}()]";
    string s2 = "([)]";
    string s3 = "(((";
    
    cout << s1 << ": " << (isValid(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << ": " << (isValid(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << ": " << (isValid(s3) ? "Valid" : "Invalid") << endl;
    
    return 0;


}
