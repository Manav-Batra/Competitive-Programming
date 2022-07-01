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
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        map<ll,ll> mp;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            mp[v[i]]++;
        }
        // ll start=0,last=0;
        ll maxi=-1;
        for(auto it : mp)
        {
            maxi=max(maxi,it.second);
        }
        if(maxi<k)
        {
            cout<<-1<<endl;
            continue;
        }
       vector<ll > a;
       for(auto it : mp)
       {
        if(it.second>=k)
        a.push_back(it.first);
       }
       ll mx=0;
       ll lans=a[0],rans=a[0];
       ll l=a[0];
       for(ll i=1;i<a.size();i++)
       {
        if(a[i]-1==a[i-1])
        {
            if(a[i]-l>mx)
            {
                lans=l;
                rans=a[i];
                mx=a[i]-l;
            }
            
        }
        else
            l=a[i];

       }
       cout<<lans<<" "<<rans<<endl;

    
    }
}