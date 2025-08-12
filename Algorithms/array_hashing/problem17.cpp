#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int profit = 0;
    int left=0;
    int right=1;
    while(left<prices.size()-1){
        if(prices[left]<prices[right]){
            profit+=(prices[right]-prices[left]);
            left=right;
            right++;
        }
    }
    right++;
    return profit;
}
int main(){
    vector<int> prices = {1, 2, 3, 4, 5};
    cout<<maxProfit(prices);

    return 0;
}