/*input
3
6
1 3 2 1 4 2
4
100 100 4 100
8
1 2 3 3 3 2 6 6

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		ll n;cin>>n;
		map<ll,ll> cnt;
		for(ll i=0;i<n;i++) {
			ll x;cin>>x;
			cnt[x]++;
		}
		vector<ll> f;
		for(auto p : cnt) f.push_back(p.second);
		sort(f.begin(), f.end());

		n = (int)f.size();

		vector<ll> L(n,0);
		vector<ll> R(n,0);
		for(ll i=0;i<n;i++) L[i] = (i-1>=0?L[i-1]:0) + f[i];
		for(ll i=n-1;i>=0;i--) R[i] = (i+1<n?R[i+1]:0) + f[i];
 
		ll ans = accumulate(f.begin(), f.end(),0ll);
		// for(ll i=0;i<n;i++) cout<<f[i]<<" "; cout<<"\n";
		// for(ll i=0;i<n;i++) cout<<L[i]<<" "; cout<<"\n";
		// for(ll i=0;i<n;i++) cout<<R[i]<<" "; cout<<"\n";
		for(ll i=0;i<n;i++){
			ll temp = (i-1>=0?L[i-1]:0);
			if(i+1<n){
				ll len = n - i - 1;
				temp += (R[i+1] - f[i]*len); 
			}	
			ans=min(ans,temp);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
