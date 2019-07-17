/*input
4
1 2 1
1 3 3
4 6 2
5 7 1


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

// idx-a[i] and val =h[i];
const ll N = 3e5+5;
ll bit[N];
void add(ll idx,ll val)
{
	for(;idx<N;idx+=idx&-idx)
		bit[idx] = max(bit[idx],val);
}

ll prefix_sum(ll idx)
{
	ll s=-1;
	for(;idx>0;idx-=idx&-idx)
		s=max(s,bit[idx]);
	return s;
}


int solve()
{
	ll n;cin>>n;
	vi a(n),b(n),h(n);
	rep(i,0,n)
		cin>>a[i]>>b[i]>>h[i];
	
	vi data;
	rep(i,0,n) data.pb(a[i]),data.pb(b[i]);
	sort(data.begin(), data.end());
	data.erase(unique(data.begin(), data.end()),data.end());
	rep(i,0,n)
		a[i]=lbnd(data.begin(), data.end(),a[i])-data.begin()+1,
		b[i]=lbnd(data.begin(), data.end(),b[i])-data.begin()+1;


	vector< pair< ll,pii > > val(n);
	rep(i,0,n)
		val[i]=mp(b[i],mp(a[i],h[i]));
	sort(val.begin(), val.end(),greater< pair< ll,pii > > ());


	ll ans=0;
	rep(i,0,n)
	{
		ans = max(ans,prefix_sum(val[i].F-1)+val[i].S.S);
		add(val[i].S.F,prefix_sum(val[i].F-1)+val[i].S.S);
		// cout<<val[i].S.F<<" "<<val[i].F<<" "<<val[i].S.S<<" "<<ans<<"\n";
		// cout<<prefix_sum(5)<<"\n";
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

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}