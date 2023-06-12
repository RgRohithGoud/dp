#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int a){
        val = a;
        left = NULL;
        right = NULL;
    }
};

int solve(Node* root,int* res){
    if(root==NULL) return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    int temp = max(root->val + max(l,r),root->val);  //if l =-ve and r = -ve no need of taking them
    int ans = max(temp,root->val +l+r);
    *res = max(*res,ans);
    return temp;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(0);
    root->right->right = new Node(3);
    root->left->left = new Node(-10);
    int a = 0;
    int d = solve(root,&a);
    cout<<a<<endl;
    return 0;
}