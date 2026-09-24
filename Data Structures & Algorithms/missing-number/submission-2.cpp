class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            x=x^nums[i];
            x=x^i;
        }
        x=x^0;
        x=x^nums.size();
        return x;
    }
};
