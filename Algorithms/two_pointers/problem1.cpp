#include<iostream>
#include<vector>
using namespace std;
void reverseString(vector<char>& s) {
        int n=s.size();
        int left=0, right=n-1;
        while (left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    void show(vector<char> nums){
    for( auto i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<char>  s ={'n','e','e','t'};
    reverseString(s);
    show(s);
    return 0;
}