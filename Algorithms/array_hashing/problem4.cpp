 
#include<iostream>
#include<unordered_set>
#include<vector>
#include <string>
#include <array>
#include<map>
#include<algorithm>
using namespace std;
 
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<string,vector<string>> mp;
        for(string s :strs){
            string sorted=s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        vector<vector<string>> re;
       for (auto& [key, group] : mp) {
        re.push_back(group);
    }
        
return re;
        
    }
int main(){
    
    return 0;
}