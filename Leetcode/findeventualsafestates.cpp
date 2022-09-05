class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &currentPath, vector<bool> &safe) {
    
    vis[node] = currentPath[node] = true;
    
    for(int u: adj[node]) {
        if(!vis[u]) {
            if(dfs(u, adj, vis, currentPath, safe)) {
                safe[node] = false;
                return true;
            }
        }
        else if(currentPath[u]) {
            safe[node] = false;
            return true;
        }
    }
    
    return currentPath[node] = false;
}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    int V = size(graph);
    
    vector<int> adj[V];
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < graph[i].size(); ++j)
            adj[i].push_back(graph[i][j]);
    }
    
    vector<bool> vis(V, false);
    vector<bool> currentPath(V, false);
    vector<bool> safe(V, true);
    
    for(int i = 0; i < V; i++) {
        if(!vis[i])
            dfs(i, adj, vis, currentPath, safe);
    }
    
    vector<int> ans;
    for(int i = 0; i < V; i++) {
        if(safe[i])
            ans.push_back(i);
    }
    
    return ans;
}
};