class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,INT_MAX);
        dp[0]=0;
        for(int ind=0;ind<n;ind++){
            for(int i=0;i<=nums[ind];i++){
                if(ind+i<n)dp[ind+i]=min(dp[ind]+1,dp[ind+i]);
            }
        }
        return dp[n-1];
    }
};
