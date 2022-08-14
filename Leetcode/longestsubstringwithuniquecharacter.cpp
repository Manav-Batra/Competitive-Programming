class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0;
        int n=s.size();
        int j=0;
        unordered_map<char,int> mp;
        while(j<n)
        {
        if(mp.find(s[j])!=mp.end())
        {
            i=max(i,mp[s[j]]+1);
        }
            mp[s[j]]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};