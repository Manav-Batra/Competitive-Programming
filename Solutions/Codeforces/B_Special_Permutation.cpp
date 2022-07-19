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
        ll n,a,b;
        cin>>n>>a>>b;
        vector<ll> ans;
        ans.push_back(a);
        for(ll i=n;i>0;i--)
        {
           
           if(i==a||i==b)
           continue;
           ans.push_back(i);
        }
        ans.push_back(b);
        ll mx1=INT_MAX,mx2=0;
        ll m=ans.size();
        for(ll i=0;i<m/2;i++)
        {
            mx1=min(mx1,ans[i]);

        }
        for(ll i=m/2;i<m;i++)
        {
            mx2=max(mx2,ans[i]);

        }
        if(mx1==a&&mx2==b)
        {
            for(auto it : ans)
            cout<<it<<" ";
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }

    }
}