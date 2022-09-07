class Solution {
public:
    int find(int i,int parent[])
    {
        if(parent[i]==-1)
            return i;
      return  parent[i]=find(parent[i],parent);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int m=n+1;
        m=m*m;
        int parent[m],rank[m];
        for(int i=0;i<m;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        
        for(int i=n+1;i<m;i=i+n+1)
        {
            // cout<<i<<" ";
            parent[i]=0;
            parent[i-1]=0;
        }
        for(int i=0;i<n+1;i++)
        {
            if(i==0)
                continue;
            parent[i]=0;
        }
        
        int i=m-1;
        int temp=n+1;
        while(temp--)
        {
            parent[i]=0;
            i--;
        }
        int ans=1;
        m=n+1;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j]=='/')
               {
                   int x=(i+1)*m+j;
                   int y=(i*m)+(j+1);
                   int s1=find(x,parent);
                   int s2=find(y,parent);
                   
                   if(s1==s2)
                       ans++;
                   else
                   {
                       if(rank[s1]<rank[s2])
                       {
                           parent[s1]=s2;
                           rank[s2]+=rank[s1];
                       }
                       else
                       {
                           parent[s2]=s1;
                           rank[s1]+=rank[s2];
                       }
                   }
               }
               else if(grid[i][j]=='\\')
               {
                   int x=(i*m)+j;
                   int y=(i+1)*m+(j+1);
                                      int s1=find(x,parent);
                   int s2=find(y,parent);
                   
                   if(s1==s2)
                       ans++;
                   else
                   {
                       if(rank[s1]<rank[s2])
                       {
                           parent[s1]=s2;
                           rank[s2]+=rank[s1];
                       }
                       else
                       {
                           parent[s2]=s1;
                           rank[s1]+=rank[s2];
                       }
                   }
               }
           }
       }
        return ans;
    }
};