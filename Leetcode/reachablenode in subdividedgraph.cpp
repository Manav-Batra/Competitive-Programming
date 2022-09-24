class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int,int>> g[n];
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            g[u].push_back({v,w+1});
            g[v].push_back({u,w+1});
        }
        
        set<pair<int,int>> s;
      int dist[n];
        for(int i=0;i<n;i++)
            dist[i]=INT_MAX;
        dist[0]=0;
        s.insert({0,0});
        while(!s.empty())
        {
            auto it =s.begin();
            int node=it->second;
            int d=it->first;
            s.erase(it);
            for(auto nbr : g[node])
            {
                int x=nbr.first;
                int wt=nbr.second;
                if(d+wt<dist[x])
                {
                    auto f=s.find({dist[x],x});
                    if(f!=s.end())
                        s.erase(f);
                    dist[x]=d+wt;
                    s.insert({dist[x],x});
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
         {   if(dist[i]<=maxMoves)
            {
                ans++;
            }}
        
        for(auto it : edges)
        {
            int wx=maxMoves-dist[it[0]];
            int wy=maxMoves-dist[it[1]];
            int w=it[2];
            if(wx>=0 and wy>=0)
            {
                ans+=(wx+wy)-max(wx+wy-w,0);
                
            }
            else
            {
                ans+=max(wx,0)+max(wy,0);
            }
        }
        return ans;
        
    }
};