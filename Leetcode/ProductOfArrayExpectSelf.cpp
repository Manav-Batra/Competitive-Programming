class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int right=nums[n-1];
        vector<int> ans(n,1);
        ans[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i];
        }
        ans[n-1]=ans[n-2];
        for(int i=n-2;i>=1;i--)
        {
            ans[i]=ans[i-1]*right;
            right=right*nums[i];
        }
        ans[0]=right;
        return ans;
    }
};