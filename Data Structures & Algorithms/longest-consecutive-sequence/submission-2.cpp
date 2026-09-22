class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1)==st.end()){
                int cnt=1;
                int elem=nums[i];
                while(st.find(elem+1)!=st.end()){
                    cnt++;
                    elem++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
