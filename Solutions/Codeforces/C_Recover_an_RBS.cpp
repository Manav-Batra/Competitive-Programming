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

        ll buffer=0,cnt=0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]==')')
            cnt++;
            else if(s[i]=='(')
            cnt--;
            else
            buffer++;
        }

        ll open=(cnt+buffer)/2;
        ll close=(buffer-cnt)/2;

        if(open==0||close==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        string check=string(open-1,'(')+string(1,')')+string(1,'(')+string(close-1,')');
        ll ptr=0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                s[i]=check[ptr++];
            }
        }       
        
        cnt=0;
        bool ok=false;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            cnt++;
            else
            cnt--;
            if(cnt<0)
            {
                ok=true;
                break;

            }
            

        }
        if(ok)
        {
            cout<<"YES"<<endl;

        }
        else
        {
            cout<<"NO"<<endl;
        }
        


    }
}