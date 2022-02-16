#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;
bool bs(vector<int> v, int n)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == n)
            return true;
        else if (v[mid] > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
const int N = 1e5;
vector<int> g[N];
// bool vis[N];
int p[N];
void dfs(int vertex,int par=-1)
{
    // cout << vertex;
    // vis[vertex] = true;
    p[vertex]=par;
    for (auto child : g[vertex])
    {
        
        if (child==par)
            continue;
        dfs(child,vertex);
    }
}
vector<int> path(int vertex)
{
    vector<int> ans;
    while(vertex!=-1)
    {
        ans.push_back(vertex);
        vertex=p[vertex];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int x,y;
    cin>>x>>y;
    vector<int> path_x=path(x);
      vector<int> path_y=path(y);
      int min_ln=min(path_x.size(),path_y.size());
      int lca=-1;
      for(int i=0;i<min_ln;i++)
      {
          if(path_x[i]==path_y[i])
          lca=path_x[i];
          else
          break;
      }
cout<<lca<<endl;
}