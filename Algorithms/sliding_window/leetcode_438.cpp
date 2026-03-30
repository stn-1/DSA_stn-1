
// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average
// value and return this value. Any answer with a calculation error less than 10-5 will be accepted.


#include<iostream>
#include<vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
        vector<int>r;
        int n=s.length();
        int m=p.length();
        vector<int> freq(26,0);
        for(char i:p){
            freq[i-'a']++;
        }
        vector<int> win_freq(26,0);
        for(int i=0;i<m;i++){
            win_freq[s[i]-'a']++;
        }
        if(freq==win_freq) r.push_back(0);
        for(int i=m;i<n;i++){
            win_freq[s[i]-'a']++;
            win_freq[s[i-m]-'a']--;
            if(freq==win_freq) r.push_back(i-m+1);
        }
        
        return r;
    }
    void show(vector<int>r){
        for(int i:r){
            cout<<i<<" ";
        }
    }
int main() {
    string s = "cbaebabacd";
    string p = "abc";
    show(findAnagrams(s,p));
    return 0;
}
