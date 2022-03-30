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
const int N = 1e7+10;
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
vector<bool> isprime(N,true);
vector<int> lp(N,0),hp(N,0);
int main()
{
    isprime[0]=isprime[1]=false;
    for(int i=2;i<N;i++)
    {
        if(isprime[i]==true)
        {
            lp[i]=hp[i]=i;
            for(int j=2*i;j<N;j+=i)
            {
                isprime[j]=false;
                hp[j]=i;
                if(lp[j]==0)
                lp[j]=i;
            }
        }
    }

    // PRIME FACTORIZATION
    int n;
    cin>>n;
    vector<int> prime_factors;
    while(n>1)
    {
        int p=hp[n];
        while(n%p==0)
        {
            prime_factors.push_back(p);
            n=n/p;
        }
    }
    for(auto it : prime_factors)
    cout<<it<<" ";
    cout<<endl;
}