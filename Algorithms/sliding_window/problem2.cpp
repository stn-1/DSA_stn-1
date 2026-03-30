#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
 int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int left = 0;
    int maxLength = 0;
    for (int right = 0; right < s.length(); right++) {
        char currentChar = s[right];
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
            left = charIndex[currentChar] + 1;
        }
        
        charIndex[currentChar] = right; 
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
    }
int main(){

    return 0;
}