#include<iostream>
#include<vector>
using namespace std;
int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n=s.length();
        int left=0;
        int mcount=0;
        int mlen=0;
        int right=0;
        while(right<n){
            int index=s[right]-'A';
            freq[index]++;
            mcount=max(mcount,freq[index]);
            while(right-left+1-mcount>k){
                freq[s[left]-'A']--;
                left++;
            }
            mlen=max(mlen,right-left+1);
            right++;
        }
        return mlen;
    }
int main(){

    cout << characterReplacement("ABAB", 2);
    cout << characterReplacement("AABABBA", 1);
    return 0;
    return 0;
}