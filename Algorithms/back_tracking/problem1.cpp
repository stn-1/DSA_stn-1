#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;

    void backtracking(vector<int>& candidates, vector<int>& comb, int remain, int start) {
        if (remain == 0) {
            res.push_back(comb);
            return;
        }

        if (remain < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            backtracking(candidates, comb, remain - candidates[i], i);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        backtracking(candidates, comb, target, 0);
        return res;
    }
};
int main(){
    Solution x;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>>k=x.combinationSum(candidates,target);
    for (auto i:k){
        cout<<'(';
        for (int j:i){
            cout<<j<<" ";
        }
        cout<<')';
    }
    return 0;
}