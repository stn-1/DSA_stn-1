// You are given an integer array nums of length n. 
// Create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).


#include<iostream>
#include<vector>
using namespace std;
vector<int> getConcatenation(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        nums.push_back(nums[i]);
    }
    return nums;
    }
void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> i={1,4,1,2};
    show(getConcatenation(i));
    return 0;
}