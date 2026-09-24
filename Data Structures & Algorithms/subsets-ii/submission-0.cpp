class Solution {
public:
    void f(int ind, vector<int>&nums, vector<int>&ans, vector<vector<int>>&final){
        if(ind==nums.size()){
            final.push_back(ans);
            return;
        }
        ans.push_back(nums[ind]);
        f(ind+1,nums,ans,final);
        ans.pop_back();
        if(ind<nums.size()-1 && nums[ind]==nums[ind+1]){
            while(ind<nums.size()-1 && nums[ind]==nums[ind+1])ind++;
            f(ind+1,nums,ans,final);
        }
        else f(ind+1,nums,ans,final);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>final;
        sort(nums.begin(),nums.end());
        f(0,nums,ans,final);
        return final;
    }
};
