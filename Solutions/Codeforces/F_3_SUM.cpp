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
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        cin>>a[i];
        int count1[10]={};
        // unordered_map<int,int> mp;
        for(ll i=0;i<n;i++)
        {
            a[i]=a[i]%10;
            count1[a[i]]++;
        }
        vector<int> v;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<min(count1[i],3);j++)
            v.push_back(i);
        }

        
        
        int m=v.size();
        bool ok=false;
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                for(int k=j+1;k<m;k++)
                {
                    if(((v[i]+v[j]+v[k])%10)==3)
                    {
                        cout<<"YES"<<endl;
                        return;
                    }
                }
             
            }
          
        }
        cout<<"NO"<<endl;
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