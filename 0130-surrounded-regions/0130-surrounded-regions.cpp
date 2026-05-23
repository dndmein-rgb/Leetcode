class Solution {
public:
    
    int n,m;
    void dfs(int i,int j,vector<vector<char>>& board){
        if(i<0 || i>=n || j<0 ||j>=m )return ;
        if(board[i][j]=='O'){
            board[i][j]='#';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
        }
    }
    void solve(vector<vector<char>>& board) {
         n = board.size();
         m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i==0 || j==0 || i==n-1||j==m-1) && board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='#')board[i][j]='O';
            }
        }
    }
};