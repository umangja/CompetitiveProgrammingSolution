#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,a,n) for(ll i=a;i<n;i++)

int main()
{
	ll n;cin>>n;
	vector< ll > a(2*n);
	ll s1=0,s2=0;
	rep(i,0,2*n)
	{
		cin>>a[i];
		if(i>=n)
			s2+=a[i];
		else
			s1+=a[i];
	}

	sort(a.begin(), a.end());
	ll st=0;
	rep(i,0,n)
			st+=a[i];

	if(st==(s1+s2-st))
	{
		cout<<"-1";
		return 0;
	}

	rep(i,0,2*n)
		cout<<a[i]<<" ";
}