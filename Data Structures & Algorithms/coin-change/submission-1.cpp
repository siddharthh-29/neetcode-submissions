class Solution {
public:
    int f(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(ind==coins.size())return 1e9;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nt=f(ind+1,amount,coins,dp);
        int tk=1e9;
        if(coins[ind]<=amount){
            tk=f(ind,amount-coins[ind],coins,dp)+1;
        }
        return dp[ind][amount]=min(tk,nt);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=f(0,amount,coins,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};
