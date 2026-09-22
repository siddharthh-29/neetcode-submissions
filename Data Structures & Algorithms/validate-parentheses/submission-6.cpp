class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                char x=s[i];
                if(x=='}'){
                    if(!st.empty() && st.top()=='{'){
                        st.pop();
                        continue;
                    }
                    else return false;
                }
                else if(x==')'){
                    if(!st.empty() && st.top()=='('){
                        st.pop();
                        continue;
                    }
                    else return false;
                }
                else if(x==']'){
                    if(!st.empty() && st.top()=='['){
                        st.pop();
                        continue;
                    }
                    else return false;
                }
            }
        }
        if(st.size()>0)return false;
        return true;
    }
};
