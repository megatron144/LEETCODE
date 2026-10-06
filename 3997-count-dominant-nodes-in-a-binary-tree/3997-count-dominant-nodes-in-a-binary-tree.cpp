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
    pair<int,int> f(TreeNode* node) {
        if(!node)return {0,0};
        auto [c1,mx1]=f(node->left);
        auto [c2,mx2]=f(node->right);
        int res=c1+c2;
        int mx=max({mx1,mx2,node->val});
        res=c1+c2+(mx==node->val);
        return {res,mx};
    }
public:
    int countDominantNodes(TreeNode* root) {
        return f(root).first;
    }
};