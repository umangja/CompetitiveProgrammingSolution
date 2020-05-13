#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int l1,b1,l2,b2;
        cin>>l1>>b1>>l2>>b2;
        if(l1==l2 && l1==b1+b2)        cout<<"YES\n";
        else if(l1==b2 && l1 == b1+l2) cout<<"YES\n";
        else if(b1==b2 && b1 == l1+l2) cout<<"YES\n";
        else if(b1==l2 && l2 == b2+l1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}