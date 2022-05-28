// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:  
    bool bs(int v[], int n,int size)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == n)
            return true;
        else if (v[mid] > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
bool bs1(vector<int> v, int n)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == n)
            return true;
        else if (v[mid] > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> check_one,check_two;
            vector<int> final;
            for(int i=0;i<n1;i++)
            {
                if(bs(b,a[i],n2))
                check_one.push_back(a[i]);
            }
             for(int i=0;i<n3;i++)
            {
                if(bs(b,c[i],n2))
                check_two.push_back(c[i]);
            }
            sort(check_one.begin(),check_one.end());
            for(int i=0;i<check_two.size();i++)
            {
                if(bs1(check_one,check_two[i]))
                final.push_back(check_two[i]);
            }
            set<int > ans;
            for(auto it : final)
            ans.insert(it);
            final.clear();
            for(auto it : ans)
            {
                final.push_back(it);
            }
            return final;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends