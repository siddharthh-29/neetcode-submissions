class Solution {
public:
    void f(int ind, int target, vector<int>&ans, vector<int>&nums,vector<vector<int>>&final){
        if(ind==nums.size() && target==0){
            final.push_back(ans);
        }
        if(ind==nums.size())return;
        f(ind+1,target,ans,nums,final);
        if(nums[ind]<=target){
            ans.push_back(nums[ind]);
            target-=nums[ind];
            f(ind,target,ans,nums,final);
            target+=nums[ind];
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<vector<int>>final;
        f(0,target,ans,nums,final);
        return final;
    }
};
