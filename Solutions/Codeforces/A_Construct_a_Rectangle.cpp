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
        map<ll, int> m;
        for (int i = 0; i < 3; i++)
        {
            ll x;
            cin >> x;
            m[x]++;
        }
        // cout<<m.size()<<endl;
        if (m.size() == 3)
        {
            vector<ll> v;
            for (auto it : m)
                v.push_back(it.first);
            if (v[2] == (v[0] + v[1]))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (m.size() == 2)
        {

            ll temp;
            ll check;
            for (auto it : m)
            {
                if (it.second == 2)
                    temp = it.first;
                if (it.second != 2)
                    check = it.first;
            }
            if (check % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        else
        {

            ll check;
            for (auto it : m)
                check = it.first;
            if (check % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}