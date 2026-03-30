#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
 void backtracking(vector<string>& re, string s, int open, int close, int n) {
    if (s.size() == 2 * n) {
        re.push_back(s);
        return;
    }
    if (open < n) {
        backtracking(re, s + '(', open + 1, close, n);
    }

    if (close < open) {
        backtracking(re, s + ')', open, close + 1, n);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> re;
    backtracking(re, "", 0, 0, n);
    return re;
}
int main() {
    return 0;
}