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
    ll h1=n/3;
    ll h2=n/3;
    ll h3=n/3;
    if(n%3==0)
    {
        h3=h3-1;
        h1=h1+1;
    }
    if(n%3==1)
    {
        h3=h3-1;
        h1=h1+2;

    }
    if(n%3==2)
    {
      h1=h1+2;
      h2=h2+1;
      h3=h3-1;
    }
    cout<<h2<<" "<<h1<<" "<<h3<<endl;
}
}