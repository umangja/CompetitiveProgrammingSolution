/*input
6
9 2
1337 1
1 1
50000000 4
991026972 997
1234 5678

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fun(ll a,ll b){
	ll ans = 0;

	while(a>0){
		a = a/b;
		ans++;
	}
	return ans;
}
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		ll a,b;cin>>a>>b;

		ll k  =0;
		if(b ==1 ) b++,k=1;
		ll ans = fun(a,b) + k;
		for(ll add = 1; add<ans+1; add++){
			ans=min(ans,fun(a,b+add)+add+k);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
