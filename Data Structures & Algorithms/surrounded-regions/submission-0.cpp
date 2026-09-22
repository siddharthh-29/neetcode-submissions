class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&board){
        board[i][j]='t';
        int a[]={0,1,0,-1};
        int b[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int x1=i+a[k];
            int y1=j+b[k];
            if(x1>=0 && x1<board.size() && y1>=0 && y1<board[0].size() && board[x1][y1]=='O'){
                board[x1][y1]='t';
                dfs(x1,y1,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<n;i++)if(board[0][i]=='O')dfs(0,i,board);
        for(int i=0;i<n;i++)if(board[m-1][i]=='O')dfs(m-1,i,board);
        for(int i=0;i<m;i++)if(board[i][0]=='O')dfs(i,0,board);
        for(int i=0;i<m;i++)if(board[i][n-1]=='O')dfs(i,n-1,board);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='t')board[i][j]='O';
            }
        }
    }
};
