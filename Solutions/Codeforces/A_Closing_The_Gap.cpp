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
        int n;
        cin>>n;
        vector<ll> v(n);
        ll sum=0;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            sum=sum+v[i];
        }
        if(sum%n==0)
        cout<<0<<endl;
        else
        cout<<1<<endl;

    }
}