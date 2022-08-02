class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum+=cardPoints[i];
        }
        for(int i=0;i<n-k;i++)
        {
            sum+=cardPoints[i];
        }
        int mn_sum=sum;
        for(int i=n-k;i<n;i++)
        {
            sum=sum+cardPoints[i]-cardPoints[i-(n-k)];
            mn_sum=min(sum,mn_sum);
        }
        cout<<total_sum<<" ";
        cout<<mn_sum<<" ";
        return total_sum-mn_sum;
    }
};