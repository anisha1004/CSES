#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve_dp(vector<int>& h, vector<int>& s, int x, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    dp[0][0]=0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<=x; ++j)
        {
            if(j-h[i-1]>=0)
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-h[i-1]]+s[i-1]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][x];
}
int solve(vector<int>& h, vector<int> &s, int x, int i, int n, vector<vector<int>>& v)
{
    if(x<=0 || i>=n)
        return 0;
    if(v[i][x]!=-1)
        return v[i][x];
    int ans=INT32_MIN; 
    if(x-h[i]>=0)
        ans=max(solve(h, s, x-h[i], i+1, n, v)+s[i], solve(h, s, x, i+1, n, v));
    else
        ans=solve(h, s, x, i+1, n, v);
    v[i][x]=ans;
    return v[i][x];
}
int main()
{
    int  n, x;
    cin>>n>>x;
    vector<int> h(n);
    vector<int> s(n);
    for(int i=0; i<n; ++i)
        cin>>h[i];
    for(int i=0; i<n; ++i)
        cin>>s[i];
    // vector<vector<int>> v(n, vector<int>(x+1, -1));
    // cout<<solve(h, s, x, 0, n, v);
    cout<<solve_dp(h, s, x, n);
    return 0;
}