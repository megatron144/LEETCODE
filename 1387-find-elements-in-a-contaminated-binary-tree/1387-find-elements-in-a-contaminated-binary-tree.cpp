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
class FindElements {
    TreeNode* head;
public:
    FindElements(TreeNode* root) {
        head=root;
    }
    bool find(int target) {
        vector<int> dir;
        int t=target;
        while(t){
            if(t&1){
                dir.push_back(1);
            }
            else{
                dir.push_back(0);
                t--;
            }
            t--;
            t=t>>1;
        }
        int i=dir.size()-1;
        TreeNode* tmp=head;
        if(!tmp)return false;
        for(;i>=0;i--){
            if((dir[i] && !(tmp->left)) || (!dir[i] && !(tmp->right)) )return false;
            if(dir[i])tmp=tmp->left;
            else tmp=tmp->right;
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */