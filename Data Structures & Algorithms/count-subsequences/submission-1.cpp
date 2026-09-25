class Solution {
public:
    int f(int i, int j, string&s, string &t, vector<vector<int>>&dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            int include=f(i+1,j+1,s,t,dp);
            int exclude=f(i+1,j,s,t,dp);
            return dp[i][j]=include+exclude;
        }
        else{
            return dp[i][j]=f(i+1,j,s,t,dp);
        }
        return 1;
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        int ans=f(0,0,s,t,dp);
        return ans;
    }
};
