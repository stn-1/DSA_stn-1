
#include<iostream>
#include<vector>
using namespace std;
 
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l= 0;
        int r=n-1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r+1;
    }
int main(){
    vector<int> nums={-1,0,2,4,6,8};
    cout<<searchInsert(nums,4);
    return 0;
}
// | Mục tiêu bài toán       | Dạng vòng lặp           | Cập nhật                                  |
// | ----------------------- | ----------------------- | ----------------------------------------- |
// | Tìm phần tử chính xác   | `while (left <= right)` | loại bỏ mid (`+1` hoặc `-1`)              |
// | Tìm ranh giới / cực trị | `while (left < right)`  | giữ mid (`right = mid`, `left = mid + 1`) |
