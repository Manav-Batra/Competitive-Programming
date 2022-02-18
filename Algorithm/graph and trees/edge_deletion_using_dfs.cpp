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
bool vis[N];
int val[N];
int subtree_sum[N];
void dfs(int vertex,int par=-1)
{
    // cout << vertex;
    // vis[vertex] = true;
            subtree_sum[vertex]+=val[vertex];
    for (auto child : g[vertex])
    {
        if (child==par)
            continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>val[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        ll part1=subtree_sum[i];
        ll part2=subtree_sum[1]-part1;
        ans=max(ans,(part1*part2));
    }
    // for(int i=1;i<=n;i++)
    // cout<<val[i]<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<subtree_sum[i]<<endl;
    // }
    cout<<ans<<endl;
}