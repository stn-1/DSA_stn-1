//ghi đè in place
#include<iostream>
#include<unordered_set>
#include<vector>
#include <string>
using namespace std;
 
vector<int> removeElement(vector<int>& nums, int val) {
    int k=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]!= val){
            nums[k++]=nums[i];
           }
        }
        nums.resize(k);
        return nums;
    }
void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> num={1,1,2,3,4};
    show(removeElement(num,1));
    return 0;
}