#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int re=0;
        int left=0;
        int right=people.size()-1;
        
        while(left<=right){
            if(people[left]+people[right]>limit){
                right--;
                re++;
            }else{
                re++;
                left++;
                right--;
            }
       }
       return re;
    }
int main(){
     vector<int> people = {5,1,4,2}; 
     int limit = 6;
     cout<<numRescueBoats(people,limit);
    return 0;
}