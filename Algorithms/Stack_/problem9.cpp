#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<stack>
using namespace std;
string simplifyPath(string path) {
        stack<std::string> s;
        string current_dir;
        for (char c : path + "/") {
            if (c == '/') {
                if (current_dir == ".." && !s.empty()) {
                    s.pop();
                } else if (current_dir != "." && !current_dir.empty() && current_dir != "..") {
                    s.push(current_dir);
                }
                current_dir = "";
            } else {
                current_dir += c;
            }
        }
        string h;
        if(s.empty()){
            return "/";
        }
        while(!s.empty()){
            h="/"+s.top()+h;
            s.pop();
        }
        return h;
    }
    void show(stack<string> a){
        while(!a.empty()){
            cout<<a.top()<<" ";
            a.pop();
        }
    }
int main() {
    cout<<simplifyPath("/neetcode/practice//...///../courses");
      

    return 0;
}