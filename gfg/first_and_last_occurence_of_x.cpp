// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    // vector<int> ans;
bool ok=false;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            {
               ok=true;
               break;
            }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    vector<int> final;
    if(ok==false)
    {
        final.push_back(-1);
        final.push_back(-1);
    }
    else
    {
    auto it =lower_bound(arr,arr+n,x);
    auto it2=upper_bound(arr,arr+n,x);

    
    
   
   
       final.push_back(it-arr);
       final.push_back((it2-arr)-1);
    }
    return final;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends