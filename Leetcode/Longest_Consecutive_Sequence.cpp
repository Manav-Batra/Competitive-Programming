class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        vector<int> res;
        for(auto it : s)
            res.push_back(it);
        int ans=0;
        int m=res.size();
        int count=0;
        if(m==0)
        {
            return 0;
            
        }
        if(m==1)
        {
            return 1;
        }
        for(int i=0;i<m-1;i++)
        {
            if((res[i]+1)==res[i+1])
            {
                count++;
                ans=max(ans,count);
            }
            else
                count=0;
        }
        return ans+1;
    }
};