#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
string decodeString(string s) {
    stack<char> st;

        for(char i:s){
            if(i==']'){
                string re="";
                while(!st.empty()&&st.top()!='['){
                    re+=st.top();
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())) {
                    num = st.top() + num; 
                    st.pop();
                }
                reverse(re.begin(),re.end());
                int t=stoi(num);
                string temp=re;
                for(int j=0;j<t-1;j++){
                    re+=temp;
                }
                for(int k:re){
                    st.push(k);
                }
            }
            if(i!=']') st.push(i);
        }
       
        string k="";
        while(!st.empty()) {
            k = st.top() + k;
            st.pop();
        }
        return k;
    }
       
int main() {
      string a="2[a3[b]]c";
      cout<<decodeString(a);

    return 0;
}