class Solution {
public:
    bool check(int mid,vector<int> nums,int operations)
    {
        if(mid==0)
            return false;
        int moves=0;
        for(int i=0;i<nums.size();i++)
        {
operations-=nums[i]/mid;
            if(nums[i]%mid==0)
                operations++;
        }
        // cout<<mid<<" "<<moves<<endl;
        if(operations>=0)
        {
            return true;
        }
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=0;
        int high=INT_MAX;
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,nums,maxOperations))
            {
                ans=mid;
                // cout<<ans<<endl;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        // cout<<9/3-1<<endl;
        return ans;
    }
};