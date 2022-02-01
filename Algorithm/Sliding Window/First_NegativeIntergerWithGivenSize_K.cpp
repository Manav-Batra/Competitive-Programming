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
vector<int> firstNeg(vector<int> v,int k)
{
    int i=0,j=0;
    queue<int> q;
    vector<int> ans;
    while(j<v.size())
    {
        if(v[j]<0)
        q.push(v[j]);
        if((j-i+1)<k)
        j++;
        else
        {
           if(q.size()==0)
           ans.push_back(0);
           else
           {
               ans.push_back(q.front());
               if(v[i]==q.front())
               q.pop();
               i++;
               j++;
           }
        }
    }
    return ans;

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
        vector<int> ans=firstNeg(v,k);
        for(auto it : ans)
        cout<<it<<" ";
        cout<<endl;
    }
}