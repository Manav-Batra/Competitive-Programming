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
vector<int> g[N] ;
bool vis[N] ;
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
// int low = 0, high = v.size() - 1;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        int max=-1e9;
        for(auto it : m)
        {
            if(it.second>max)
            max=it.second;

        }
        if(max>(n/2))
        {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        sort(s.begin(),s.end());
        for(int i=0;i<s.length()/2;i++)
        {
            cout<<s[i];
        }
        for(int i=s.length()-1;i>=s.length()/2;i--)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}