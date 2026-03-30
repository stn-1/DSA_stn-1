
// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average
// value and return this value. Any answer with a calculation error less than 10-5 will be accepted.


#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    int maxsum=sum;
    for(int i=k;i<n;i++){
        sum+=nums[i]-nums[i-k];
        maxsum=max(sum,maxsum);
    }
    return static_cast<double>(maxsum) / k;
}
int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << fixed;
    cout.precision(6);
    cout << findMaxAverage(nums, k) << endl; 
    return 0;
}
