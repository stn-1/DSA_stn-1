#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void showList(ListNode *head) {
    while (head != nullptr) {              
        cout << head->val;                 // in giá trị
        if (head->next != nullptr)         // nếu còn node tiếp theo
            cout << " -> ";                // in mũi tên
        head = head->next;                 // chuyển sang node kế
    }
    cout << endl;                          // xuống dòng khi in xong
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val > list2->val)
        std::swap(list1, list2);

    ListNode* head = list1;  
    ListNode* pre1 = list1;
    ListNode* pre2 = list2;

    while (pre1 != nullptr && pre2 != nullptr) {
        if (pre1->next == nullptr || pre1->next->val > pre2->val) {
            ListNode* temp = pre2->next;
            pre2->next = pre1->next;
            pre1->next = pre2;
            pre2 = temp;  
        } else {
            pre1 = pre1->next; 
        }
    }

    return head;
}
};
int main(){
    cout<<"hello";
    return 0;
}