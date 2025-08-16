/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*,TreeNode*> par;
    vector<int> ans;
    vector<int> vis;
    void dfs(TreeNode* root){
        if(root->left)par[root->left]=root,dfs(root->left);
        if(root->right)par[root->right]=root,dfs(root->right);
    }
    void call(TreeNode* root,int k){
        if(!root)return;
        if(vis[root->val])return;
        if(k==0){
            if(root)ans.push_back(root->val);
            return;
        }
        vis[root->val]=1;
        call(root->left,k-1);
        call(root->right,k-1);
        if(par[root]!=root)call(par[root],k-1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        par[root]=root;
        dfs(root);
        //for(auto x: par)cout<<x.first->val<<" "<<x.second->val<<endl;
        vis.resize(501,0);
        call(target,k);
        return ans;
    }
};