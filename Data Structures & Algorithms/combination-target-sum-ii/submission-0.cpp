class Solution {
public:
    void f(int ind, int target, vector<int>&ans, vector<int>&candidates, vector<vector<int>>&final){
        if(ind==candidates.size()){
            if(target==0){
                final.push_back(ans);
                return;
            }
            else return;
        }
        //take
        if(candidates[ind]<=target){
            ans.push_back(candidates[ind]);
            target-=candidates[ind];
            f(ind+1,target,ans,candidates,final);
            target+=candidates[ind];
            ans.pop_back();
        }
        //not take
        if(ind<candidates.size()-1 && candidates[ind]==candidates[ind+1]){
            while(ind<candidates.size()-1 && candidates[ind]==candidates[ind+1])ind++;
        }
        f(ind+1,target,ans,candidates,final);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        vector<vector<int>>final;
        f(0,target,ans,candidates,final);
        return final;
    }
};
