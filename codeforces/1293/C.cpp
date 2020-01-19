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
	ll n,q;cin>>n>>q;
	set< pii >  blockage;
	set< ll > blockage_s;

	vector< set< ll > > col(n);
	map<pii,ll> m;
	rep(i,0,q)
	{
		ll r,c;cin>>r>>c;
		r--,c--;
		if(m[mp(r,c)]==0)
		{
			col[c].insert(r);
			if(sz(col[c])==2) blockage_s.insert(c);
			if(c+1<n && m[mp(r^1,c+1)]==1) blockage.insert(mp(r,c));
			if(c-1>=0 && m[mp(r^1,c-1)]==1) blockage.insert(mp(r^1,c-1));
		}
		else
		{
			col[c].erase(r);
			if(blockage_s.find(c)!=blockage_s.end()) blockage_s.erase(c);
			if(c+1<n && m[mp(r^1,c+1)]==1) blockage.erase(mp(r,c));
			if(c-1>=0 && m[mp(r^1,c-1)]==1) blockage.erase(mp(r^1,c-1));		
		}

		m[mp(r,c)]^=1;

		if(sz(blockage_s) || sz(blockage) || (m[mp(0,n-1)]==1 && m[mp(1,n-2)]==1	) ) cout<<"NO\n";
		else cout<<"YES\n";
	}

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