#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int solve_dp(string s, string t, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0]=0;
    for(int j=0; j<m+1; ++j)
        dp[0][j]=j;
    for(int i=0; i<n+1; ++i)
        dp[i][0]=i;
    for(int i=1; i<n+1; ++i)
    {
        for(int j=1; j<m+1; ++j)
        {
            // if(i==0) dp[i][j]=j;
            // else if(j==0) dp[i][j]=i;
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
            }
        }
    }
    return dp[n][m];
}
int solve(string s, string t, int i, int j, vector<vector<int>>& v)
{
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(v[i][j]!=-1)
        return v[i][j];
    if(s[i]==t[j])
        return v[i][j]=solve(s, t, i-1, j-1, v);
    v[i][j]=min({1+solve(s, t, i-1, j, v), 1+solve(s, t, i, j-1, v), 1+solve(s, t, i-1, j-1, v)}); 
    return v[i][j];
}
int main()
{
    string s, t;
    cin>>s>>t;
    //int n=s.size()-1, m=t.size()-1;
    // vector<vector<int>> v(n+1, vector<int>(m+1, -1));
    // cout<<solve(s, t, n, m, v);
    int n=s.size(), m=t.size();
    cout<<solve_dp(s, t, n, m);
    return 0;
}