#include<iostream>
using namespace std;

struct node
{
    int data;
    node*left;
    node*right;

    node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
    
};
node* Insert(node*&root,int value){
    if(root==nullptr){
        return new node(value);
    }
    if(value < root->data){
        root->left=Insert(root->left,value);
    }else{
        root->right=Insert(root->left,value);
    }
    return root;
}

int main(){
    cout<<"hello";

    return 0;
}