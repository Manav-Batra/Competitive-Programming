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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ans = 0;
        ll first_index = -1, last_index = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                first_index = i;
                break;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                last_index = i;
                break;
            }
        }
        if (first_index == -1)
        {
            cout << 0 << endl;
            continue;
        }
        if (first_index == 0 && last_index == (n - 1))
        {
            string temp = "";
            for (int i = 0; i < s.length() - 1; i++)
            {
                temp = temp + s[i];
                temp=temp+s[i+1];
                stringstream ss;
                ss<<temp;
                ll a;
                ss>>a;
                ans=ans+a;
                temp.clear();
            }
            cout<<ans<<endl;
            continue;
        }
        // cout<<first_index<<" "<<last_index<<endl;
        if(first_index==last_index)
        {
            if(first_index==(n-1))
            {
                cout<<1<<endl;
                continue;
            }
            if(first_index==0)
            {
                if(k>=(n-1))
                {
                    cout<<1<<endl;
                    continue;
                }
                cout<<10<<endl;
                continue;
            }
            if(k>=(n-first_index-1))
            {
                cout<<1<<endl;
                continue;
            }
            if(k>=first_index)
            {
                cout<<10<<endl;
                continue;
            }
            cout<<11<<endl;
            continue;
        }
        if(k>=(n-last_index-1))
        {
            k=k-(n-last_index-1);
            s[last_index]='0';
            s[n-1]='1';
        }
        if(k>=first_index)
        {
            k=k-first_index;
           
            s[first_index]='0';
             s[0]='1';
        }
        // cout<<s<<endl;
         string temp="";
        for(int i=0;i<n-1;i++)
        {
            
            temp=temp+s[i];
            temp=temp+s[i+1];
            stringstream ss;
            ss<<temp;
            ll b;
            ss>>b;
            ans=ans+b;
            temp.clear();
        }
        cout<<ans<<endl;
    }
}