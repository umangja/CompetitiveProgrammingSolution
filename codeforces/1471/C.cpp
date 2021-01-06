/*input
1
1 1
1
1


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
		ll n,m;cin>>n>>m;
		ll ans=0;
		vector<ll> k(n);
		for(int i=0;i<n;i++) cin>>k[i],k[i]--;

		vector<ll> cost(m);
		for(int i=0;i<m;i++) cin>>cost[i];

		sort(k.begin(), k.end(),greater<ll> ());

		ll L = 0;
		for(int i=0;i<n;i++)
		{
			if(L<k[i]) ans+=cost[L++];
			else ans+=cost[k[i]];
		}

		cout<<ans<<"\n";

	}
	return 0;
}
