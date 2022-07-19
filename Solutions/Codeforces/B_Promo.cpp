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
int level[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty())
    {
        int curr_vertex = q.front();
        q.pop();
        cout << curr_vertex;
        for (auto child : g[curr_vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[curr_vertex] + 1;
            }
        }
    }
    cout << endl;
}
void dfs(int vertex)
{
    cout << vertex;
    vis[vertex] = true;
    for (auto child : g[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {     
           ll n,q;
        cin>>n>>q;
        vector<ll> v(n);
        for(ll i=0;i<n;i++)
        cin>>v[i];
        sort(v.begin(),v.end());
        vector<ll> prefix_sum(n+1);
        for(ll i=n-1;i>=0;i--)
        {
            prefix_sum[i]=prefix_sum[i+1]+v[i];
        }
        reverse(prefix_sum.begin(),prefix_sum.end());
        // for(auto it : prefix_sum)
        // cout<<it<<" ";
        // cout<<endl;
        while(q--)
        {
            ll x,y;
            cin>>x>>y;
            ll ans=prefix_sum[x]-prefix_sum[x-y];
            cout<<ans<<endl;
        }
    // }
}