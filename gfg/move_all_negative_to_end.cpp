// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int a[],int n)
    {
        // Your code goes here
        vector<int> pos,neg;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            pos.push_back(a[i]);
            if(a[i]<0)
            neg.push_back(a[i]);
        }
        int i=0;
        for(int j=0;j<pos.size();j++)
        {
            a[i]=pos[j];
            i++;
        }
        for(int j=0;j<neg.size();j++)
        {
            a[i]=neg[j];
            i++;
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends