#include<iostream>
#include<vector>
using namespace std;
bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int left=0;
        int right=s1.length()-1;
        vector<int> freq1(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }
        vector<int> freq2(26,0);
        for(int i= left;i<=right;i++){
                freq2[s2[i]-'a']++;
            }
        while(right<s2.length()){
            
            if(freq1==freq2){
                return true;
            }else{
                left++;
                right++;
                freq2[s2[left-1]-'a']--;
                freq2[s2[right]-'a']++;
            }
        }
        return false;
    }
int main(){
string s1 = "abc", s2 = "lecabee";
cout<<checkInclusion(s1,s2);
    return 0;
}