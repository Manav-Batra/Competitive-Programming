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
    int t;
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> a(m);
        for(ll i=0;i<m;i++)
        cin>>a[i];
        map<ll,ll> mp;
        for(ll i=1;i<=n;i++)
        mp[i]=0;
        for(auto it : a)
        mp[it]++;
        ll ans=0,low=1,high=2*m;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            bool check=false;
            ll left=0,help=0;
            for(ll i=1;i<=n;i++)
            {
                if(mid>mp[i])
                {
                    help+=(mid-mp[i])/2;
                }
                else
                {
                    left+=mp[i]-mid;
                }
            }
            if(help>=left)
            check=true;
            if(check)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<ans<<endl;

    }
}