#include <iostream>
#include <string>
#include <stack>
#include <algorithm>


using namespace std;



string PostfixToPrefix(string postfix){

stack<string> st;

for (int i =0; i< postfix.size(); i++){

  char c  = postfix[i];
  if(isalnum(c)){
    st.push(string(1,c));
  }

  else {
    string op2 = st.top();
    st.pop();
    string op1 = st.top();
    st.pop();

    st.push(c + op1 + op2 );
  }

}
  return st.top();
}

int main(){
 string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << PostfixToPrefix(postfix) << endl;
    return 0;

}