class Solution {
public:
    long long mod=1e9+7;
    int countHousePlacements(int n) {
        if(n==1)
        {
            return 4;
        }
        if(n==2)
            return 9;
        if(n==3)
            return 25;
        if(n==4)
            return 64;
        long long a=5;
        long long b=8;
        long long total=a+b;
        for(long long i=6;i<=n;i++)
        {
            a=b;
            b=total;
            total=(a+b)%mod;
            
        }
        return (total*total)%mod;
    }
};