class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,-1));
        int fresh = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }    
        int time = 0;
        int dx[] = {-1, 1, 0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int sz = q.size();
            bool change = false;
            for(int j = 0; j<sz; j++){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();
                for(int k = 0; k<4;k++){
                    int nrow = row+dx[k];
                    int ncol = col + dy[k];
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == -1){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                        fresh--;
                        change = true;
                    }

                }
            }
            if(change){
                time++;
            }
        }
        return fresh == 0?time:-1;
    }
};