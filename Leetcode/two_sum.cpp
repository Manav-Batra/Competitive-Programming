  vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                sum=sum+nums[j];
                if(target==sum)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
                else
                {
                    sum=sum-nums[j];
                }
            }
        }
        return ans;
    }