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
	ll n;cin>>n;
	vi a(n);
	map<ll,set<ll> > pos;
	set<ll> val;
	rep(i,0,n) cin>>a[i],pos[a[i]].insert(i),val.insert(a[i]),val.insert(2*a[i]);

	all(it,val)
	{
		ll v = *it;
		while(sz(pos[v])>=2)
		{
			// whatis(v);
			auto it1 = pos[v].begin();
			ll p1=*it1;it1++;
			ll p2=*it1;

			pos[v].erase(p1);
			pos[v].erase(p2);

			val.insert(2*v);

			pos[2*v].insert(p2);
		}
	}

	vi ans(n,-1);
	ll cnt=0;


	all(it,pos)
	{
		ll v = it->F;
		set<ll> st = it->S;
		all(it1,st) ans[*it1] = v;
	}


	rep(i,0,n) if(ans[i]!=-1) cnt++;
	cout<<cnt<<"\n";
	rep(i,0,n) if(ans[i]!=-1) cout<<ans[i]<<" ";

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