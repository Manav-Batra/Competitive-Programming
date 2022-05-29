// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	     long long  maxp=-1000;
	    
	    long long  maxVal=1;
	    long long  minVal=1;
	    
	    if(n==1)
	    return arr[0];
	    for(long long  i=0;i<n;i++)
	    {
	        if(arr[i]>0)
	        {
	            maxVal*=arr[i];
	            if((minVal*arr[i])<1)
	            {
	                minVal=minVal*arr[i];
	            }
	            else
	            {
	                minVal=1;
	            }
	           // minVal=min(1,minVal*arr[i]);
	            
	        }
	        if(arr[i]<0)
	        {
	            long long temp=maxVal;
	            if((minVal*arr[i])>1)
	            {
	                maxVal=minVal*arr[i];
	            }
	            else
	            maxVal=1;
	            minVal=temp*arr[i];
	        }
	        if(arr[i]==0)
	        {
	            maxVal=1;
	            minVal=1;
	        }
	        if(maxp<maxVal)
	        maxp=maxVal;
	        
	    }
	    return maxp;
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends