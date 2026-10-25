class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=accumulate(gas.begin(),gas.end(),0);
        int cost_total=accumulate(cost.begin(),cost.end(),0);
        if(cost_total>total_gas)return -1;
        else{
            int fuel=0;
            int startIndex=0;
            for(int i=0;i<n;i++){
                fuel+=gas[i];
                fuel-=cost[i];
                if(fuel>=0)continue;
                else {
                    startIndex=i+1;
                    fuel=0;
                }
            }
            return startIndex;
        }
        return 0;
    }
};
