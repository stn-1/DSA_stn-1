#include<iostream>
#include <string>
using namespace std;
string mergeAlternately(string word1, string word2) {
    int n = word1.length();
    string a = word1 + word2;
    string re = "";
    int m = a.length();
    int p1 = 0;

    while (re.length() < m) {
        int p2 = p1 + n;
        if (p1 > n - 1) {
            re += a.substr(p2);
            return re;
        }
        if (p2 > m - 1) {
            re += a.substr(p1, a.length() - word1.length());
            return re;
        }
        re.push_back(a[p1]);
        re.push_back(a[p2]);
        p1++;
    }
    return "";
}
string solve2(string word1, string word2) {
    string re="";
    re.reserve(word1.size() + word2.size());
    int i=0,j=0;
    while(i<word1.length()||j<word2.length()){
        if (i < word1.size()) re.push_back(word1[i++]);
        if (j < word2.size()) re.push_back(word2[j++]);
    }
}
int main(){
    string word1 = "abc", word2 = "xyz";
    cout<<mergeAlternately(word1,word2);

    return 0;
}