class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        string ans="";
        //odd length substrings
        for(int i=0;i<n;i++){
            int ptr=i;
            int l=ptr-1;
            int r=ptr+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(r-l+1>maxi){
                maxi=max(maxi,r-l+1);
                int start=l;
                int end=r;
                ans=s.substr(start,end-start+1);
            }
        }
        //even length substrings
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                int l=i-1;
                int r=i+2;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        l--;
                        r++;
                    }
                    else break;
                }
                l++;
                r--;
                if(r-l+1>maxi){
                    maxi=max(maxi,r-l+1);
                    int start=l;
                    int end=r;
                    ans=s.substr(start,end-start+1);
                }
            }
        }
        return ans;
    }
};
