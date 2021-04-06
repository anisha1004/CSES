#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    long long i,c=1,m=1;
    cin>>s;
    for(i=0;i<s.length()-1;++i)
    {
        if(s.at(i)==s.at(i+1))
        {
            c++;
            if(c>m)
            m=c;
        }
    }
    cout<<m;
    return 0;
}