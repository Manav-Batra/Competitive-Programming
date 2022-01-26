#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007;
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
int numberOfWays(string c)
{
    int seat=0;
    for(int i=0;i<c.length();i++)
    {
        if(c[i]=='S')
        seat++;
    }
    if(seat<2)
    return 0;
    if(seat==2&&c.length()==2)
    return 1;
    seat=0;
    int index,last;
    for(int i=0;i<c.length();i++)
    {
        if(c[i]=='S')
        seat++;
        if(seat==2&&c[i]=='S')
        index=i;
        if(seat>2)
        {
            last=i;
            break;
        }

    }
    // cout<<last<<" "<<index<<endl;
    if(seat==2)
    return (c.length()-index-1);
    return last-index;

}
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    cout<<numberOfWays(s);

}