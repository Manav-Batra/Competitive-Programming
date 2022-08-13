class Solution {
public:
    bool solve(vector<int> &nums,int i,int target,int curr_sum,int k,vector<bool> &vis)
    {
        if(k==1)
            return true;
        if(i>=nums.size())
            return false;
        if(curr_sum==target)
            return solve(nums,0,target,0,k-1,vis);
        
        for(int j=i;j<nums.size();j++)
        {
            if(vis[j]==false and curr_sum+nums[j]<=target)
            {
                vis[j]=true;
                if(solve(nums,j+1,target,curr_sum+nums[j],k,vis))
                    return true;
                vis[j]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(n<k||sum%k!=0)
            return false;
        vector<bool> vis(n,false);
        return solve(nums,0,sum/k,0,k,vis);
    }
};