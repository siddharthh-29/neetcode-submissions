class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        int a[]={0,1,0,-1};
        int b[]={1,0,-1,0};
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[0][0]=1;
        while(!pq.empty()){
            int time_taken=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==m-1 && y==n-1)return time_taken;
            pq.pop();
            for(int k=0;k<4;k++){
                int x1=x+a[k];
                int y1=y+b[k];
                if(x1>=0 && x1<m && y1>=0 && y1<n && vis[x1][y1]==0){
                    if(grid[x1][y1]<=time_taken){
                        pq.push({time_taken,{x1,y1}});
                        vis[x1][y1]=1;
                    }
                    else{
                        pq.push({grid[x1][y1],{x1,y1}});
                        vis[x1][y1]=1;
                    }
                }
            }
        }
        return -1;
    }
};
