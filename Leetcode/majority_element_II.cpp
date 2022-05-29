 vector<int> majorityElement(vector<int>& nums) {
        int check=floor(nums.size()/3);
        // cout<<check;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : m)
        {
            if(it.second>check)
                ans.push_back(it.first);
        }
        return ans;
    }