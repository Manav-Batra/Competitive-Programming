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
     unordered_map<ll,ll> mp=
            {
                {1,1},{2,0},{3,9},{4,18},{6,6},{7,25},{8,14},{9,23}
            };
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        ll count=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%10==0||a[i]%10==5)
            {
                count++;
            }
        }
        if(count==n)
        {
            // vector<ll> b(n);
            for(ll i=0;i<n;i++)
            {
                if(a[i]%10==5)
                {
                 a[i]=a[i]+5;
                }
            }
            bool ok=true;
            for(ll i=0;i<n-1;i++)
            {
                if(a[i]!=a[i+1])
                {
                       ok=false;
                       break;
                }
            }
            if(ok)
            {
                cout<<"Yes"<<endl;

            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else if(count==0)
        {
           bool ok=true;
           for(ll i=0;i<n;i++)
           {
              a[i]=(a[i]+mp[a[i]%10])%20;
           }
           for(ll i=0;i<n-1;i++)
           {
            if(a[i]!=a[i+1])
            {
               ok=false;
               break;
            }
           }
           if(ok)
           {
            cout<<"Yes"<<endl;
           }
           else
           cout<<"No"<<endl;
        }
        else
        cout<<"No"<<endl;
    }
}