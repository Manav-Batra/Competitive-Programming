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
        cin >> n;
        vector<string> a(n);
        multiset<string> st;
        ll temp = n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            a[i] = s;
            st.insert(s);
        }
    
        for (int i = 0; i < n; i++)
        {
            ll l = a[i].length();
            if (l == 1)
                cout << 0;
            else
            {
                ll j=0;
                bool ok=false;
                string part1;
                while(j<l-1)
                {
                    part1.push_back(a[i][j]);
                    if(st.find(part1)!=st.end())
                    {
                       ll k=j+1;
                       string part2;
                       while(k<l)
                       {
                          part2.push_back(a[i][k]);
                          k++;
                       }
                       if(st.find(part2)!=st.end())
                       {
                        cout<<1;
                        ok=true;
                       }
                    }
                    if(ok==true)
                    {
                        break;
                    }
                    j++;
                }
                if(ok==false)
                cout<<0;
            }
           
        }
         cout<<endl;
    }
}
