
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class MountainArray {
    public:
      int get(int index);
      int length();
  };

int findInMountainArray(int target, MountainArray &mountainArr) {
        int left=0;
        int right=mountainArr.length()-1;
        int n=mountainArr.length();
        while(left<right){
            int mid = (left + right) / 2;
            int midVal = mountainArr.get(mid);
            int nextVal = mountainArr.get(mid + 1);
            if (midVal < nextVal)
                left = mid + 1; 
            else
                right = mid;   
            }
            int peak=left;
             int index = binarySearch(mountainArr, 0, peak, target, true);
             if (index != -1) return index;

             return binarySearch(mountainArr, peak + 1, n - 1, target, false);
        }

int binarySearch(MountainArray &mountainArr, int left, int right, int target, bool ascending) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;

            if (ascending) {
                if (val < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (val > target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }

int main(){
    
    return 0;
}