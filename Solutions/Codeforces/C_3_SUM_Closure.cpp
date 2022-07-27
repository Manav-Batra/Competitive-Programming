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
void solve()
{
    ll n;
    cin>>n;
    vector<ll> pos,neg,a;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(x>0)
        {
            pos.push_back(x);
        }
        else if(x<0)
        neg.push_back(x);
        else
        {
            if(a.size()<2)
            {
                a.push_back(x);
            }
        }
        
    }
    if(pos.size()>2||neg.size()>2)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(auto it : pos)
    a.push_back(it);
    for(auto it : neg)
    {
        a.push_back(it);
    }
   
    for(ll i=0;i<a.size();i++)
    {
        for(ll j=i+1;j<a.size();j++)
        {
            for(ll k=j+1;k<a.size();k++)
            {
                bool ok=false;
                for(ll l=0;l<a.size();l++)
                {
                    if((a[i]+a[j]+a[k])==a[l])
                    {
                        ok=true;
                    }
                    
                }
                if(ok==false)
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
            }
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}