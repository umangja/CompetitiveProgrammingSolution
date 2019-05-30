#include<bits/stdc++.h>
using namespace std;
map< long long int,long long int > lf,rt;

int main()
{
	long long int n,k;
	cin>>n>>k;
	vector< long long int > a(n);
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%k==0)
			rt[a[i]/k]++;
	}

	long long int ans=0;
	for(long long int i=0;i<n;i++)
	{
		if(a[i]%k==0 && rt[a[i]/k]!=0)
			rt[a[i]/k]--;

		ans+=lf[a[i]]*rt[a[i]];
		lf[a[i]*k]++;
	}

	cout<<ans;
	return 0;
}