class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &v,int target,vector<int> &candidates,int i)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j]>target)
                break;
            v.push_back(candidates[j]);
            target=target-candidates[j];
            solve(ans,v,target,candidates,j);
            v.pop_back();
            target=target+candidates[j];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(ans,v,target,candidates,0);
        return ans;
    }
};