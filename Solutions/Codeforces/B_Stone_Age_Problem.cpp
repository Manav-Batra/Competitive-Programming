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
   ll n,q;
   cin>>n>>q;
   vector<ll> a(n);
   map<ll,ll> mp;
   ll sum=0;
   for(ll i=0;i<n;i++)
   {
    cin>>a[i];
    sum+=a[i];
    mp[i]=a[i];
   }
   ll temp=0;
   while(q--)
   {
    ll t;
    cin>>t;
    if(t==1)
    {
        ll i,x;
        cin>>i>>x;
        i--;
        if(!mp.count(i))
        {
            mp[i]=temp;
        }
        sum-=mp[i];
        mp[i]=x;
        sum+=mp[i];
    }
    else
    {
        ll x;
        cin>>x;
        temp=x;
        sum=n*x;
        mp.clear();
    }
    cout<<sum<<endl;
   }
}
