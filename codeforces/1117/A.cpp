/*input
1
6 1 6 6 0

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )

int solve()
{
	ll n;cin>>n; 
	vi a(n);
	rep(i,0,n)
		cin>>a[i];

	ll ap = *max_element(a.begin(), a.end());

	ll ans=0,l=0;
	rep(i,0,n)
	{
		if(a[i]==ap)
		{
			ll j=i;
			while(j<n && a[j]==ap)
				j++;
			ans=max(ans,j-i);
			i=j-1;
		}
	}
	cout<<ans;
	return 0;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}