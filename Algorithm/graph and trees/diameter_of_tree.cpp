#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;
int bs(vector<int> v, int n)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == n)
            return mid;
        else if (v[mid] > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
const int N = 1e5;
vector<int> g[N];
int depth[N];
// bool vis[N];
void dfs(int vertex,int par=0)
{
    // cout << vertex;
    // vis[vertex] = true;
    for (auto child : g[vertex])
    {
        if (child==par)
            continue;
            depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int max_depth=-1;
    int max_node;
    for(int i=1;i<=n;i++)
    {
        if(max_depth<depth[i])
        {
        max_depth=depth[i];
max_node=i;
        }
        depth[i]=0;

    }
    dfs(max_node);
    max_depth=-1;
     for(int i=1;i<=n;i++)
    {
        if(max_depth<depth[i])
        {
        max_depth=depth[i];
// max_node=i;
        }
        // depth[i]=0;

    }
    cout<<max_depth<<endl;
     

}