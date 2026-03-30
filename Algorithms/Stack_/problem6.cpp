#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st; 

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            result[prev] = i - prev;
        }
        st.push(i); 
    }

    return result;
}

int main() {
    return 0;
}