 
#include<iostream>
#include<unordered_set>
#include<vector>
#include <string>
using namespace std;
 
 string longestCommonPrefix(vector<string>& strs) {
        string re="";
        char a=strs[0][0];
        if (strs.empty()) return "";
        for(int i=0;i<strs[0].length();i++){
            char a=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()<=i){
                    return re;
                }
                if(strs[j][i]!=a){
                    return re;
                }
            }
            re+=a;
        }
        return re;
    }
int main(){
    vector<string>strs = {"bat","bag","bank","band"};
    cout<<longestCommonPrefix(strs);
    return 0;
}