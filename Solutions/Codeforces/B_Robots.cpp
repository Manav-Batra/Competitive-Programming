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
        int n,m;
        cin>>n>>m;
        char a[n+1][m+1];
        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char x;
                cin>>x;
                a[i][j]=x;
                if(x=='R')
                {
                    pair<int,int> p;
                    p.first=i;
                    p.second=j;
                    v.push_back(p);
                }
            }
        }
        // for(auto it : v)
        // cout<<it.first<<" "<<it.second<<endl;
        int x=v[0].first-1;
        int y=v[0].second-1;
        // cout<<x<<" "<<y<<endl;
        for( int i=0;i<v.size();i++)
        {
            v[i].first=v[i].first-x;
            v[i].second=v[i].second-y;

        }
        bool ok=true;
        for(auto it : v)
        {
            if(it.second<=0||it.first<=0)
            {
                ok=false;
                break;
            }
        }
        // for(auto it : v)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        if(ok)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}