class Solution {
public:
    void f(int ind, int k, vector<int>&numbers, vector<int>&ans, vector<vector<int>>&final){
        if(ans.size()==k){
            final.push_back(ans);
            return;
        }
        if(ind==numbers.size())return;
        f(ind+1,k,numbers,ans,final);
        ans.push_back(numbers[ind]);
        f(ind+1,k,numbers,ans,final);
        ans.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>numbers;
        for(int i=0;i<n;i++)numbers.push_back(i+1);
        vector<int>ans;
        vector<vector<int>>final;
        f(0,k,numbers,ans,final);
        return final;
    }
};