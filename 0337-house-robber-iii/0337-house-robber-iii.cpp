/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int,int> post(TreeNode* root){
        if(!root)return {0,0};
        pair<int,int> l=post(root->left),r=post(root->right);
        int skip=max(l.first,l.second)+max(r.first,r.second);
        int take=root->val+l.first+r.first;
        return {skip,take};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> v=post(root);
        return max(v.first,v.second);
    }
};