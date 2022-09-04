class Solution {
public:
//     Here created a map to convert the string node to interger like
//     "a"->1
//     "b"->2
    unordered_map<string,int> mp;
    const static int N=100;

    vector<double> ans; // vector to store ans;
    
    double dist[N][N]; // compute matrix
    
//     flord_warshall algortihm
    void flord_warshall(int n)
    {
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][j]>(dist[i][k]*dist[k][j]) and dist[i][k]!=1000.0 and dist[k][j]!=1000.0)
                        dist[i][j]=dist[i][k]*dist[k][j];
                }
            }

        }
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int count=0;
        
//         convert string to interger node
        for(int i=0;i<equations.size();i++)
        {
            
            string x=equations[i][0];
            string y=equations[i][1];
            if(mp.find(x)==mp.end())
            {
                mp.insert({x,count});
                count++;
            }
            if(mp.find(y)==mp.end())
            {
                mp.insert({y,count});
                count++;
            }
            
        }
        int n=mp.size();
//         create the edge list as required for flordwarshall algorithm
      vector<vector<int>> edges;
        for(int i=0;i<equations.size();i++)
        {
                        string x=equations[i][0];
            string y=equations[i][1];
            int xx=mp[x];
            int yy=mp[y];
    
        
            vector<int> v;
            v.push_back(xx);
            v.push_back(yy);
            edges.push_back(v);
        }
        
//         initalize the distance array as maximum value
                 for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                dist[i][j]=1000.0;
            
        }
        
        
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            double w=values[i];
            double rev=(double)1/w;
            dist[x][y]=w;
            dist[y][x]=rev;
        
        }
       
        flord_warshall(n);
        
//         compute queries
        for(int i=0;i<queries.size();i++)
        { 
            if((mp.find(queries[i][0])==mp.end()) or( mp.find(queries[i][1])==mp.end()))
        {
            ans.push_back(-1.0);
            continue;
        }
            int x=mp[queries[i][0]];
            int y=mp[queries[i][1]];
            if(dist[x][y]==1000.0)
            {
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(dist[x][y]);
        }
        return ans;
    }
};