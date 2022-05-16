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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n];
        set<ll> s;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
        }
        
        vector<ll> v;
        for(auto it : s)
        v.push_back(it);
        if(v.size()==1)
        {
            cout<<2*v[0]<<endl;
            continue;
        }
        ll a1=v[v.size()-1];
        ll b=v[v.size()-2];
        ll ans=a1+b;
        ll check1=((a1-b)%m);
        ll check2=b-a1;
        ll temp=m-abs(check2);
        if(check1>=temp)
        ans=ans+check1;
        else
        ans=ans+temp;
        // cout<<a1<<" " <<b<<" "<<check1<<" "<<check2<<" "<<temp<<endl;
        // cout<<ans<<endl;
        ans=max(ans,2*a1);
        cout<<ans<<endl;


        
    }
}