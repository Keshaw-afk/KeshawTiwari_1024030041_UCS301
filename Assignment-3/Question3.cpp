#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str){
	stack<char> st;
	for (int i = 0; i<str.size(); i++){
		if (str[i] == '(' || str[i] == '{' || str[i] == '['){
			st.push(str[i]);
		} else {
			if (str[i] == ')' && st.top() == '('){
				st.pop();
			} else if (str[i] == '}' && st.top() == '{'){
				st.pop();
			} else if (str[i] == ']' && st.top() == '['){
				st.pop();
			} else {
				return false;
			}
		}
	}
	return (st.size() == 0);
}

int main(){
	string test_str_unbalanced = "({}[]";
	if (isBalanced(test_str_unbalanced)){
		cout << "Balanced string" << endl;
	} else {
		cout << "Unbalanced string" << endl;
	}
	string test_str_balanced = "[{()}]";
	if (isBalanced(test_str_balanced)){
		cout << "Balanced string" << endl;
	} else{
		cout << "Unbalanced string" << endl;
	}
}








