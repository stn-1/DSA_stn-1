#include<iostream>
using namespace std;

struct Node{
    int val;
    Node*next;
};
Node* new_node(int val){
    Node * newnode=new Node();
    newnode->val=val;
    newnode->next=nullptr;
    return newnode;
}
void show_node(Node* head){
    Node* current = head;
    while (current != nullptr) {
        cout << current->val<< " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

   void push_back(Node*& head, int val) {
    Node* temp = new_node(val);
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp;
}
void push_front(Node* &head,int val){
    if(head==nullptr){
        head=new_node(val);
    }
    Node *temp=new_node(val);
    temp->next=head;
    head=temp;
}
void insert(Node* &head,int index,int val){
    Node* cur=head;
    Node* temp=new_node(val);
    if(index==0){
        push_front(head,val);
        return;
    }
    for(int i=0;i<index-1;i++){
        cur=cur->next;
        if(cur==nullptr){
            cout<<"out of range!";
            return;
        }
    }
    temp->next = cur->next;
    cur->next = temp;
}
void erase(Node*&head,int index){
    Node *cur=head;
    if(head==nullptr){
        cout<<"list is empty!";
        return;
    }
    if(index==0){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    for(int i=0;i<index-1;i++){
         if (cur == nullptr || cur->next == nullptr) {
            cout << "out of range!" << endl;
            return;
        }
        cur = cur->next;
    }
    if (cur->next == nullptr) {
    cout << "out of range!" << endl;
    return;
}
    Node* temp = cur->next;
    cur->next = cur->next->next;
    delete temp;
}
void clear(Node*&head){
    Node* cur=head;
    while(cur->next!=nullptr){
       Node* next=cur->next;
       delete cur;
       cur=next;
    }
    head=nullptr;
}
int main(){
    Node* head=new_node(1);
    push_back(head,12);
    push_front(head,0);
    insert(head,0,198);
    erase(head,0);
    show_node(head);
    

    //phần giải phóng bộ nhớ
        Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}