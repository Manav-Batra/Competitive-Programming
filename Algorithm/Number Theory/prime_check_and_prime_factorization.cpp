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
    int n;
    cin>>n;
    bool isprime=true;
    if(n==1)
    {
        cout<<0<<endl;
        // continue;
        // return;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            isprime=false;
            break;
        }
    }
    cout<<isprime<<endl;
    // O(N)

    isprime=true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            isprime=false;
            break;
        }
    }
    cout<<isprime<<endl;
    vector<int> is_prime;
    int m=n;
    for(int i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            is_prime.push_back(i);
            n=n/i;
        }
    }
    for(auto it : is_prime)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    // O(N)

n=m;
    is_prime.clear();
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
         is_prime.push_back(i);
         n=n/i;
        }
    }
    if(n>1)
    {
        is_prime.push_back(n);
    }
    for(auto it : is_prime)
    {
        cout<<it<<" ";

    }
    cout<<endl;
}