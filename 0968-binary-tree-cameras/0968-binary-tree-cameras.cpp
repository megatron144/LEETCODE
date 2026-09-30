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
int cnt;
private:
    int dfs(TreeNode* root){
        if(!root)return 2;
        int l=dfs(root->left),r=dfs(root->right);
        if(!l | !r){
            cnt++;
            return 1;
        }
        return (l==1 | r==1)?2:0;
    }
public:
    int minCameraCover(TreeNode* root) {
        cnt=0;
        return (dfs(root)?0:1)+cnt;
    }
};