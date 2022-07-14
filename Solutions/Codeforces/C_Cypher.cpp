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
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        cin>>a[i];
       
        ll temp=n;
        vector<int> ans;
        while(temp--)
        {
            ll b;
            string s;
            cin>>b>>s;
             unordered_map<int,int> mp;
             for(int i=0;i<b;i++)
             {
                mp[s[i]]++;
             }
             ll count=0;
             ll c=mp['U'];
             c=c*-1;
             count=c+mp['D'];
             ans.push_back(count);
        }
        // for(auto it : ans)
        // cout<<it<<" ";
        // cout<<endl;
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            ll d=a[i]+ans[i];
            if(d>=10)
            {
                d=d%10;
            }
            else if(d<0)
            {
                if(d==-10)
                d=0;
                else
                {
                    d=(d+10)%10;
                }
            }
            res[i]=d;

        }
        for(auto it : res)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    
    }
}