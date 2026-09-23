class Solution {
public:
    bool f(int ind, int sum, vector<int>&nums, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(ind==nums.size())return false;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        bool nt=f(ind+1,sum,nums,dp);
        bool tk=false;
        if(nums[ind]<=sum){
            tk=f(ind+1,sum-nums[ind],nums,dp);
        }
        return dp[ind][sum]=nt||tk;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        else{
            sum=sum/2;
            int n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
            return f(0,sum,nums,dp);
        }
        return true;
    }
};
