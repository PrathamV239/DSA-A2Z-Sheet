#include <iostream>
#include <string>
#include <algorithm>
#include <stack>


using namespace std;

int Precedence (char c){

  if (c == '^') return 3;
  else if (c == '*' || c == '/') return 2;
  else if (c == '+' || c== '-') return 1;
  else return -1;

}
bool isOperator (char c){
  return (c == '^' || c == '+'|| c == '-'|| c== '*' || c == '/'); 
}

string infixToPostfix (string infix){
  stack <char> st;
  string result;

  for (int i = 0; i < infix.size(); i++){
    char c = infix[i];
    if (isalnum(c)){
      result = result + c;

    }

    else if (c == '('){
      st.push(c);
      
    }

    else if (c == ')'){

      while(st.top() != '('){
      result = result + st.top();
      st.pop();
    }
    st.pop();
  }
  else if (isOperator(c)) {
    if (c == '^'){
      while (!st.empty() &&  Precedence(infix[i]) < Precedence(st.top()) ){
        result = result + st.top();
        st.pop();
      }

    } 

    else {
      while (!st.empty() && Precedence(st.top()) >= Precedence(c)){
        result += st.top();
        st.pop();
      }
    }
    st.push(c);

  }

}

  while (!st.empty()){
    result += st.top();
    st.pop();

  }
  return result;
}


string InfixToPrefix(string infix){

  reverse(infix.begin(), infix.end());

  for(int i = 0; i <infix.length(); i++){
    if (infix[i] == '('){
      infix[i] = ')';
    }
    else if(infix[i] == ')'){
      infix[i] = '(';
    }
  }

  string postfix = infixToPostfix(infix);

  reverse(postfix.begin(), postfix.end());

  return postfix;
}
int main()
{

     string infix = "(p+q)*(c-d)";
    
    cout << "Infix:  " << infix << endl;
    cout << "Prefix: " << InfixToPrefix(infix) << endl;

    return 0;

}