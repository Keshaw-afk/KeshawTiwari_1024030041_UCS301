#include <stack>
#include <string>
#include <iostream>

int main(){
    std::string test_str = "DataStructure";
    std::stack<char> stack;
    for (int i = 0; i<test_str.size(); i++){
        stack.push(test_str[i]);
    }
    std::string ans = "";
    for (int i = 0; i<test_str.size(); i++){
        ans += stack.top();
        stack.pop();
    }
    std::cout << ans << std::endl;

}
