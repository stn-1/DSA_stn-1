#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int left = 0;
    for (int right = 1; right < nums.size(); right++) {
        if (nums[right] != nums[left]) {
            nums[left + 1] = nums[right];
            left++;
        }
    }
    return left + 1; 
}
int main(){

    cout<<"hello";
    return 0;
}