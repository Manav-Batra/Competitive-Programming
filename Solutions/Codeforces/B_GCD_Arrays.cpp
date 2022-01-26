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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        ll count;
        if(r==l&&r!=1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(r==l&&r==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if((l%2!=0&&r%2==0)||(l%2==0&&r%2!=0))
        {
            count=(r-l-1)/2+1;
        }
        else if(l%2!=0&&r%2!=0)
        count=(r-l)/2+1;
        else
        count=(r-l)/2;
        if(count<=k)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
