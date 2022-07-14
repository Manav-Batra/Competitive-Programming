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
        vector<ll> a(n+1),bade,index;
        map<ll,ll> mp;
        set<ll> st;
        for(ll i=1;i<=n;i++)
        {
              cin>>a[i];
              if(i>a[i])
              {
                bade.push_back(a[i]);
                index.push_back(i);
                mp[a[i]]++;
                if(mp.find(i)==mp.end())
                  mp[i]=0;
              }
        }
        for(auto it : bade)
        {
            st.insert(it);
        }
        for(auto it : index)
        st.insert(it);
        map<ll,ll> ans;
        vector<ll> res;
        for(auto it : st)
        res.push_back(it);
        ll total=0;
        for(ll i=0;i<res.size();i++)
        {
            total=total+mp[res[i]];
            ans.insert({res[i],total});
        }
        
        ll m=bade.size();
       ll final=0;
    //    for(auto it : index)
       for(ll i=0;i<index.size();i++)
       {
        final+=(m-ans[index[i]]);
       }
       cout<<final<<endl;

    }
}