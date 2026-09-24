class Solution {
public:
    void f(int open, int close, int n, string ans, vector<string>&final){
        if(open==close & open==n){
            final.push_back(ans);
        }
        if(open<n){
            f(open+1,close,n,ans+'(',final);
        }
        if(open>close){
            f(open,close+1,n,ans+')',final);
        }
    }

    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string>final;
        f(0,0,n,ans,final);
        return final;
    }
};
