class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int > mp;
        for(auto it : t)
            mp[it]++;
        
        int count = mp.size(), ansLength =INT_MAX;
        string ans = "";
        
        int i = 0, j = 0;
        while(j < s.length()) {
            
if(mp.find(s[j])!=mp.end())
{
    mp[s[j]]--;
    if(mp[s[j]]==0)
        count--;
}
            
            if(count > 0)
                j++;
            
            else if(count == 0) {  
                  
                while(count == 0) {
                    
                    if(j-i+1 < ansLength) {
                        ansLength = j-i+1;
                        ans = s.substr(i, j-i+1);
                    }
                    
                   if(mp.find(s[i])!=mp.end())
                   {
                       mp[s[i]]++;
                       if(mp[s[i]]==1)
                           count++;
                   }
                    
                    i++;    
                }  
                
                j++;  
            }
        }
        
        return ans;
         
    }
};