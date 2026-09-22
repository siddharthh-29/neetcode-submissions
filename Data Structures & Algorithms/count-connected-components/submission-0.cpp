class Solution {
public:
    void dfs(int node, int parent, vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0)dfs(it,node,vis,adj);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,-1,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
