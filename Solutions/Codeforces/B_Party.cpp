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
        vector<ll> cost(n),freq(n+1,0);
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++)
        cin>>cost[i];
        ll temp=m;
        while(temp--)
        {
            pair<ll,ll> p;
            ll x,y;
            cin>>x>>y;
            p.first=x;
            p.second=y;
            freq[x]++;
            freq[y]++;
            v.push_back(p);
        }
         ll ans=INT_MAX;
         if(m&1)
         {
            for(ll i=1;i<=n;i++)
            {
                if(freq[i]&1)
                {
                    ans=min(ans,cost[i-1]);
                }
            }
 for(auto it : v)
        {
            if((freq[it.first]%2==0)&&(freq[it.second]%2)==0)
            {
                ans=min(ans,(cost[it.first-1]+cost[it.second-1]));
            }
        }
        cout<<ans<<endl;
         }
         else
         {
            cout<<0<<endl;
         }
       

    }
}