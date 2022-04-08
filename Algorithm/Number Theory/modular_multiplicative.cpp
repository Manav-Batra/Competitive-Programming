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
int binexp(int a,int b,int M)
{
    int res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*1LL*a)%M;

        }
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return res;
}
// THERE ARE N CHILDREN AND K TOFFES COUNT THE NUMBER OF WAYS TO DISTRUBUTE TOFFES.
int fact[N];
const int M=1e9+7;
int main()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%M;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        int ans=fact[n];
        int den=(fact[n-k]*1LL*fact[k])%M;
        ans=ans*binexp(den,M-2,M);
        cout<<ans%M;
    }
}