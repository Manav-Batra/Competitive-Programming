class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n=rolls.size();
        set<int> st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.find(rolls[i])==st.end())
                st.insert(rolls[i]);
        
                if(st.size()==k)
                {
                    st.clear();
                    ans++;
                }
            
        }
        return 1+ans;
    }
};