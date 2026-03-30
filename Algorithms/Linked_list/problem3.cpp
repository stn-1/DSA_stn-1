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
        cout << head->val;                 
        if (head->next != nullptr)         
            cout << " -> ";                
        head = head->next;                 
    }
    cout << endl;                          
}
bool hasCycle(ListNode* head) {
        if(head==nullptr) return false;
        ListNode *cur=head;
        ListNode *pre=head;
        while(pre!=nullptr&&pre->next!=nullptr){
            cur=cur->next;
            pre=pre->next->next;
            if(pre==cur) return true;    
        }
        return false;
    }
int main(){


    return 0;
}