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
        ll w,h;
        cin>>w>>h;
        ll ans=0;
        // int b=4;
        for(int b=0;b<4;b++)
        {
            ll k;
            cin>>k;
            vector<ll> a;
            for(int i=0;i<k;i++)
            {
                ll x;
                cin>>x;
                a.push_back(x);
            }
            sort(a.begin(),a.end());
            ll temp=(a[k-1]-a[0]);
            if(b<2)
            temp=temp*h;
            else
            temp=temp*w;
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
        
    }
}