//đây là bài mở rộng của Boyer-Moore Voting Algorithm
#include<iostream>
#include<vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
   int n=nums.size();
   int count1=0; int count2=0;
   int can1=0; int can2=1;
   for(int num:nums){
     if(num==can1){
        count1++;
     }
     else if(num==can2){
        count2++;
     }
     else if(count1==0){
        can1=num;
        count1=1;
     }
     else if(count2==0){
        can2=num;
        count2=1;
     }
     else{
        count1--;
        count2--;
     }
   }
   count1=0;
   count2=0;
   for(int num:nums){
    if(num==can1){
        count1++;
    } 
    else if(num==can2){
        count2++;
    }
   }
   vector<int> re;
   if(count1>n/3){re.push_back(can1);}
   if(count2>n/3){re.push_back(can2);}
   return re;
}
void show(vector<int> nums){
    for( int i:nums){
        cout<<i<<" ";
    }
}
int main(){
   vector<int> nums = {5,2,3,2,2,2,2,5,5,5};
    show(majorityElement(nums));

    return 0;
}