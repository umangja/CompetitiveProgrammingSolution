#include<bits/stdc++.h>
using namespace std;

#define sz(s) (long long int)s.size()

string fun(long long int n)
{
	string ans = "";
	while(n)
	{
		ans+=('0'+(n&1));
		n/=2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main()
{
	long long int l,r;
	scanf("%lld %lld",&l,&r);
	string s1=fun(l),s2=fun(r);
	while(sz(s1)<sz(s2))
		s1='0'+s1;

	long long int p[65];
	p[0]=1;
	for(int i=1;i<65;i++)
		p[i]=p[i-1]*2;
	for(long long int i=0;i<sz(s2);i++)
	{
		if(s1[i]!=s2[i])
		{
			int s = sz(s2);
			long long int ans = p[(s-i)]; 
			cout<<ans-1;
			return 0;
		}
	}


	cout<<"0";
	return 0;
}