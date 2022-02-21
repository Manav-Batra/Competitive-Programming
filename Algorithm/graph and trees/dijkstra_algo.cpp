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
vector<pair<int,int>>  g[N];
bool vis[N];
int level[N];
/*
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
*/
/*
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
*/
const int  INF=1e9+10;
vector<int> dijkstra(int source)
{
    vector<int> dist(N,INF);
    set<pair<int,int>> st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0)
    {
        auto node=*st.begin();
        int v=node.second;
        int d=node.first;
        st.erase(st.begin());
        if(vis[v])
        continue;
        vis[v]=true;
        for(auto child : g[v])
        {
            int child_v=child.first;
            int wt=child.second;
            if(dist[v]+wt<dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});

            }
        }
    }
    return dist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});

    }
   vector<int> ans= dijkstra(2);
   for(int i=1;i<=n;i++)
   cout<<ans[i]<<endl;

}