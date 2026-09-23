class Solution {
public: 
    int f(int ind, vector<int>&nums, vector<int>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int a=f(ind+1,nums,dp);
        int b=f(ind+2,nums,dp)+nums[ind];
        return dp[ind]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,-1);
        int ans=f(0,nums,dp);
        return ans;
    }
};
