#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;
int bs(vector<int> v, int n)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == n)
            return 1;
        else if (v[mid] > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
bool ls(vector<int> v,int n)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==n)
        {
            return true;
        }
    }
    return false;
}
int findFinalValue(vector<int> &nums,int o)
{
    
    while(ls(nums,o))
    {
        o=o*2;
        // cout<<o<<endl;
    }
    return o;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        int o;
        cin>>o;
        ll ans=findFinalValue(v,o);
        cout<<ans<<endl;
    }
}