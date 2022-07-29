class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool ok=true;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>=nums[i+1])
                continue;
            else
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            if(nums[n-1]>nums[n-2])
            {
                swap(nums[n-2],nums[n-1]);
                
            }
            else
            {
                for(int i=n-2;i>0;i--)
                {
                    if(nums[i]>nums[i-1])
                    {
                        for(int j=n-1;j>i;j--)
                        {
                            if(nums[j]>nums[i-1])
                            {
                                swap(nums[i-1],nums[j]);
                                sort(nums.begin()+i,nums.end());
                                return;
                            }
                            
                        }
                        swap(nums[i],nums[i-1]);
                        sort(nums.begin()+i,nums.end());
                        return ;
                    }
                }
            }
        }
    }
};