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
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> v(n);
        if(x>k)
        {
            cout<<-1<<endl;
            continue;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(count==x)
            count=0;
            v[i]=count;
            count++;

        }
        for(auto it : v)
        {
            cout<<it<<" ";
        }
        cout<<endl;

    }
}