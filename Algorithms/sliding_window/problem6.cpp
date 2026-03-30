#include<iostream>
#include<vector>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int left=0,right=n-k;
        while(left<right){
            int mid=(left+right)/2;
            if(x - arr[mid] <= arr[mid + k] - x){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        vector<int> re;
        for(int i=0;i<k;i++){
            re.push_back(arr[left+i]);
        }
        return re;
    }
int main(){


    return 0;
}