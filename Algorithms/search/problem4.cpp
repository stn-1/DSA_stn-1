
#include<iostream>
#include<vector>
using namespace std;
  int mySqrt(int x) {
    int left=1;
    int right=x/2;
    int ans=1;
    while(left<=right){
        int mid=left+(right-left)/2;
        long long dis = 1LL * mid * mid-x; 
        if(dis==0){
            return mid;
        }else if(dis<0){
             ans=mid;
             left=mid+1;
        }else{
           right=mid-1;
           
        }
       
    }
         return ans;
    }
int main(){
    cout<<mySqrt(10);
    return 0;
}