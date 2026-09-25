class Solution {
public:
    int sqr(int n){
        int sum=0;
        while(n){
            int digit=n%10;
            sum+=(digit*digit);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        while(true){
            if(n==1)return true;
            else if(st.find(n)!=st.end())return false;
            st.insert(n);
            n=sqr(n);
        }
        return false;
    }
};
