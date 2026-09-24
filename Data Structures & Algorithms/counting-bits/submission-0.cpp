class Solution {
public:
    int f(int n){
        int cnt=0;
        while(n){
            if(n%2==1)cnt++;
            n/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=f(i);
        }
        return ans;
    }
};
