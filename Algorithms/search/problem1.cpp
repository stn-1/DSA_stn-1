
#include<iostream>
#include<vector>
using namespace std;
 int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l= 0;
        int r=n-1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
int main(){
    vector<int> nums={-1,0,2,4,6,8};
    cout<<search(nums,4);
    return 0;
}