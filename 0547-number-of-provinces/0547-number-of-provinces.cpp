class Solution {
public:
    void dfs(int start, vector<int>&vis, vector<vector<int>>& adj){
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it])
                dfs(it, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int c = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                c++;
                dfs(i, vis, adj);
            }
        }
        return c;
    }
};