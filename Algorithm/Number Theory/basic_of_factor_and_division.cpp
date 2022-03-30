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
    // BRUTE APPROACH
    int n;
    cin>>n;
    int count=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
            count++;
            sum=sum+i;
        }

    }
    cout<<count<<" "<<sum<<endl;
    // O(N)
    // SQRT METHOD
    int m;
    cin>>m;
    int sum1=0,count1=0;
    for(int i=1;i*i<=m;i++)
    {
        if(m%i==0)
        {
            cout<<i<<" "<<m/i<<endl;
            count1++;
            sum1=sum+i;
            if(m/i!=i)
            {
                count1++;
                sum=sum+(m/i);
            }
        }
    }
        cout<<sum1<<" "<<count1<<endl;  
        // O(SQRT(N))
}