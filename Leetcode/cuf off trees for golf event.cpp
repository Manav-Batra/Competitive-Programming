class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int bfs(vector<vector<int>> &forest,int sr,int sc,int er,int ec)
    {
        if(sc==ec and sr==er)
            return 0;
        int step=0;
        queue<pair<int,int>> q;
        int m=forest.size();
        int n=forest[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        q.push({sr,sc});
        vis[sr][sc]=true;
        while(!q.empty())
        {
           step++;
            int sz=q.size();
        
            for(int i=0;i<sz;i++)
            {
                auto [x,y]=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int r=x+dx[j];
                    int c=y+dy[j];
                    if(r<0 or c<0 or r>=m or c>=n or (forest[r][c]==0) or (vis[r][c]==true))
                        continue;
                    if(r==er and c==ec)
                        return step;
                    q.push({r,c});
                    vis[r][c]=true;
                    
                }
                
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size();
        int n=forest[0].size();
        vector<vector<int>> tree;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(forest[i][j]>1)
                    tree.push_back({forest[i][j],i,j});
            }
        }
        int ans=0;
        sort(tree.begin(),tree.end());
            int start_row=0;
        int start_col=0;
            for(int i=0;i<tree.size();i++)
            {
               int step=bfs(forest,start_row,start_col,tree[i][1],tree[i][2]);
                if(step==-1)
                    return -1;
                ans+=step;
                start_row=tree[i][1];
                start_col=tree[i][2];
                
            }
        return ans;
    }
};