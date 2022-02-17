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
        ll n,x,y;
        cin>>n>>x>>y;
        ll ans;
        ll sab100se,sab4s3,mix,mix2;
        ll l=n/100;
        ll o=n/4;
        if(n%100!=0)
        {
            l=l+1;
        }
        if(n%4!=0)
        o++;
        sab100se=l*x;
        sab4s3=o*y;
        ans=min(sab100se,sab4s3);
        ll m=n;
        mix2=(m/4)*y;
        m=m%4;
mix2=mix2+(m/100)*x;
if(m%100!=0)
mix2=mix2+x;
        mix=(n/100)*x;
        n=n%100;
        mix=mix+(n/4)*y;
        if(n%4!=0)
        {
            mix=mix+y;
        }
        ll temp=min(mix,mix2);
        ans=min(ans,temp);
        cout<<ans<<endl;
        
        
    }
}