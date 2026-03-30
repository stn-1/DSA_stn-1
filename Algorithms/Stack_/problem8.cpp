#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<stack>

using namespace std;
 
int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float,int>> st;
        for (int i = 0; i < position.size(); i++){
            float time=float((target-position[i])/speed[i]);
            pair<float,int> a={time,position[i]};
            st.push_back(a);
        }
        sort(st.begin(), st.end(), [](const pair<float,int>& a, const pair<float,int>& b) {
        return a.second > b.second;
        });
        stack<float> re;
        for(auto &i:st){
            if(re.empty()||i.first>re.top()){
                re.push(i.first);
            }
        }
        return re.size();
        
    }
int main() {
    int target = 10;
    vector<int> position = {1,4}, speed = {3,2};
   cout<< carFleet(target,position,speed);
    return 0;
}