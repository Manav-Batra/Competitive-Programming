class Solution {
public:
    bool check(string &s,string &p,int start_s,int start_p,vector<vector<int>> &dp)
    {
        
       if(start_s>=s.size() and start_p>=p.size())
           return true;
        if(start_p>=p.size() and start_s<s.size())
            return false;
        if(start_s>=s.size() and start_p<p.size())
        {
            for(int i=start_p;i<p.size();i++)
            {
                if(p[i]!='*')
                    return false;
            }
            return true;
        }
        if(dp[start_s][start_p]!=-1)
            return dp[start_s][start_p];
        if(p[start_p]=='?')
             return dp[start_s][start_p]=check(s,p,start_s+1,start_p+1,dp);
        if(p[start_p]=='*')
        {
           return dp[start_s][start_p] = check(s,p,start_s,start_p+1,dp)||check(s,p,start_s+1,start_p,dp);
        }
        if(s[start_s]!=p[start_p])
            return false;
         return dp[start_s][start_p]= check(s,p,start_s+1,start_p+1,dp);
        return dp[start_s][start_p];
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,-1));
        return check(s,p,0,0,dp);
    }
};