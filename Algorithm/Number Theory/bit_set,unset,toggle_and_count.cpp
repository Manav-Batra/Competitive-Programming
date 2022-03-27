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
void printbinary(int num)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main()
{
    printbinary(9);
    int a=9;
    int i=3;
    // check if ith bit is set or not
    if(a&(1<<i)!=0)
    {
        cout<<"bit is set"<<endl;
    }
    else
    {
        cout<<"bit is not set"<<endl;
    }
    // bit set
    printbinary(a|(1<<i));
    // bit unset
    printbinary(a&(~(1<<i)));
    // bit toggle
    printbinary(a^(1<<i));
    // count set bit
    int count=0;
    for(int i=31;i>=0;i--)
    {
        if((a&(1<<i))!=0)
        count++;
    }
    cout<<count<<endl;
    cout<<(__builtin_popcount(a))<<endl;

}