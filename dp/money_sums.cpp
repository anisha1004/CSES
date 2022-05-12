#include<iostream>
#include<vector>
#include<set>
using namespace std;
void solve_dp(vector<int> v, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(1000*n+1, 0));
    dp[0][0]=1;
    for(int i=1; i<n+1; ++i)
    {
        for(int j=0; j<1000*n+1; ++j)
        {
            dp[i][j]=dp[i-1][j];
            if(j-v[i-1]>=0 && dp[i-1][j-v[i-1]]==1)
                dp[i][j]=1;
        }
    }
    vector<int> ans;
    for(int i=1; i<1000*n+1; ++i)
    {
        if(dp[n][i]==1)
            ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto i: ans)
        cout<<i<<" ";
}
void solve(vector<int>& v, set<int>& s, int i, int sum, int n)
{
    if(i==n)
    {
        if(sum!=0)
            s.insert(sum);
        return;
    }
    solve(v, s, i+1, sum+v[i], n);
    solve(v, s, i+1, sum, n);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    // set<int> s;
    // solve(v, s, 0, 0, n);
    // cout<<s.size()<<"\n";
    // for(auto &i: s)
    //     cout<<i<<" ";
    solve_dp(v, n);
    return 0;
}