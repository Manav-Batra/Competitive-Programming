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
        ll n;
        cin>>n;
        ll a[n];
        ll count=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            count++;
        }
        if(count==0||count>1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        ll x;
        for(ll i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                x=i;
                break;
            }
        }
        vector<ll> v(a+x,a+n);
        v.insert(v.end(),a,a+x);
        bool ok=true;
        for(ll i=1;i<n;i++)
        {
            if(v[i]>v[i-1]&&((v[i]-v[i-1])>1))
            {
                ok=false;
                break;
            }
        }
        if(ok)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}