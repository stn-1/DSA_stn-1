#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(vector<int> &f) {
    for (int i : f) {
        if (i > 0) return false;
    }
    return true;
}

string minWindow1(string s, string t) {
    int n = s.size();
    if (t.size() > n) return "";

    vector<int> freq(128, 0); // dùng full ASCII
    for (char c : t) freq[c]++;

    int left = 0, minLen = n + 1, start = 0;
    for (int right = 0; right < n; right++) {
        freq[s[right]]--;

        while (check(freq)) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            freq[s[left]]++;
            left++;
        }
    }

    return (minLen == n + 1) ? "" : s.substr(start, minLen);
}
string minWindow(string s, string t) {
        int n=s.length();
        int minLen=n+1;
        int need = t.size();  // số ký tự cần
        int left=0;
        int start = 0;  
        vector<int> freq(128,0);
        for (char c : t) freq[c]++;

        for (int right = 0; right < n; right++) {
            if (--freq[s[right]] >= 0) need--; // lấy được 1 ký tự cần
            while (need == 0) {
                // update kết quả
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (++freq[s[left]] > 0) need++; // mất 1 ký tự cần
                left++;
            }
        }
        return (minLen == n + 1) ? "" : s.substr(start, minLen);
    }
int main() {
    string s = "xyz", t = "xyz";
    cout << minWindow(s, t) << endl;
    return 0;
}
