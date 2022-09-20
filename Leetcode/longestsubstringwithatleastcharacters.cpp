class Solution {
public:
    int solve(string &s,int k,int total)
    {
        int i=0,j=0;
        unordered_map<char,int> mp;
        int count=0;
        int ans=0;
        int len=0;
        while(j<s.size())
        {

            mp[s[j]]++;
            if(mp[s[j]]==1)
                count++;
            if(mp[s[j]]==k)
                len++;
            if(count<total)
                j++;
            else
            {
                while(count>total)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        // mp.erase(s[i]);
                        count--;
                    }
                    if(mp[s[i]]==k-1)
                        len--;
                    i++;
                    
                }
                if(len==total)
                    ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        int ans =0;
      for(int i=1;i<=26;i++)
      {
          ans=max(ans,solve(s,k,i));
      }
        return ans;
    }
};