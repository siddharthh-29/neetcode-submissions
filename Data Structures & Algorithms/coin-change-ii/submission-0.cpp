class Solution {
public:
    int f(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(amount==0)return 1;
        if(ind==coins.size())return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nt=f(ind+1,amount,coins,dp);
        int tk=0;
        if(coins[ind]<=amount)tk=f(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=nt+tk;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=f(0,amount,coins,dp);
        return ans;
    }
};
