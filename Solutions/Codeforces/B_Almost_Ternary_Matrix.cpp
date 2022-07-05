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
        ll n,m;
        cin>>n>>m;
        vector<int> v;
        ll temp=m;
        ll start=4;
        ll i=2;
        // v.push_back(1);
        while(start<=temp)
        {
            v.push_back(start);
            start=4*i;
            i++;

        }
        start=1;
        while(start<=temp)
        {
            v.push_back(start);
            start=start+4;
        }
        sort(v.begin(),v.end());
        // for(auto it : v)
        // cout<<it<<" ";
        // cout<<endl;
        vector<int> b;
        for(int i=1;i<=m;i++)
        {
            if(bs(v,i)==true)
            continue;
            b.push_back(i);
        }
        sort(b.begin(),b.end());
        vector<int> check_v;
        vector<int> check_b;
        temp=n;
        start=3;
        check_v.push_back(0);
        check_v.push_back(3);
        check_v.push_back(4);
        while(start<=temp)
        {
            start=start+4;
            ll x=start+1;
            check_v.push_back(start);
            check_v.push_back(x);
        }
        sort(check_v.begin(),check_v.end());
check_b.push_back(1);
check_b.push_back(2);
        start=1;

         while(start<=temp)
        {
            start=start+4;
            ll x=start+1;
            check_b.push_back(start);
            check_b.push_back(x);
        }
        sort(check_b.begin(),check_b.end());
        // for(auto it : check_v)
        // cout<<it<<" ";
        // cout<<endl;


        int a[n][m]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ll x=j+1;
                if(bs(check_v,i)==true)
                {
                    if(bs(v,x)==true)
                    {
                        a[i][j]=1;

                    }
                    else
                    {
                        a[i][j]=0;
                    }
                }
                else
                {
                    if(bs(b,x)==true)
                    {
                        a[i][j]=1;
                    }
                    else
                    {
                        a[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}