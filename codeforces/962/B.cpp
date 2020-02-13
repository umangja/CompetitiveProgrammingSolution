/*input

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve()
{
	ll n,a,b1;cin>>n>>a>>b1;
	string st;cin>>st;
	st='*'+st;st+='*';
	n+=2;

	vi gap;
	rep(i,0,n)
	{
		if(st[i]=='*')
		{
			ll j=i+1;
			while(j<n && st[j]=='.') j++;
			ll val  = j-i-1;
			if(val>0) gap.pb(val);
			i=j-1;
		}
	}

	n=sz(gap);
	ll ans=0;
	sort(gap.begin(), gap.end(),greater<ll> ());
	rep(i,0,n)
	{
		// if(a==0 && b==0) break;

		ll b = max(a,b1);
		ll s = min(a,b1);
		ll g = gap[i];
		ll t = min((g+1)/2,b);
		b-=t;
		ans+=t;
		t=min(g/2,s);
		s-=t;
		ans+=t;

		a=s,b1=b;
		// if(a==0 && b==0) break;
		// cout<<a<<" "<<b<<"\n";
		assert(a>=0 && b1>=0);
	}

	cout<<ans<<"\n";

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}