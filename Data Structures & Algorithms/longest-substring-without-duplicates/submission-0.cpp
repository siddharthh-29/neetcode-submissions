class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int n=s.size();
        int maxi=0;
        while(r<n){
            mp[s[r]]++;
            if(mp.size()<r-l+1){
                while(mp.size()<r-l+1){
                    mp[s[l]]--;
                    if(mp[s[l]]==0)mp.erase(s[l]);
                    l++;
                }
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
