class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;
        int r=n-1;
        int maxi=0;
        while(l<=r){
            int mini=min(heights[l],heights[r]);
            int volume=mini*(r-l);
            maxi=max(maxi,volume);
            if(mini==heights[l])l++;
            else r--;
        }
        return maxi;
    }
};
