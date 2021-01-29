/*input
2
4 1
20100 1 202 202
3 100
1 1 1

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		ll n,k;cin>>n>>k;
		vector<ll> p(n);
		for(ll i=0;i<n;i++) cin>>p[i];

		ll sum = p[0];
		ll ans = 0;

		for(ll i=1;i<n;i++){

			// (p[i])*100 <= k*(sum[i-1]+x);
			if(  p[i]*100 > k*sum  ){
				ll x =  (p[i]*100 - k*sum + k-1)/k;
				p[i] += x;
				ans += x;

				// cout<<x<<"\n";
			}
			sum += p[i];
			// cout<<sum<<"\n";
		}

		cout<<ans<<"\n";

	}
	return 0;
}
