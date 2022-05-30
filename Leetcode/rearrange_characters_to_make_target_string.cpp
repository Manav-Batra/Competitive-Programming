int rearrangeCharacters(string s, string target) {
        int  count=0;
        unordered_map<char,int> target_count;
        for(int i=0;i<target.length();i++)
            target_count[target[i]]++;
        unordered_map<char,int> s_count;
        for(int i=0;i<s.length();i++)
        s_count[s[i]]++;
        int mn=100000;
        for(int i=0;i<target.length();i++)
        {
            mn=min(mn,s_count[target[i]]/target_count[target[i]]);
        }
        return mn;
    }