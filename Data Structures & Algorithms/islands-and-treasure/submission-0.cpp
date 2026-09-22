class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            int dis=grid[x][y];
            q.pop();
            int a[]={0,1,0,-1};
            int b[]={1,0,-1,0};
            for(int k=0;k<4;k++){
                int x1=x+a[k];
                int y1=y+b[k];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && grid[x1][y1]==INT_MAX){
                    q.push({x1,y1});
                    grid[x1][y1]=dis+1;
                }
            }
        }
    }
};
