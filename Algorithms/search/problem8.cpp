
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Max(vector<int> s){
    int max=0;
    for(int i:s){
        if(i>max){
            max=i;
        }
    }
    return max;
}
int Sum(vector<int> s){
    int sum=0;
    for(int i:s){
        sum+=i;
    }
    return sum;
}
bool cantrans(vector<int> weights,int capacity,int days){
    int day = 1, current = 0;
    for (int w : weights) {
        if (current + w > capacity) {
            day++;
            current = 0;
        }
        current += w;
    }
    return day <= days;
}
int shipWithinDays(vector<int>& weights, int days) {
        int left=Max(weights);
        int right=Sum(weights);
       
        while(left<right){
            int mid=left+(right-left)/2;
            if(cantrans(weights,mid,days)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
int main(){

    return 0;
}