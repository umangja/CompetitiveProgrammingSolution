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
const ll N = 1e5+5;
vvi a(N,vi(31));

ll f(ll l,ll r,ll idx)
{
	if(idx==31) return 0;

	ll c0=0,c1=0;
	rep(i,l,r+1)
	{
		if(a[i][idx]==0) c0++;
		else c1++;
	}
	// cout<<l<<" "<<r<<" "<<idx<<" "<<c0<<"\n";
	ll ans=0;
	if(c0==r-l+1 || c1==r-l+1)
	{
		ll temp_ans = f(l,r,idx+1);
		ans=temp_ans;
	} 
	else
	{
		ll br=-1;
		ans = (ll)pow(2,30-idx);
		rep(i,l,r+1)  if(a[i][idx]==1) {br=i; break;}
		ll temp_ans = min(f(l,br-1,idx+1),f(br,r,idx+1));
		ans+=temp_ans;
	}
	return ans;
}

int solve()
{
	ll n;cin>>n;
	vi b(n);
	rep(i,0,n) cin>>b[i];
	sort(b.begin(), b.end());
	rep(i,0,n)
	{
		ll x=b[i];
		// whatis(x);
		vi br;
		while(x>0)
		{
			if((x%2)==0) br.pb(0);
			else br.pb(1);
			x/=2;
		} 
		while(sz(br)<31) br.pb(0);
		reverse(br.begin(), br.end());
		// rep(j,0,31) cout<<br[j]<<" ";
		// cout<<"\n";
		a[i]=br;
	} 
	cout<<f(0,n-1,0);
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