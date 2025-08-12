 

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
 bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> a;
        for(int i : nums){
            a.insert(i);
        }
        if(a.size()!=nums.size()) return true;
        return false;
    }


int main(){
    vector<int> i={1,4,1,2};
    cout<<hasDuplicate(i);
    return 0;
}