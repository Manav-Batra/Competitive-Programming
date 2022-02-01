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
vector<int> countAnagram(map<char, int> m, string s, int k)
{
    vector<int> ans;
    int count = m.size();
    int i = 0, j = 0;
    // int ans = 0;
    while (j < s.size())
    {
        if (m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                count--;
            }
            // cout<<s[j]<<" "<<m[s[j]]<<endl;
    
        if ((j - i + 1) < k)
            j++;
        else
        {
            if (count == 0)
                ans.push_back(i);
            if (m.find(s[i]) != m.end())
             {
                 m[s[i]]++;
                 if(m[s[i]]==1)
                 count++;
             }
            i++;
            j++;
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
        string s, p;
        cin >> s >> p;
        int k = p.length();
        map<char, int> m;
        for (int i = 0; i < k; i++)
        {
            m[p[i]]++;
        }
        // for (auto it : m)
        //     cout << it.first << " " << it.second << endl;
        vector<int> ans = countAnagram(m, s, k);
        for(auto it : ans)
        cout<<it<<" ";
        cout<<endl;
        // for(int i=0;i<s.length();i++)
        // {
        //     cout<<s[i]<<" "<<m[s[i]]<<endl;
        // }
    }
}