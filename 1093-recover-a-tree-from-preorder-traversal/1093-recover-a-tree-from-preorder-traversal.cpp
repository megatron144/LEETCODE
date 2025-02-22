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
public:
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*> v(1001,nullptr);
        vector<int> lr(1001,1);
        int cnt=0;
        int i=0,j=0,n=s.length();
        for(;i<n;i++){
            if(s[i]=='-'){
                cnt++;
                continue;
            }
            j=i;
            string str="";
            while(j<n && s[j]!='-'){
                str+=s[j];
                j++;
            }
            int data=stoi(str);
            if(cnt==0){
                v[0]=new TreeNode(data);
                i=j-1;
                continue;
            }
            TreeNode* tmp=new TreeNode(data);
            if(lr[cnt-1])
                v[cnt-1]->left=tmp;
            else
                v[cnt-1]->right=tmp;
            lr[cnt-1]=abs(lr[cnt-1]-1);
            if(v[cnt]!=tmp)lr[cnt]=1;
            v[cnt]=tmp;
            cnt=0;
            i=j-1;
        }
        return v[0];
    }
};