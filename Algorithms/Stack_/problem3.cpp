#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> re;
        for (string t:tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int b = re.top(); re.pop();
                int a = re.top(); re.pop();
                if(t=="+") re.push(a+b);
                else if(t=="-") re.push(a-b);
                else if(t=="*") re.push(a*b);
                else re.push(a/b);
            }else{
                re.push(stoi(t));
            }
        }
        return re.top();
    }
int main(){
    cout<<"hello";
    return 0;
}