#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	// your code goes here
     int t;
     cin>>t;
     while(t--)
     {
          int n,x,y;
         cin>>n>>x>>y;
         vector<int > a(n);
         long long  max=-1;
         int   max_index;
         for(int i=0;i<n;i++)
         {
             cin>>a[i];
             if(a[i]>=max)
             {
                 max_index=i;
                 max=a[i];
             }
         }
         if(x<=y)
         {
             cout<<(max/y)+(max%y==0?0:1)<<endl;
             continue;
         }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            a[i]-=ans*y;
            if(a[i]>0)
            {
                ans+=(a[i]%x==0?a[i]/x:a[i]/x+1);
            }
        }
        cout<<ans<<endl;
        
     }

	return 0;
}
