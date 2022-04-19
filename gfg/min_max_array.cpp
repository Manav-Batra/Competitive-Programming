pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long,long long> ans;
    sort(a,a+n);
    ans.first=a[0];
    ans.second=a[n-1];
    return ans;
}