class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(distance[it.first]>dis+it.second){
                    distance[it.first]=dis+it.second;
                    pq.push({distance[it.first],it.first});
                }
            }
        }
        int mini=INT_MIN;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX)return -1;
            else if(i!=k)mini=max(mini,distance[i]);
        }
        return mini;
    }
};
