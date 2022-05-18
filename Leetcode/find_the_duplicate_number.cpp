class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int dup;
        sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]==a[i+1])
        dup=a[i];
    }
        return dup;
    }
};