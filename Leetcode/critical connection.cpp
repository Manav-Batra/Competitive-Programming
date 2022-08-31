class Solution {
public:
    const static int N=1e5+1;
    vector<int> g[N];
    int vis[N];
    int par[N];
    int dis[N];
    int low[N];
    int time;
    vector<vector<int>> ans;
    void dfs(int u,int parr)
    {
        par[u]=parr;
        dis[u]=low[u]=time;
        vis[u]=1;
        time++;
        int count=0;
        for(auto v : g[u])
        {
            if(par[u]==v)
                continue;
            else if(vis[v])
            {
                low[u]=min(low[u],dis[v]);
            }
            else
            {
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>dis[u])
                {
                    ans.push_back({u,v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        for(int i=0;i<m;i++)
        {
            int x=connections[i][0];
            int y=connections[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        time=0;
        dfs(0,-1);
        return ans;
    }
};