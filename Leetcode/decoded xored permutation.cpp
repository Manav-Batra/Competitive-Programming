class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        int total=1;
        for(int i=2;i<=n+1;i++)
        {
            total=total^i;
        }
        
        int temp=0;
        for(int i=1;i<n;i=i+2)
        {
            temp=temp^encoded[i];
        }
        
        int first=temp^total;
        
        vector<int> ans;
        ans.push_back(first);
        
        for(int i=0;i<n;i++)
        {
            first=encoded[i]^first;
            ans.push_back(first);
        }
        return ans;
    }
};