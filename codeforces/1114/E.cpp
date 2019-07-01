/*input

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vppi        vector< pii >
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int solve()
{
	ll n,ans;cin>>n;
	ll low = 0,high = 1e9;
	ll q_max=60;
	while(low<high)
	{
		ll mid = low+(high-low)/2;
		cout<<"> "<<mid<<"\n";
		cout.flush();
		cin>>ans;
		if(ans)
			low=mid+1;
		else
			high=mid;

		q_max--;			
	}

	vi a;
	map< ll,ll > m;
	q_max = min(q_max,n);
	q_max;
	while(q_max)
	{
		ll i = (rng()%n)+1;
		while(m[i]==1)
			i=rng()%n+1;
		m[i]=1;
		cout<<"? "<<i<<"\n";
		cout.flush();
		cin>>ans;a.pb(ans);
		q_max--;
	}
	sort(a.begin(), a.end());
	if(a[sz(a)-1]!=low)
		a.pb(low);

	ll d = 0;
	rep(i,1,sz(a))
		d = __gcd(d,a[i]-a[i-1]);

	cout<<"! "<<low-(n-1)*d<<" "<<d<<"\n";
	cout.flush();
	return 0;
}

int main()
{
	ll t=1;
	while(t--)
		solve();
}