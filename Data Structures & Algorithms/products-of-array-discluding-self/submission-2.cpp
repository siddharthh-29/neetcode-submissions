class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int prod=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;
            else prod=prod*nums[i];
        }
        vector<int>ans(nums.size(),0);
        if(zero>1){
            return ans;
        }
        else if(zero==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0)ans[i]=prod;
                else ans[i]=0;
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};
