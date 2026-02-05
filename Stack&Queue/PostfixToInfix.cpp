#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


string PostfixToInfix(string postfix){

stack <string> st;
int n = postfix.size();

for (int i =0; i< n; i++ ){

  char c = postfix[i];
  if (isalnum(c)){
    st.push(string(1,c));  // converts char to string to push in the stack, since stack defined is of string datatype.
    
  }

  else {
   string op1 = st.top();
    st.pop();
    string op2 = st.top();
    st.pop();

    st.push("(" + op1+ c+ op2 + ')');

  }
 
}

return st.top();

}


int main(){

  string postfix = "AB*C+";
    cout << "Infix Expression: " << PostfixToInfix(postfix) << endl;
    return 0;
}