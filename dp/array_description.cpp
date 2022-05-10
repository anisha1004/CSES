#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a, int curr, int ind, int n, int m)
{
    if(curr>m || ind>n-1 || curr<0 || curr==0)
        return 0;
    if(ind==n-1)
    {
        if(a[n-1]==curr || a[ind]==0)
            return 1;
        else
            return 0;
    }
    int ans=0;
    if(a[ind]==curr || a[ind]==0)
        ans+=solve(a, curr, ind+1, n, m)+ solve(a , curr+1, ind+1, n, m)+solve(a, curr-1, ind+1, n, m);
    return ans;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int ans=0;
    for(int i=1; i<=m; ++i)
        ans+=solve(a, i, 0, n, m);
    cout<<ans;
    return 0;
}