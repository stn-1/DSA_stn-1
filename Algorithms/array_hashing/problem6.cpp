//Boyer-Moore Voting Algorithm
//Misra-Gries Algorithm
//thuật toán hay được sử dụng cho việc tìm phân tử phổ biến nhất trên là n/2 và dưới mở rộng cho n/k phần tử
#include<iostream>
#include<unordered_set>
#include<vector>
#include <string>
using namespace std;
 
int majorityElement(vector<int>& nums) {
        int candiate=nums[0];
        int vote=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=candiate){
                vote--;
            }
            if(vote<=0){
                candiate=nums[i];
                vote=1;
            }
        }
        return candiate;
    }
int main(){
    vector<int> nums = {5,5,1,1,1,5,5};
    cout<<majorityElement(nums);
    return 0;
}
