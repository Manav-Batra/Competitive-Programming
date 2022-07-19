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
        cin >>n;
        string s;
        cin>>s;
        string ans;
        if(s[0]=='9')
        {
            // string str(n+1,'1');
            // string ans;
            ll c=0;
            for(ll i=n-1;i>=0;i--)
            {
               ll x=s[i]-'0';
               x+=c;
               if(x>1)
               {
                ans.push_back((11-x)+'0');
                c=1;
               }
               else
               {
                c=0;
                ans.push_back((1-x)+'0');
               }
            }
            reverse(ans.begin(),ans.end());

        }
        else
        {
            // string str(n,'9');
            // string ans;
            for(ll i=0;i<n;i++)
            {
                ans.push_back((9-(s[i]-'0'))+'0');
            }
        }
        cout<<ans<<endl;
    }
}