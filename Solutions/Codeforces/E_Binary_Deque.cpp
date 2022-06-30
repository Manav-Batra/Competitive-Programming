#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{ 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll t;
cin>>t;
while(t--){
 
ll n,s;
cin>>n>>s;
int a[n];
ll check=0;

for(int i=0;i<n;i++){
cin>>a[i];
check+=a[i];
}
if(check<s)
{
    cout<<-1<<endl;
    continue;
}
 
int i=0,j=0;
int sum=0;
int len=0;
int size=0;
while(j<n){
    sum+=a[j];
    if(sum<s)j++;
    else if(sum==s){
         size=j-i+1;
           len=max(len,size);
           j++;
    }
    else if(sum>s){
           while(sum>s){
            sum=sum-a[i];
            i++;
           }
            size=j-i+1;
           len=max(len,size);
           j++;

    }

}

ll ans= n-len;
cout<<ans<<endl;


}
    return 0;
}