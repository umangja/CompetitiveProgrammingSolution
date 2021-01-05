/*input
4
2 1
2 2
5 1
1 3




*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool cmp(const pair<ll,ll> p1,const pair<ll,ll> p2)
{
	return 2*p1.first+p1.second>2*p2.first+p2.second;
}

int main()
{
	ll T = 1; // cin>>T;
	while(T--)
	{
		ll n;cin>>n;
		vector<pair<ll,ll>> votes(n);
		ll sumT = 0,sumA=0; 
		for(ll i=0;i<n;i++) cin>>votes[i].first>>votes[i].second,sumA+=votes[i].first;
		sort(votes.begin(),votes.end(),cmp);

		ll ans=0;
		while(sumT<=sumA)
		{
			sumT+=votes[ans].first+votes[ans].second;
			sumA-=votes[ans].first;
			ans++;
		}

		cout<<ans<<"\n";


	}
	return 0;
}
