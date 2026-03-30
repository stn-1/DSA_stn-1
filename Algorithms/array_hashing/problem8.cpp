// Dutch National Flag Algorithm 3 con trỏ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while (mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            if(nums[mid]==1) mid++;
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
 void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> nums={1,0,1,2};
    sortColors(nums);
    show(nums);
    return 0;
}