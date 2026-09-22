class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&grid){
        grid[i][j]='0';
        int a[]={0,1,0,-1};
        int b[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int x1=i+a[k];
            int y1=j+b[k];
            if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && grid[x1][y1]=='1'){
                dfs(x1,y1,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
