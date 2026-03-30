
#include<iostream>
#include<vector>
using namespace std;
 int pick=5;
 int guess(int num){
    if(num<pick) return -1;
    else if(num>pick) return 1;
    else return 0;
 }
 int guessNumber(int n) {
    int left=1;
    int right=n;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(guess(mid)==0) return mid;
        if(guess(mid)==-1){
            right=mid-1;
        }
        if(guess(mid)==1) left=mid+1;
        cout<<mid<<" ";
    }
        return -1;
    }
int main(){
    
    cout<<guessNumber(15);
    return 0;
}