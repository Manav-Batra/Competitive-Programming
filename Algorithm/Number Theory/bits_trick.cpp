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
void printbinary(int num)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main()
{
    // TRICK ONE-EVEN AND ODD CHECK
    for(int i=0;i<8;i++)
    {
        if(i&1)
        cout<<"odd"<<endl;
        else
        cout<<"even"<<endl;
    }

    // TRICK SECOND-MULTIPLY DIVIDE BY 2
    int a=5;
    cout<<(a>>1)<<endl;// DIVIDE BY 2
    cout<<(a<<1)<<endl;// MULTIPLY BY 2

    // TRICK THIRD->UPPER CASE TO LOWER CASE AND VICE VERSA
    // METHOD -1
    char ch='A';
    char c=(ch|(1<<5));
    cout<<c<<endl;
    char ch1='a';
    char c1=(ch1&(~(1<<5)));
    cout<<c1<<endl;

    // METHOD -> 2
    // (1<<5)-> SPACE ASCII
    // (~(1<<5))-> UNDERSCORE ASCII
    char c2=(ch|' ');
    char c3=(ch1&('_'));
    cout<<c2<<" "<<c3<<endl;

    // TRICK FOURTH->CLEAR LSB'S
    int b=73;
    printbinary(b);
    int i=3;
    printbinary(b&(~((1<<(i+1))-1)));
//    00001001001
//    00000010000
//    00000001111
//    11111110000
//    00001000000

// TRICK FIFTH->CLEAR MSB'S
printbinary(b&(1<<i)-1);

// 00001001001
// 00000000111
// 00000000001


// TRICK SIX->CHECK POWER OF 2
int n=16;
if(n&(n-1))
{
    cout<<"NOT POWER OF 2"<<endl;

}
else
{
    cout<<"POWER OF 2"<<endl;
}
    
}