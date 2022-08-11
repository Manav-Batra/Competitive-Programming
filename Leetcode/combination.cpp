class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void combination(int i,vector<int>& nums,int k)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            temp.push_back(nums[j]);
            combination(j+1,nums,k);
            temp.pop_back();
            // combination(i+1,nums,k);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        int m=nums.size();
        combination(0,nums,k);
        return ans;
    }
};