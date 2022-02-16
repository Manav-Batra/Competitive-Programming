#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;
bool bs(vector<int> v, int n)
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

void dfs(vector<vector<int>> &image, int i, int j, int newcolor, int originalcolor)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != originalcolor)
        return;
    image[i][j] = newcolor;
    dfs(image, i - 1, j, newcolor, originalcolor);
    dfs(image, i + 1, j, newcolor, originalcolor);
    dfs(image, i, j + 1, newcolor, originalcolor);
    dfs(image, i, j - 1, newcolor, originalcolor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int originalcolor = image[sr][sc];
    if (originalcolor != newColor)
    {
        dfs(image, sr, sc, newColor, originalcolor);
    }
    return image;
}
int main()
{
}