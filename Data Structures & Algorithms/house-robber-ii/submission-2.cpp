class Solution {
public:
    int f(int ind, vector<int>&arr1,vector<int>&dp){
        if(ind>=arr1.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int a=f(ind+1,arr1,dp);
        int b=f(ind+2,arr1,dp)+arr1[ind];
        return dp[ind]=max(a,b);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n=nums.size();
        vector<int>arr1(n-1);
        vector<int>arr2(n-1);
        for(int i=0;i<n-1;i++){
            arr1[i]=nums[i];
            arr2[i]=nums[i+1];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(f(0,arr1,dp1),f(0,arr2,dp2));
    }
};
