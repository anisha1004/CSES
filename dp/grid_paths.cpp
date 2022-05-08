#include<iostream>
#include<vector>
using namespace std;

int mod=1e9+7;

int solve(vector<vector<char>>& g, int i, int j, int n)
{
    if(i==n-1 && j==n-1)
        return 0; 
    int l=0, r=0;
    if(i+1!=n && g[i+1][j]!='*')
        int l=solve(g, i+1, j, n)+1;
    if(j+1!=n && g[i][j+1]!='*')
        int r=solve(g, i, j+1, n)+1;
    return l+r;
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
    cout<<solve(g, 0, 0, n);
    return 0;
}