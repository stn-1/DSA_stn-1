#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//phần này chúng ta sẽ lợi dùng hàm count và find của unorder_set với độ phức tạp là o(1)
int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for(int num:numSet){
            int longnow=0;
            if(!numSet.count(num-1)){
                int current=num;
                int longnow=1;
                while (numSet.count(current+1))
                {
                    longnow++;
                    current++;
                }
                longest=max(longnow,longest);
            }
        }
        return longest;
    }
int main(){
    vector<int> nums = {2,20,4,10,3,4,5};
    cout<<longestConsecutive(nums);
    return 0;
}