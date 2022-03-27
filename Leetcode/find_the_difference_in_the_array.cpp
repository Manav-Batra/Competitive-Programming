class Solution {
public:
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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        vector<int> ans1,ans2;
        set<int> s1,s2;
        for(auto it : nums1)
        {
            s1.insert(it);
        }
        for(auto it : nums2)
        {
            s2.insert(it);
        }
        vector<int> a,b;
        for(auto it : s1)
        {
            a.push_back(it);
        }
        for(auto it : s2)
        {
            b.push_back(it);
        }
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++)
        {
            if(bs(b,a[i])==false)
                ans1.push_back(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            if(bs(a,b[i])==false)
                ans2.push_back(b[i]);
        }
        res.push_back(ans1);
        res.push_back(ans2);
        return res;
    }
};