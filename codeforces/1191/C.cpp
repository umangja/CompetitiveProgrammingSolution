/*input
13 4 5
7 8 9 10


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
#define inf			1e18
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

ll n,m,k;
vi a;

ll bsf(ll st,ll d,ll gn)
{
	ll low = st,high = m-1;
	while(low<high)
	{
		ll mid = low+(high-low+1)/2;
		if((a[mid]-d-1)/k==gn)
			low=mid;
		else
			high=mid-1;
	}

	return low+1;
}

int solve()
{
	cin>>n>>m>>k;
	rep(i,0,m)
	{
		ll x;cin>>x;
		a.pb(x);
	}

	vi pf(m);
	rep(i,0,m)
		pf[i]=(i==0?0:pf[i-1])+pf[i];

	ll st=0;
	ll ans=0;
	while(st<m)
	{
		ll gn = (a[st]-st-1)/k;
		ans++;
		ll max_idx = bsf(st,st,gn);
		// whatis(gn);
		// whatis(max_idx);
		if(max_idx>=m)
			break;
		st=max_idx;
		
	}

	cout<<ans;

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}