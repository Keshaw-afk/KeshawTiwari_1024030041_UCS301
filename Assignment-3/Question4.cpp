#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char c){
	if (c == '^'){
		return 3;
	} else if (c == '*' || c == '/'){
		return 2;
	} else if (c == '+' || c == '-'){
		return 1;
	} else{
		return -1;
	}
}

string infixToPostfix(string str){
	stack<char> st;
	string res = "";
	for (int i = 0; i<str.size(); i++){
		if ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
			res += str[i];
		} else if (str[i] == '('){
			st.push(str[i]);
		} else if (str[i] == ')'){
			while(st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		} else{
			while(!st.empty() && prec(str[i]) <= prec(st.top())){
				res += st.top();
				st.pop();
			}
			st.push(str[i]);
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	return res;
}

int main(){
	string simple_test_infix = "A+B/C";
	string simple_test_postfix = infixToPostfix(simple_test_infix);
	cout << "Infix: " << simple_test_infix << " " << "Postfix: " << simple_test_postfix << endl;
}
