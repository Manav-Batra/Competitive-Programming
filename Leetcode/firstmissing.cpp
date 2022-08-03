class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int res=n;
        int i=0;
        while(i<n)
        {
            if(nums[i]<n&&nums[i]>0&&nums[i]!=nums[nums[i]-1])
                swap(nums[nums[i]-1],nums[i]);
            else
                i++;
            
        }
        for(int j=0;j<n;j++)
            if(nums[j]!=j+1)
                return j+1;
        return res+1;
    }
};