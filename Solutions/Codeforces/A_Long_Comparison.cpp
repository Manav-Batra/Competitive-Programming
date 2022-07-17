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
        ll x1,p1,x2,p2;
        cin>>x1>>p1;
        cin>>x2>>p2;
        ll m=min(p1,p2);
        p1=p1-m;
        p2=p2-m;
        if(p1>=7)
        {
            cout<<">"<<endl;

        }
        else if(p2>=7)
        {
            cout<<"<"<<endl;

        }
        else
        {
            for(int i=0;i<p1;i++)
            x1=x1*10;
            for(int i=0;i<p2;i++)
            x2=x2*10;
            if(x1>x2)
            {
                cout<<">"<<endl;

            }
            else if(x1==x2)
            {
                cout<<"="<<endl;
            }
            else
            {
                cout<<"<"<<endl;
            }
        }
    }
}