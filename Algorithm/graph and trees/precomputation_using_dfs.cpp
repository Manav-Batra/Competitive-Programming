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
int subtree_sum[N];
int even_ct[N];
// bool vis[N];
void dfs(int vertex, int par = 0)
{
    // cout<<vertex;
    // vis[vertex]=true;
    if (vertex % 2 == 0)
        even_ct[vertex]++;
    subtree_sum[vertex] += vertex;
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << subtree_sum[i] << " " << even_ct[i] << endl;
    }
}