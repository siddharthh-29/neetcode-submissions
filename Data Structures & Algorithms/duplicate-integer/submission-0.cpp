class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)st.insert(nums[i]);
        if(st.size()==n)return false;
        else return true;
    }
};