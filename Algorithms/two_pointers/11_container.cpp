#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxArea(vector<int>& height){
    int n=height.size();
    int re=0;
    int left=0;
    int right=n-1;
    while(left<right){
        int area=min(height[left],height[right])*(right-left);
        if(area>re){
            re=area;
        }
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
    }
    return re;
}
int main() {
    vector<int> h={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(h);
    return 0;
}