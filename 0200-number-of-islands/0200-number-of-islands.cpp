class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        vector<vector<int>> vis(n, vector<int>(m,-1));
        int islands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    islands++;
                    vis[i][j] = 1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for(int k = 0; k<4; k++){
                            int nrow = row + dx[k];
                            int ncol = col + dy[k];
                            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == -1){
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                            } 
                        }
                    }
                }
            }
        }
        return islands;
    }
};