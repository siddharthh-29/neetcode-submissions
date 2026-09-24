class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int max_sum=INT_MIN;
        int r=0;
        int l=0;
        while(r<n){
            if(sum+nums[r]>=nums[r])sum+=nums[r];
            else sum=nums[r];
            max_sum=max(max_sum,sum);
            r++;
        }
        return max_sum;
    }
};
