// Bucket Sort
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
  vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto &[num,count]:freq){
            bucket[count].push_back(num);
        }
        vector<int> re;
        for(int i=n;i>=1&&re.size() < k;i--){
            for(int num:bucket[i]){
                re.push_back(num);
                if (re.size() == k) break;
            }
        }
        return re;
    }
  void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> nums = {1,2,2,3,3,3};
    show(topKFrequent(nums,2));
    return 0;
}