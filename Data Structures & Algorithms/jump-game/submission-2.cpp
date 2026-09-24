class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int max_dis=0;
        while(r<n-1){
            for(int i=l;i<=r;i++){
                max_dis=max(max_dis,i+nums[i]);
            }
            if(max_dis>l){
                l++;
                r=max_dis;
            }
            else return false;
        }
        return true;
    }
};
