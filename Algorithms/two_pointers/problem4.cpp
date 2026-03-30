#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;         
    int p2 = n - 1;          
    int p = m + n - 1;       
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
    }
void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> nums1 = {10,20,20,40,0,0};
    int m = 4;
     vector<int> nums2 = {1,2};
    int n = 2;
    merge(nums1,m,nums2,n);
    show(nums1);
    return 0;
}