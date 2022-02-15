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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string palin;
        bool ok=true;
        for(int i=n-1;i>=0;i--)
        {
            palin.push_back(s[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==palin[i])
            continue;
            else
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout<<1<<endl;

        }
        else
        {
            if(k==0)
            cout<<1<<endl;
            else
            cout<<2<<endl;
        }
    }
}