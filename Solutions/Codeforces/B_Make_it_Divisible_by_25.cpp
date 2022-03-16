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
        ll temp=n;
        ll ld;
        ll ans=0,res=0;
        while(temp>0)
        {
            ld=temp%10;
            if(ld==5)
            {
                temp=temp/10;
                break;
            }
            temp=temp/10;
            ans++;
        }
        while(temp>0)
        {
            ld=temp%10;
            if(ld==2||ld==7)
            {
                break;
            }
            temp=temp/10;
            ans++;
        }
        while(n>0)
        {
            ld=n%10;
            if(ld==0)
            {
                n=n/10;
                break;
            }
            n=n/10;
            res++;
        }
        while(n>0)
        {
           
            ld=n%10;
            if(ld==0||ld==5)
            {
                break;
            }
            n=n/10;
            res++;
        }
        res=min(res,ans);
        cout<<res<<endl;

    }
}