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
        ll n, m;
        cin >> n >> m;
        int a[n][m];
       for(int i=0;i<n;i++)
       {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            a[i][j]=s[j]-'0';
        }
       }
        if (a[0][0] == 1)
        {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        vector<vector<int>> res;
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp;
            for (int j = m - 1; j >= 0; j--)
            {
                if (a[i][j] == 1)
                {
                    ans++;
                    if (i != 0)
                    {
                        if (j != 0)
                        {
                            // if(b[i][j-1]==0)

                            temp.push_back(i);
                            temp.push_back(j - 1);
                            temp.push_back(i);
                            temp.push_back(j);
                            // res.push_back(temp);

                            res.push_back(temp);
                        }
                        else
                        {
                            //    if(a[i-1][j]==0)
                            // {
                            temp.push_back(i - 1);
                            temp.push_back(j);
                            temp.push_back(i);
                            temp.push_back(j);
                            // }
                            res.push_back(temp);
                        }
                    }
                    else
                    {
                        //  if(a[i][j-1]==0)
                        // {
                        temp.push_back(i);
                        temp.push_back(j - 1);
                        temp.push_back(i);
                        temp.push_back(j);
                        // res.push_back(temp);
                        // }
                        res.push_back(temp);
                    }

                    temp.clear();
                }
            }
        }
        cout << ans << endl;
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j]+1 << " ";
            }
            cout << endl;
        }
    }
}
