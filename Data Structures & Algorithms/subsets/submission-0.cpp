class Solution {
public:
    void f(int ind, vector<int>&nums, vector<int>&ans, vector<vector<int>>&final){
        if(ind==nums.size()){
            final.push_back(ans);
            return;
        }
        f(ind+1,nums,ans,final);
        ans.push_back(nums[ind]);
        f(ind+1,nums,ans,final);
        ans.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>final;
        f(0,nums,ans,final);
        return final;
    }
};
