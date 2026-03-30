#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums); 
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);

            backtracking(nums, start + 1);

            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};
int main(){
    Solution x;
    vector<int> nums = {2,3,6,7};
    vector<vector<int>>k=x.permute(nums);
    for (auto i:k){
        cout<<'(';
        for (int j:i){
            cout<<j<<" ";
        }
        cout<<')';
    }
    return 0;
}