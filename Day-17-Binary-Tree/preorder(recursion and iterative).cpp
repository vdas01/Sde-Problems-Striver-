//https://leetcode.com/problems/binary-tree-preorder-traversal/
//Recursion:-
class Solution {
public:
    void result(TreeNode* root,vector<int>&v){
        if(!root) return;
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        else{
            v.push_back(root->val);
            result(root->left,v);
            result(root->right,v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        if(!root) return preorder;
       result(root,preorder);
        return preorder;
    }
};
//Iterative:-
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        if(!root) return preorder;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            preorder.push_back(root->val);
            if(root->right)
                s.push(root->right);
            if(root->left)
                s.push(root->left);
        }
        return preorder;
    }
};