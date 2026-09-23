class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ans.size()==0 || nums[i]>ans.back())ans.push_back(nums[i]);
            else{
                auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
                if(it!=ans.end())
                *it=nums[i];
            }
        }
        return ans.size();
    }
};
