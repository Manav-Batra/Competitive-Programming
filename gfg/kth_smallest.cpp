int kthSmallest(int arr[], int l, int r, int k) {
        int ans;
        sort(arr+l,arr+r+1);
        ans=arr[k-1];
        return ans;
    }