class Solution {
public:
    int f(int n, vector<int>&cost, vector<int>&dp){
        if(n==0 || n==1)return 0;
        if(dp[n]!=-1)return dp[n];
        int a=f(n-1,cost,dp)+cost[n-1];
        int b=f(n-2,cost,dp)+cost[n-2];
        return dp[n]=min(a,b);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        int ans=f(cost.size(),cost,dp);
        return ans;
    }
};
