
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Max(vector<int> s){
    int max=-99999999;
    for(int i:s){
        if(i>max){
            max=i;
        }
    }
    return max;
}
bool check(vector<int> &s,int k,int h){
     int count = 0;
    for (int i : s) {
        count += (i + k - 1) / k; 
    }
    return count <= h;
}
  int minEatingSpeed(vector<int>& piles, int h) {
    int l=1;
    int r=Max(piles);
    while(l<=r){
        int mid=l+(r-l)/2;
        if (check(piles, mid, h)) {
            r = mid - 1;
        } else {
            l = mid + 1; 
        }

    }
    return l;
}
int main(){
    vector  <int> piles={1,2,3};

    return 0;
}