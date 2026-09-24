class Solution {
public:
    int f(int mid, vector<int>&piles){
        int cnt=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid)cnt++;
            else{
                if(piles[i]%mid==0)cnt+=piles[i]/mid;
                else {
                    cnt+=piles[i]/mid;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int final=INT_MAX;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int ans=f(mid,piles);
            if(ans<=h){
                final=min(mid,final);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return final;
    }
};
