
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Impossible target conditions
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int s1 = (totalSum + target) / 2;
        vector<int> dp(s1 + 1, 0);
        
        // Base case: 1 way to get a sum of 0 (by choosing an empty subset)
        dp[0] = 1;

        for (int num : nums) {
            // Iterate backwards to use values from the previous iteration
            for (int j = s1; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[s1];
    }
};