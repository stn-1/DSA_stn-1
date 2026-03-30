#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> re;
    vector<int> r;

    for (int i : asteroids) {
        if (i > 0) {
            re.push(i);
        } else {
            if (re.empty()) {
                re.push(i); 
                continue;
            }
            while (!re.empty() && re.top() > 0 && re.top() < -i) {
                re.pop();
            }
            if (!re.empty() && re.top() == -i) {
                re.pop(); 
                continue;
            }
            if (re.empty() || re.top() < 0) {
                re.push(i); // số âm còn sống
            }
        }
    }

    while (!re.empty()) {
        r.push_back(re.top());
        re.pop();
    }
    reverse(r.begin(), r.end()); // vì stack LIFO
    return r;
}
int main() {
    vector<int> test{2,4,-4,-1};
    for(int i:asteroidCollision(test)){
        cout<<i<<" ";
    }
    return 0;
}