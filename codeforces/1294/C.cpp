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
	ll dup = n;
	map<ll,ll> pf;
	for(ll i=2;i*i<=n;i++) if(n%i==0) while(n%i==0) pf[i]++,n/=i;

	if(n!=1) pf[n]++;
	
	vi ans(3);
	ll f=1;
	if(sz(pf)>=2)
	{
		ll idx=0;
		ll l = dup;
		all(it,pf)
		{
			if(idx>=2) break;
			ans[idx] = it->F;
			l/=it->F;
			idx++;
		}
		ans[2]=l;	
		all(it,pf) if(l==ans[0] || l==ans[1]) f=0; else if(l==1) f=0;
	}
	else 
	{
		auto it = *pf.begin();
		ll pr = it.F;
		ll pp = it.S;
		if(pp>=6)
		{
			ans[0] = pr;
			ans[1] = pr*pr;
			ans[2] = dup/(pr*pr*pr);
		}
		else f=0;
	}

	if(f==0) cout<<"NO\n";
	else 
	{
		cout<<"YES\n";
		rep(i,0,3) cout<<ans[i]<<" ";
		cout<<"\n";
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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}