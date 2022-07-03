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
string decodeMessage(string key, string message)
{
    string ans;
    int n = key.size();
    int m = message.size();
    set<char> st;
    for (int i = 0; i < n; i++)
    {
        if(key[i]==32)
        continue;
        st.insert(key[i]);
    }
    char ch[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int j=0;
    unordered_map<char,char> mp;
    for (int i = 0; i < n; i++)
    {
      if(st.find(key[i])!=st.end())
      {
             mp[key[i]]=ch[j];
             j++;
             st.erase(key[i]);
      }
      if(st.size()==0)
      break;
      
    }
    
    for(int i=0;i<m;i++)
    {
        if(message[i]==32)
        ans.push_back(message[i]);
        else
        ans.push_back(mp[message[i]]);
    }
    return ans;
}
int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    string ans=decodeMessage(key,message);
    cout<<ans<<endl;
}