#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>y>>x;
        if(y>x)
        {
            if(y%2==0)
            cout<<y*y-x+1<<"\n";
            else
            cout<<(y-1)*(y-1)+x<<"\n";
        }
        else
        {
            if(x%2==0)
            cout<<(x-1)*(x-1)+y<<"\n";
            else
            cout<<x*x-y+1<<"\n";
        }
    }
    return 0;
}