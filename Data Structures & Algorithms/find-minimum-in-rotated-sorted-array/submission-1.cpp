class Solution {
public:
    int findMin(vector<int> &nums) {
        int min_index=-1;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                min_index=i;
            }
        }
        return mini;
    }
};
