class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
            if(s[i]!=' '){
                if(s[i]>='A' && s[i]<='Z')ans+=s[i]-'A'+'a';
                else if(s[i]>='a' && s[i]<='z')ans+=s[i];
                else if(s[i]>='0' && s[i]<='9')ans+=s[i];
            }
            
        int i=0;
        int j=ans.size()-1;
        while(i<=j){
            if(ans[i]==ans[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
