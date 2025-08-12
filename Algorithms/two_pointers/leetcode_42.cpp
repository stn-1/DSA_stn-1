#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 int trap_greedy(vector<int>& height) {
        int p1=0;
        int p2;
        int total=0;
        while(p1<height.size()){
            while(height[p1]<height[p1+1]){
                if(p1==height.size()-1) return 0;
                p1=p1+1;   
                p2=p1+1;         
            }
            while(height[p2]>=height[p2+1]){
                p2++;
            }
            for(int i=1;i<p2-p1;i++){
                total-=height[i];
            }
            total+=max(height[p1],height[p2])*abs(p1-p2-1);
            p1=p2;
        }
        return total;
    }
    //o(n) memory
int trap1(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> maxleft(n), maxright(n);
    maxleft[0] = height[0];
    for (int i = 1; i < n; ++i)
        maxleft[i] = max(maxleft[i - 1], height[i]);

    maxright[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i)
        maxright[i] = max(maxright[i + 1], height[i]);

    int water = 0;
    for (int i = 0; i < n; ++i)
        water += max(min(maxleft[i], maxright[i]) - height[i], 0);

    return water;
}
int trap2(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int maxL = 0, maxR = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= maxL)
                maxL = height[left];
            else
                water += maxL - height[left];
            ++left;
        } else {
            if (height[right] >= maxR)
                maxR = height[right];
            else
                water += maxR - height[right];
            --right;
        }
    }
    return water;
}
int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap2(height);
    return 0;
}