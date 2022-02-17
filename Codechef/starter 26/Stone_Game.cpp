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
        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        vector<char> ans(2*n);
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int front=0,back=2*n-1;
        int startA=0,endA=n-1;
        int startB=0,endB=n-1;
        // cout<<b<<endl;
        for(int i=0;i<2*n;i++)
        {
            if(i%2==0)
            {
                if(startB<=endB&&a[startA]>=b[startB])
                ans[back--]=a[endA--];
                else
                ans[front++]=a[startA++];
            }
            else
            {
                if(startA<=endA&&a[startA]>=b[startB])
                ans[back--]=b[endB--];
                else
                ans[front++]=b[startB++];
            }

        }
        for(int i=0;i<2*n;i++)
        cout<<ans[i];
        cout<<endl;

    }
}