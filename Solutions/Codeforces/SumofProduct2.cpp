#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
const ll mod=998244353;
const ll N=2e5+1;
ll fact[N];
ll addm(ll a,ll b)
{
    return (a+b)%mod;
}
ll subm(ll a, ll b)
{
    return ((a-b)%mod+mod)%mod;
}
ll multim(ll a,ll b)
{
    return (a*b)%mod;
}
ll powrm(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=multim(res,a);
        a=multim(a,a);
        b=b>>1;
    }
    return res;
}
ll inv(ll x)
{
    return powrm(x,mod-2);
}
ll divm(ll a, ll b)
{
    return multim(a,powrm(b,mod-2));
}
ll ncr(ll n ,ll r)
{
    return multim(multim(fact[n],inv(fact[r])),inv(fact[n-r]));
}
void cal_fact()
{
    fact[0]=1;
    for(ll i=1;i<=N;i++)
    {
        fact[i]=multim(fact[i-1],i);
    }
}
int main()
{
    cal_fact();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll one=0;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            if(x)
            one++;
        }
     ll ans=0;
        for(ll i=1;i<=one;i++)
        {
            ans=addm(ans,multim(ncr(one,i),multim(fact[i],multim((n-i+1),fact[n-i]))));
        }
        cout<<ans<<endl;
    }
}