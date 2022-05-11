#include<iostream>
#include<vector>
using namespace std;

int mod=1e9+7;
int solve_dp(vector<int>& a, int ind, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    dp[0][0]=1;
    for(int i=0; i<n+1; ++i)
    {
        for(int j=1; j<m+1; ++j)
        {
            if(i==0)
                dp[i][j]=1;
            if(i==1)
            {
                if(a[i-1]==j || a[i-1]==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
            if(a[i]==j || a[i]==0)
                dp[i][j]=((dp[i-1][j+1]+dp[i-1][j])%mod+dp[i-1][j-1])%mod;
        }
    }
    int ans=0;
    for(int i=1; i<=m; ++i)
        (ans+=dp[n][i])%=mod;
    return ans;
}
int solve(vector<int>& a, int curr, int ind, int n, int m, vector<vector<int>>& v)
{
    if(curr>m || ind>n-1 || curr<0 || curr==0)
        return 0;
    if(v[ind][curr]!=-1)
        return v[ind][curr];
    if(ind==n-1)
    {
        if(a[n-1]==curr || a[ind]==0)
            return v[ind][curr]=1;
        else
            return v[ind][curr]=0;
    }
    int ans=0;
    if(a[ind]==curr || a[ind]==0)
        (ans+=(solve(a, curr, ind+1, n, m, v)%mod+ solve(a , curr+1, ind+1, n, m, v)%mod)%mod+solve(a, curr-1, ind+1, n, m, v)%mod)%=mod;
    v[ind][curr]=ans;
    return v[ind][curr];
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int ans=0;
    vector<vector<int>> v(n+1, vector<int>(m+1, -1));
    for(int i=1; i<=m; ++i)
        (ans+=solve(a, i, 0, n, m, v))%=mod;
    cout<<ans;
    return 0;
}