class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int a[]={0,1,0,-1};
        int b[]={1,0,-1,0};
        int ans=0;
        while(!q.empty()){
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            ans=max(ans,dis);
            q.pop();
            for(int k=0;k<4;k++){
                int x1=x+a[k];
                int y1=y+b[k];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && grid[x1][y1]==1){
                    grid[x1][y1]=2;
                    q.push({dis+1,{x1,y1}});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};
