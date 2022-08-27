//https://leetcode.com/problems/binary-tree-inorder-traversal/
//Recursion:-
class Solution {
public:
    vector<int> result(TreeNode* root,vector<int>&v){
         if(!root) return v;
        if(!root->left && !root->right){
            v.push_back(root->val);
            return v;
        }
        result(root->left,v);
                v.push_back(root->val);
        result(root->right,v);
        return v;

    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>v;
        return result(root,v);
    }
};
//Iterative:-
class Solution {
public:
    vector<int> result(TreeNode* root,vector<int>&v){
         if(!root) return v;
        if(!root->left && !root->right){
            v.push_back(root->val);
            return v;
        }
        result(root->left,v);
                v.push_back(root->val);
        result(root->right,v);
        return v;

    }
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*>s;
        vector<int>inorder;
        TreeNode* temp = root;
        while(true){
            if(temp){
                s.push(temp);
                temp=temp->left;
            }
            else{
                if(s.empty()) break;
                temp = s.top();
                s.pop();
                inorder.push_back(temp->val);
                temp = temp->right;
            }
        }
        return inorder;
    }
};