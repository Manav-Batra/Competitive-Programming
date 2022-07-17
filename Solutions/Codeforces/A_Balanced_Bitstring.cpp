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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<k;i++)
    {
        if(s[i]=='?')
        {
            for(int j=i+k;j<n;j=j+k)
            {
                if(s[j]!='?')
                {
                    s[i]=s[j];
                    break;
                }
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        if(s[i]!='?')
        {
            for(int j=i+k;j<n;j=j+k)
            {
                if(s[j]=='?')
                {
                    s[j]=s[i];
                }
                if(s[j]!=s[i])
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    int one=0,zero=0;
    for(int i=0;i<k;i++)
    {
        if(s[i]=='1')
        one++;
        if(s[i]=='0')
        zero++;
    }
    if(one<=(k/2)&&zero<=(k/2))
    cout<<"YES"<<endl;
    else
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