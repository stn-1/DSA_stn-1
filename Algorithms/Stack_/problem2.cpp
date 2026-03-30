#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
bool isValid(string s) {
    stack<char> check;
    for (char i : s) {
        if (i == '(' || i == '[' || i == '{') {
            check.push(i);
        } else {
            if (check.empty()) return false; 
            char top = check.top();
            check.pop();
            if (!((i == ')' && top == '(') ||
                  (i == ']' && top == '[') ||
                  (i == '}' && top == '{'))) {
                return false; 
            }
        }
    }
    return check.empty(); 
}

int main() {
    return 0;
}