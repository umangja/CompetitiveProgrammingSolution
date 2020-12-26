/*input
4 4
1 25 121 169
1 2 7 23

*/

// gcd(a,b) = gcd(b,b-a)  if b>a

// gcd(a+x,b+x) = gcd(b+x,b-a);

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		vector<ll> a(n),b(m);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];

		if(n==1)
		{
			for(int i=0;i<m;i++) cout<<b[i]+a[0]<<" ";
			continue;
		}

		sort(a.begin(), a.end(),greater<ll> ());
		for(int i=1;i<n;i++) a[i] = a[0] - a[i];
		ll g = a[1];
		for(int i=2;i<n;i++) g=__gcd(g,a[i]);
		for(int i=0;i<m;i++) cout<<__gcd(a[0]+b[i],g)<<" ";
	}
	return 0;
}
