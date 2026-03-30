#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;

int calPoints(vector<string>& operations) {
        int sum=0;
        vector<int> stack;
        for(string i:operations){
            if(i=="C"){
                if (!stack.empty()) stack.pop_back();
            }else if(i=="D"){
                if (!stack.empty()) stack.push_back(2 * stack.back());
            }else if(i=="+"){
                stack.push_back(stack.back() + stack[stack.size() - 2]);
            }else{
                stack.push_back(stoi(i));
            }
        }
        for(int i:stack){
            sum+=i;
        }
        return sum;
    }
int main() {
    return 0;
}