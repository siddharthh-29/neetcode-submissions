class Solution {
public:
    int f(int ind, int buy, vector<int>&prices, vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy==0){
            //it means i can buy
            int buy_now=f(ind+1,1,prices,dp)-prices[ind];
            int buy_later=f(ind+1,0,prices,dp);
            return dp[ind][buy]=max(buy_now,buy_later);
        }
        else{
            int sell_now=f(ind+2,0,prices,dp)+prices[ind];
            int sell_later=f(ind+1,1,prices,dp);
            return dp[ind][buy]=max(sell_now,sell_later);
        }
        return 0;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans=f(0,0,prices,dp);
        return ans;
    }
};
