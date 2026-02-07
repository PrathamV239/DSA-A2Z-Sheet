#include <iostream>
#include <string>
#include <stack>
#include <algorithm>


using namespace std;

int Precedence (char c){

    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c== '-') return 1;
    else return -1;

}

bool isOperator (char c){
    if (c == '*' || c== '^' || c== '/' || c == '+' || c == '-'){
        return true;
    }
    else {
        return false;
    }
}



string InfixToPostfix( string s){

    stack <char> st;
    string result;
    
    for (int i = 0; i < s.size(); i++){
         char c = s[i];

         if(isalnum(c)){

            result = result +c;
         }
         else if(c == '('){
            st.push(c);
         }
         else if( c == ')'){
            while (!st.empty() && st.top() != '('){
                result = result + st.top();
                st.pop();
            }
            st.pop();
         }
         else if (isOperator(c)){
            if ( c == '^'){
                while (!st.empty() && Precedence(st.top()) > Precedence(c)){
                    result = result + st.top();
                    st.pop();
                }
            }
            else {
                while (!st.empty() && Precedence(st.top()) >= Precedence(c)){
                    result = result + st.top();
                    st.pop();

                }
                st.push(c);
            }

         }
        
    }

    while (!st.empty()){
        result = result + st.top();
        st.pop();
    }

    return result;
}

string InfixToPrefix (string infix){

    reverse(infix.begin() ,infix.end());

    for (int i =0; i < infix.size(); i++ ){
        if (infix[i] == '('){
            infix[i] = ')';
        }
        else if ( infix[i] == ')'){
            infix[i] = '(';
        }
    }
string postfix = InfixToPostfix(infix);

reverse(postfix.begin(), postfix.end());

return postfix;

}

int main(){

    string infix = "(p+q)*(c-d)";
    
    cout << "Infix:  " << infix << endl;
    cout << "Prefix: " << InfixToPrefix(infix) << endl;

    return 0;


}