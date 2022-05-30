// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        // code here
 sort(a,a+n);
 int ans=a[n-1]-a[0];
 for(int i=1;i<n;i++)
 {
     int maxa=max(a[i-1]+k,a[n-1]-k);
     int mini=min(a[0]+k,a[i]-k);
     if(mini<0)
     continue;
     ans=min(ans,(maxa-mini));
 }
 return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends