class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            
              if (i==0 || nums[i]!=nums[i-1] ){
            int j=i+1;
            int k=n-1;
          
            
            
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==target)
                    return target;
                
                
                
                if(abs(nums[i]+nums[j]+nums[k]-target)<diff)
                {
                    diff=abs(nums[i]+nums[j]+nums[k]-target);
                    cout<<diff;
                    ans=nums[i]+nums[j]+nums[k];
                    
                    
                    
                }
                if(nums[i]+nums[j]+nums[k]>target)
                    k--;
                
                
                
                else
                    j++;
            }
              
              }
        }
        return ans;
    }
};