#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];                

        while (sum >= target) {            
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}
int main(){
    int target = 10;
    vector<int> nums = {2,1,5,1,5,3};
    cout<<minSubArrayLen(target,nums);
    return 0;
}