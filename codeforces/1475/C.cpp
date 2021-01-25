/*input
3
3 4 4
1 1 2 3
2 3 2 4
1 1 1
1
1
2 2 4
1 1 2 2
1 2 1 2

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fun(ll x){
	return (x*x-x)/2;
}

int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		ll n,m,k;cin>>n>>m>>k;
		vector<int> boys(n),girls(m);

		for(int i=0;i<k;i++) { int x;cin>>x; x--; boys[x]++; }
		for(int i=0;i<k;i++) { int x;cin>>x; x--; girls[x]++; }

		ll ans = (k*k-k)/2;

		for(int i=0;i<n;i++) ans -= fun((ll)boys[i]);
		for(int i=0;i<m;i++) ans -= fun((ll)girls[i]);

		cout<<ans<<"\n";



	}
	return 0;
}
