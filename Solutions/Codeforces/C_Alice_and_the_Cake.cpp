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
        vector<ll > a(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        // ll sum=accumulate(a.begin(),a.end(),0);
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            sum+=a[i];
        }
        priority_queue<ll> pq;
        pq.push(sum);
        map<ll,ll> mp;
        for(ll i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        while(pq.size()<n)
        {
            ll x=pq.top();
            pq.pop();
            // cout<<x<<" ";
            ll p=x/2;
            ll q=(x+1)/2;
            // cout<<p<<" "<<q<<" ";
            if(mp.count(p))
            {
                mp[p]--;
                n--;
            }
            else
            {
                pq.push(p);
            }
            if(mp[p]==0)
            mp.erase(p);
            if(mp.count(q))
            {
                mp[q]--;
                n--;
            }
            else
            {
                pq.push(q);
            }
            if(mp[q]==0)
            mp.erase(q);

        }
        if(pq.size()==0)
        {
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}