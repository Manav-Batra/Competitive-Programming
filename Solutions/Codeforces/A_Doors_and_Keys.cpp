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
        string s;
        cin>>s;
        int count_red=0,count_blue=0,count_green=0;
        vector<pair<char,int>> v={
            {'r',1},{'g',1},{'b',1},{'R',-1},{'G',-1},{'B',-1}
        };
        bool ok=true;
        for(int i=0;i<6;i++)
        {
            if(count_blue==-1||count_green==-1||count_red==-1)
            {
                // cout<<"NO"<<endl;
                ok=false;
                break;
            }
            if(s[i]=='r')
            count_red++;
            if(s[i]=='g')
            count_green++;
            if(s[i]=='b')
            count_blue++;
            if(s[i]=='G')
            count_green--;
            if(s[i]=='B')
            count_blue--;
            if(s[i]=='R')
            count_red--;

        }
        if(ok)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
}