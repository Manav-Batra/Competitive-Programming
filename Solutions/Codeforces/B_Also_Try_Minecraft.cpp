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
   ll n,m;
   cin>>n>>m;
   vector<ll> a(n),b(n),c(n);
   for(ll i=0;i<n;i++)
   {
    cin>>a[i];
   }
   b[0]=0;
   for(ll i=1;i<n;i++)
   {
     if(a[i-1]>a[i])
     {
        b[i]=b[i-1]+(a[i-1]-a[i]);
    
     }
     else
     b[i]=b[i-1];
     
   }
   reverse(a.begin(),a.end());
   c[0]=0;
   for(ll i=1;i<n;i++)
   {
     if(a[i-1]>a[i])
     {
        c[i]=c[i-1]+(a[i-1]-a[i]);
    
     }
     else
     c[i]=c[i-1];
     
   }
   
//    for(ll i=0;i<n;i++)
//  {
//     cout<<a[i]<<" ";
//  }
//  cout<<endl;
   
//  for(ll i=0;i<n;i++)
//  {
//     cout<<b[i]<<" ";
//  }
//  cout<<endl;
  
 reverse(c.begin(),c.end());
// for(ll i=0;i<n;i++)
//  {
//     cout<<c[i]<<" ";
//  }
//  cout<<endl;
 while(m--)
 {
    ll x,y;
    cin>>x>>y;
    if(x<=y)
    {
        cout<<b[y-1]-b[x-1]<<endl;

    }
    else
    {
        cout<<abs(c[x-1]-c[y-1])<<endl;
    }
 }



}