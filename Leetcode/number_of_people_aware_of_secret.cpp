class Solution {
public:
    long long mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> v(n,0);
        v[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+delay;j<i+forget&&j<n;j++)
            {
                v[j]=(v[j]%mod+v[i]%mod)%mod;
                
            }
            
        }
        long long ans=0;
        for(int i=n-forget;i<n;i++)
        {
            ans=(ans%mod+v[i]%mod)%mod;
        }
       
        
        return ans;
    }
};