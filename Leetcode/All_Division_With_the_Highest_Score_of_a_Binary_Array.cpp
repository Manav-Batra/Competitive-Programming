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
vector<int> ms(vector < int> &v)
{
    vector<int> t, ans;
    int count0 = 0, count1 = 0, countt0 = 0, countt1 = 0;
    for (auto it : v)
    {
        if (it == 1)
            count1++;
        else
            count0++;
    }
    t.push_back(count1);
    int temp=count0;
    count0=0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == 0)
            count0++;
        else
            count1--;
            
        t.push_back(count0 +count1);
    }
    t.push_back(temp);
    // for(auto it : t)
    // cout<<it<<" ";
    // cout<<endl;
    int max = -1e9;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] > max)
            max = t[i];
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (max == t[i])
            ans.push_back(i);
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
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> ans = ms(v);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}