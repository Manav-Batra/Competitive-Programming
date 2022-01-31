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
int  maxSlidingWindow(vector<int> v,int k)
{
    int i=0,j=0,sum=0;
    int max=-1e9;
    while(j<v.size())
    {
        sum+=v[j];
        if((j-i+1)<k)
        j++;
        else
        {
           if(sum>max)
           max=sum;
           sum=sum-v[i];
           i++;
           j++;
        }
    }
    return max;
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
        int k;
        cin>>k;
        int ans=maxSlidingWindow(v,k);
        cout<<ans<<endl;
    }
}