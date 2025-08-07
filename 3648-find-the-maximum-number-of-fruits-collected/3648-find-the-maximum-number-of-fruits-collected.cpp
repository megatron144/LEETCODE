class Solution {
public:
    int n;
    int solve(int row , int col , vector<vector<int>>&fruits , vector<vector<int>>&dp){
        if(row < 0 || row >= n || col < 0 || col >= n){
            return -1e9;
        }
        if(row == n-1 && col == n-1){
            return 0;
        }
        if(row == col){
            return -1e9;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int op1 = fruits[row][col] + max({solve(row-1 , col+1 , fruits ,dp),
                                        solve(row , col+1 , fruits ,dp),
                                        solve(row+1 , col+1 , fruits ,dp)});

        return dp[row][col] = op1;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int child1 = 0;
        for(int i=0 ; i<n ; i++){
            child1 += fruits[i][i];
        }
        vector<vector<int>>dp(n , vector<int>(n , -1));
        int child2 = solve(n-1 , 0 , fruits ,dp);
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){ 
                swap(fruits[j][i] , fruits[i][j]);
            }
        } 
        vector<vector<int>>dp2(n , vector<int>(n , -1)); 
        int child3 = solve(n-1 , 0 , fruits ,dp2);
        return child1 + child2 + child3 ;
    }
};