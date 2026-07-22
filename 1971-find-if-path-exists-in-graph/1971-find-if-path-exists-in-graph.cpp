class Solution {
public:
    bool dfs(int start, vector<int>& vis, vector<vector<int>>& adj, int destination){
        vis[start] = 1;
        if(start == destination)
            return true;
        for(auto it : adj[start]){
            if(!vis[it])
                if(dfs(it, vis, adj, destination))
                    return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(source, vis, adj, destination);
    }
};