#include<iostream>
#include<vector>
using namespace std;

int mod=1e9+7;
int solve_dp(vector<vector<char>>& g, int i, int j, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0]=1;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(g[i][j]=='*')
                dp[i][j]=0;
            else
            {
                if(i>0)
                    dp[i][j]=dp[i-1][j]%mod;
                if(j>0)
                    (dp[i][j]+=dp[i][j-1])%=mod;
            }
        }
    }
    return dp[n-1][n-1];
}
int solve(vector<vector<char>>& g, int i, int j, int n, vector<vector<int>>& v)
{
    if(v[i][j]!=-1)
        return v[i][j];
    if (i == n - 1 && j == n - 1)
        return 1;
    int l = 0, r = 0;
    if (i + 1 != n && g[i + 1][j] != '*')
        l = solve(g, i + 1, j, n, v)%mod;
    if (j + 1 != n && g[i][j + 1] != '*')
        r = solve(g, i, j + 1, n, v)%mod;
    v[i][j]=(l + r)%mod;
    return v[i][j];
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>> g(n, vector<char>(n, '0'));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
            cin>>g[i][j];
    }
    if(g[0][0]=='*' || g[n-1][n-1]=='*')
        cout<<0;
    else
    {
        // vector<vector<int>> v(n+1, vector<int>(n+1, -1));
        // cout<<solve(g, 0, 0, n, v);
        cout<<solve_dp(g, 0, 0, n);
    }
        
    return 0;
}