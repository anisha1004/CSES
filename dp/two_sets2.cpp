#include<iostream>
#include<vector>
using namespace std;

int mod=1e9+7;
int solve_dp(int n, int x)
{
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    dp[0][0]=1;
    for(int i=1; i<n+1; ++i)
    {
        for(int j=0; j<x+1; ++j)
        {
            dp[i][j]=dp[i-1][j];
            if(j-i>=0)
                (dp[i][j]+=dp[i-1][j-i])%=mod;
        }
    }
    return dp[n-1][x];
}
int solve(int n, int x, int i, vector<vector<int>>& v)
{
    if(i>=n || x<0)
        return 0;
    if(x==0)
        return 1;
    if(v[i][x]!=-1)
        return v[i][x];
    int ans=0;
    (ans+=solve(n, x-(i+1), i+1, v))%=mod;
    (ans+=solve(n, x, i+1, v))%=mod;
    v[i][x]=ans;
    return v[i][x];
}
int main()
{
    int n;
    cin>>n;
    if(n*(n+1)/2%2==1)
        cout<<0<<"\n";
    else
    {
        int x=n*(n+1)/4;
        // vector<vector<int>> v(n+1, vector<int> (x+1, -1));
        // cout<<solve(n, x, 0, v);
        cout<<solve_dp(n, x);
    }
    return 0;
}