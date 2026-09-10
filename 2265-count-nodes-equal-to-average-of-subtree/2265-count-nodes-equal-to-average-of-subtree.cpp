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
    vector<int> ans;
private:
    pair<int,int> dfs(TreeNode* root){
        if(!root)return {0,0};
        pair<int,int> l=dfs(root->left);
        pair<int,int> r=dfs(root->right);
        int sum=l.first+r.first+root->val;
        int sz=l.second+r.second+1;
        if(sum/sz == root->val){
            ans.push_back(root->val);
            cnt++;
        }
        return {sum,sz};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        cnt=0;
        dfs(root);
        for(auto x: ans)cout<<x<<" ";
        return cnt;
    }
};