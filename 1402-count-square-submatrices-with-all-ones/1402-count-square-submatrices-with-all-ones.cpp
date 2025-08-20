class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> mat(matrix.size(),vector<int> (matrix[0].size(),0));
        int ans=0;
        for(int j=0;j<matrix[0].size();j++){
            mat[0][j]=matrix[0][j];
            ans+=mat[0][j];
        }
        for(int j=1;j<matrix.size();j++){
            mat[j][0]=matrix[j][0];
            ans+=mat[j][0];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    mat[i][j]=min(mat[i-1][j],min(mat[i-1][j-1],mat[i][j-1]))+1;
                    ans+=mat[i][j];
                }
            }
        }
        return ans;
    }
};