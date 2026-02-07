#include <iostream>
#include <stack>
#include <string>

using namespace std;


int Precedence (char c){

  if(c == '^'){
    return 3;
  }
  else if(c == '*' || c == '/'){
    return 2;
  }

  else if(c == '+' || c== '-'){
    return 1;
  }

  else return -1;
}


void InfixToPostfix(string s){

 stack <char> st;
 string result;

 for (int i =0; i < s.size(); i++){

  char c = s[i];

  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <='9')){
  result = result + c;
  }

  else if(c == '('){
    st.push(c);

  }

  else if( c == ')'){
    while (st.top() != '('){
      result = result + st.top();
      st.pop();

    }
    st.pop();
 }
    else {
      while (!st.empty() && Precedence(s[i]) <= Precedence(st.top())){
        result = result + st.top();
        st.pop();
      }
      st.push(c);
    }
}

while(!st.empty()){
  result = result + st.top();
  st.pop();
 }
cout << "Postfix Expression: "<< result <<endl;

}

int main(){

  string exp = "(p+q)*(m-n)"; 
  cout << "Infix expression: " << exp << endl;
  InfixToPostfix(exp);

return 0;
}