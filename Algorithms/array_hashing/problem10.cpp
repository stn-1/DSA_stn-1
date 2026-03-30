// Bucket Sort
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 string encode(vector<string>& strs) {
    string re="";
    for(string i:strs){
        string s=to_string(i.length())+"#";
        re+=(s+i);
    }
    return re;    
}

     vector<string> decode(string s) {
        vector<string> re;
        int i=0;
        while(i<s.size()){
            int index=s.find("#",i);
            int n = stoi(s.substr(i, index - i));
            i=index+1;
            re.push_back(s.substr(i,n));
            i+=n;
        }
        return re;
    }
    void show(vector<string> strs){
    for( string i:strs){
        cout<<i<<" ";
    }
}
int main(){
    vector<string> str= {"neet","code","love","you"};
    cout<<"encode: "<<encode(str)<<endl;
    cout<<"decode: ";
    show(decode(encode(str)));
    return 0;
}