#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> re;
    void backtracking(int start, int n, vector<int>& nums, vector<int>& sub) {
        re.push_back(sub);  

        for (int i = start; i < n; i++) {
            sub.push_back(nums[i]);              
            backtracking(i + 1, n, nums, sub);  
            sub.pop_back();                    
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>sub;
        int n=nums.size();
        backtracking(0,n,nums,sub);
        return re;
    }
};
int main(){
    Solution x;
    vector<int> nums = {2,3,6,7};
    
    vector<vector<int>>k=x.subsets(nums);
    for (auto i:k){
        cout<<'(';
        for (int j:i){
            cout<<j<<" ";
        }
        cout<<')';
    }
    return 0;
    return 0;
}