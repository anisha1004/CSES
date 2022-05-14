#pragma GCC optimize("O2")
#include<iostream>
using namespace std;

int mod=1e9+7;
//a(n)=4a(n-1)+b(n-1)
//b(n)=2b(n-1)+a(n-1)
long long dp[1000005][2]={0};

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        long long n;
        cin >> n;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
            dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1])%mod;
        }
        cout << (dp[n][0] + dp[n][1] )%mod<< endl;
    }
}