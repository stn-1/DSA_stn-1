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
ListNode* reverseList(ListNode* head) {
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *nxt = NULL;

    while (cur != NULL) {
        nxt = cur->next;   
        cur->next = pre;   
        pre = cur;         
        cur = nxt;         
    }
    return pre; 
}
int main(){
    ListNode *n1=new ListNode(4);
    ListNode *n2=new ListNode(5,n1);
    ListNode *n3=new ListNode(6,n2);
    ListNode *head=n3;
    showList(head);
    
    return 0;
}