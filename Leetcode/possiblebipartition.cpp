class Solution {
public:
    const static int N=2001;
    vector<int> g[N];
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto it : dislikes)
        {
            int x=it[0];
            int y=it[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        vector<int> color(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]!=-1)
                continue;
            
            queue<int> q;
            q.push(i);
            color[i]=1;
            
            while(!q.empty())
            {
                int f=q.front();
                q.pop();
                int c=1-color[f];
                for(auto x : g[f])
                {
                    if(color[f]==color[x])
                        return false;
                    else if(color[x]==-1)
                    {
                        color[x]=c;
                    }
                    else 
                    {
                        continue;
                    }
                    q.push(x);
                }
            }
        }
        return true;
    }
};