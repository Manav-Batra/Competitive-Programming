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
    //BBWBW
    //12233 
    //  
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        // ll cnt=0;
        vector<ll> pref(n+1);

        for(ll i=1;i<=n;i++)
        { pref[i]=pref[i-1];
            if(s[i-1]=='B')
            pref[i]++;
            // pref[i]=cnt;
        }
        //BBWBW 
        //12233  3-(3-2)=3-1=2
        //1
        // for(ll i=0;i<n;i++)
        // cout<<pref[i]<<" ";
        // cout<<endl;
        ll temp=k;
        //BBWBW
        //12233
        //5 3   
        for(ll i=k;i<=n;i++)
        { 
          temp=min(temp,k-(pref[i]-pref[i-k]));
        }
        cout<<temp<<endl;


    }
}