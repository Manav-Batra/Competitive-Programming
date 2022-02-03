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
const N=1e3;
int graph[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    // n is vertices of graph 
    // m is number of edges in a graph
    for(int i=0;i<m;i++)
    {
       int v1,v2;
       cin>>v1>>v2;
       graph[v1][v2]=1;
       graph[v2][v1]=1;

    }
    // O(n^2)->space complexity
    // when n=1e5 then it will through error
}