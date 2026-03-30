#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> win;

    for (int i = 0; i < nums.size(); i++) {
        if (win.count(nums[i])) return true;

        win.insert(nums[i]);
        if (win.size() > k) {
            win.erase(nums[i - k]);
        }
    }
    return false;
}
int main(){

    return 0;
}