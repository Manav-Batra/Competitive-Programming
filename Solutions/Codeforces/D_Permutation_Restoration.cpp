#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef  long long int ll;
#include<bits/stdc++.h>
using namespace std;
bool bs(vector<int> v,int n)
{
int low=0,high=v.size()-1;
while(low<=high)
{
int mid=(low+high)/2;
if(v[mid]==n)
return true;
else if(v[mid]>n)
high=mid-1;
else
low=mid+1;
}
return false;
}
const int N=1e5;
vector<int> g[N];
bool vis[N];
int level[N];
void bfs(int source)
{
queue<int> q;
 q.push(source);
 vis[source]=true;
 while(!q.empty())
{
int curr_vertex=q.front();
q.pop();
 cout<<curr_vertex;
for(auto child : g[curr_vertex])
{
 if(!vis[child])
{
 q.push(child);
  vis[child]=true;
level[child]=level[curr_vertex]+1;
}
}
}
cout<<endl;
}
void dfs(int vertex)
{
cout<<vertex;
vis[vertex]=true;
for(auto child : g[vertex])
{
if(vis[child])
continue;
dfs(child);
}
}
int main()
{
 int t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    vector<ll> b(n+1),ans(n+1);
    for(ll i=1;i<=n;i++)
    cin>>b[i];
    vector<vector<pair<ll,ll>>> segment(n+1);
    for(ll i=1;i<=n;i++)
    {
        ll minm=i/(b[i]+1)+1;
        ll maxm=n;
        if(b[i])
        {
            maxm=i/b[i];
        }
        segment[minm].push_back({maxm,i});

    }
    set<pair<ll,ll>> rsg;
    for(ll i=1;i<=n;i++)
    {
        for(auto it : segment[i])
        rsg.insert(it);
        ans[rsg.begin()->second]=i;
        rsg.erase(rsg.begin());
    }
    for(ll i=1;i<=n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
}