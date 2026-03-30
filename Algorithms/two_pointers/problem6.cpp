#include<iostream>
#include<vector>
using namespace std;
void reverseV(vector<int> &a,int left,int right){
    while(left<right){
        swap(a[left],a[right]);
        left++;
        right--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    if(k>n){k=k%n;}
    reverseV(nums,0,n-1);
    reverseV(nums,0,k-1);
    reverseV(nums,k,n-1);    
    }
    void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> t={1,2,3,4,5,6,7};
    rotate(t,2);
    show(t);
    return 0;
}