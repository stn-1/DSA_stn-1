#include<iostream>
#include<vector>
#include<unordered_map>
//yêu cầu tính theo phần cắt ra liên tiếp có bao nhiêu phần tử có tổng bàng k(dùng prefix sum)
//ta biết tổng từ vị trí i+1 dến j =>prefix[j] - prefix[i] = k=> ta chỉ cần tìm số lần xuất hiện của prefix[j]-k trong vector
//do khong yêu cầu tính tổng chúng ta không cần lưu giá trị của vector prefixsum mà dùng hash map
using namespace std;
 int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixcount;
        prefixcount[0]=1;
         int prefixSum = 0, count = 0;
        int n=nums.size();
        for(int num:nums){
            prefixSum+=num;
            if(prefixcount.find(prefixSum-k)!=prefixcount.end()){
                count+=prefixcount[prefixSum-k];
            }
            prefixcount[prefixSum]++;
        }
        return count;
    }

int main(){
    vector<int> nums = {2, -1, 1, 2};
    int k = 2;
    cout << subarraySum(nums, k) << endl; 
    return 0;
}