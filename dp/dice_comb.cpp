#include<iostream>
#include<vector>
#define int long long
using namespace std;
int mod=1e9+7;
int solve_dp(int n)
{
    vector<int> dp(n+1, 0);
    dp[0]=1;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=6; ++j)
        {
            if(i-j>=0)
                (dp[i]+=dp[i-j])%=mod;
        }
    }
    return dp[n];
}
int solve(int n,  vector<int>& v)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(v[n]!=-1)
        return v[n];
    int ans=0;
    for(int i=1; i<=6; ++i)
    {
        ans+=solve(n-i, v)%mod;
    }
    v[n]=ans%mod;
    return v[n]%mod;
}
signed main()
{
    int n;
    cin>>n;
    //cout<<solve(n, v);
    cout<<solve_dp(n);
    return 0;
}