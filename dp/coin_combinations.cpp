#include<iostream>
#include<vector>
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int mod=1e9+7;
// int solve_dp(vector<int>& coins, int x)
// {
//     vector<int> dp(x+1, 0);
//     dp[0]=1;
//     for(int i=1; i<=x; ++i)
//     {
//         for(int j=0; j<coins.size(); ++j)
//         {
//             if(i-coins[j]>=0)
//                 (dp[i]+=dp[i-coins[j]])%=mod;
//         }
//     }
//     return dp[x];
// }
// int solve(vector<int>& coins, int tar,  vector<int>& v)
// {
//     if(tar==0) 
//         return 1;
//     if(tar<0)
//         return 0;
//     if(v[tar]!=-1)
//         return v[tar];
//     int ans=0;
//     for(int i=0; i<coins.size(); ++i)
//     {
//         (ans+=solve(coins, tar-coins[i], v))%=mod;
//     }
//     v[tar]=ans;
//     return v[tar];
// }

int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> c(n);
  for (int&v : c) cin >> v;

  vector<int> dp(target+1,0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
      if (i-c[j] >= 0) {
	(dp[i] += dp[i-c[j]]) %= mod;
      }
    }
  }
  cout << dp[target] << endl;
}