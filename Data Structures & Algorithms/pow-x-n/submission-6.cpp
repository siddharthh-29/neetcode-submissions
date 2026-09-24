class Solution {
public:
    double power(double x, long long n){
        if(n==0)return 1;
        double y=power(x,n/2);
        if(n%2==0)return y*y;
        else return x*y*y;
    }
    
    double myPow(double x, int n) {
        if(x==1)return 1;
        if(x==-1){
            if(n%2==0)return 1;
            else return -1;
        }
        if(n==0)return 1;
        long long N=n;
        if(n<0){
            N=N*-1;
            return power(1/x,N);
        }
        return power(x,N);
    }
};
