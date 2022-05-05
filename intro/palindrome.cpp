#include<iostream>
using namespace std;
int main()
{
    string s;
    long i,c=0,n,j=0;
    cin>>s;
    n=s.length();
    long a[26]={0};
    char z[n]={0};
    for(i=0;i<n;++i)
    a[s[i]-65]++;
    for(i=0;i<26;++i)
    if(a[i]%2!=0)
    c++;
    if(c>1)
    cout<<"NO SOLUTION"<<"\n";
    else
    {
        for(i=0;i<26;++i)
        {
         if(a[i]%2==0)
         {
            char r=i+65;
            while(a[i]>0)
            {
                z[j]=r;
                z[n-j-1]=r;
                j++;
                a[i]-=2;
            }
         }
         else{
             int k=i;
             z[n/2]=i+65; 
             a[i]--;
             i=k-1;
         }   
        }   
    }
    for(i=0;i<n;++i)
    cout<<z[i];
    return 0;
}