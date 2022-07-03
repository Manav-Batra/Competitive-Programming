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
void leftrotatearray(vector<ll> &v,int k,int n)
{
    vector<ll> temp(n);
    int mod=k%n;
    int j=0;
    for(int i=0;i<n;i++)
    {
      temp[j]=v[(mod+i)%n];
    //   cout<<temp[j]; 
      j++; 
    }
    // cout<<endl;
    v.clear();
    for(ll i=0;i<n;i++)
    {
     v[i]=temp[i];
    //  cout<<v[i];
    }
    // cout<<endl;
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++)
        cin>>v[i];
        vector<ll> d(n);
        vector<ll> a=v;
        sort(a.begin(),a.end());
        ll j=n-1;
        ll temp=a[j];
        ll i=0;
        ll m=n;
        bool ok=false;
        while(i<n)
        {
             if(temp==v[i])
            {
               ll tt=i;
               if((i+1)!=v[i])
               d[j]=i+1;
               else
               d[j]=0;
               if(temp==1&&tt==0)
               {
d[j]=0;
               }
            //    cout<<tt<<" "<<d[j]<<endl;
               leftrotatearray(v,tt+1,n);
            //  for(int i=0;i<n;i++)
            //  cout<<v[i]<<" ";
            //  cout<<endl;
               n--;
               j--;
               i=-1;
               temp=a[j];
            //    cout<<n<<" "<<j<<" "<<i<<endl;
            //    ok=true;
            }
            i++;
            // cout<<
            // cout<<n<<" "<<j<<" "<<i<<endl;

            
        }
        for(int i=0;i<m;i++)
        cout<<d[i]<<" ";
        cout<<endl;
        if(d[0]!=0)
        cout<<-1<<endl;
    
    }
}