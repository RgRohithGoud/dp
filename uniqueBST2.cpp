#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    vector<TreeNode*> solve(int i,int j){
        vector<TreeNode*> v;
        if(i>j){
            v.push_back(NULL);
            return v;
        }
        if(i==j){
            v.push_back(new TreeNode(i));
            return v;
        }
        for(int k=i;k<=j;k++){
            vector<TreeNode*> left = solve(i,k-1);
            vector<TreeNode*> right = solve(k+1,j);
            for(auto x: left){
                for(auto y : right){
                    TreeNode* root = new TreeNode(k);
                    root->left = x;
                    root->right = y;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans =  solve(1,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<TreeNode*> v = generateTrees(n);
    return 0;
}