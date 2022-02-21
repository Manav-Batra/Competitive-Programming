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
int level[N] ;
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty())
    {
        int curr_vertex = q.front();
        q.pop();
        cout << curr_vertex ;
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
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
        }
        ll count=0;
        for(ll i=1;i<n-2;i++)
        {
            if(v[i]>v[i-1]&&v[i]>v[i+1])
            {
                count++;
                ll temp1=v[i];
                ll temp2=v[i+2];
                v[i+1]=max(temp1,temp2);
                
            }
        }
        ll i=n-3,j=n-2,k=n-1;
        if(v[j]>v[i]&&v[j]>v[k])
        {
            v[j]=max(v[i],v[k]);
            count++;
        }
        cout<<count<<endl;
        for(auto it : v)
        cout<<it<<" ";
        cout<<endl;
    }
}