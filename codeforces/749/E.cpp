/*input
3
2 3 1


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
const ll N = 1e5+5;
vi a;
ll ans=0;
ll bit[N];

void add(ll idx,ll val)
{
	for(;idx<N;idx+=idx&-idx)
		bit[idx]+=val;
}

ll prefix_sum(ll idx)
{
	ll s=0;
	for(;idx>0;idx-=idx&-idx)
		s+=bit[idx];
	return s;
}
void merge(ll l,ll r)
{
	ll m = l+(r-l)/2;
	vi b,c,e;
	rep(i,l,m+1)
		b.pb(a[i]);
	rep(i,m+1,r+1)
		c.pb(a[i]);

	ll i=0,j=0;
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	while(i<sz(b) && j<sz(c))
	{
		if(b[i]<c[j])
			e.pb(b[i]),i++;
		else
			e.pb(c[j]),ans+=sz(b)-i,j++;
	}
	while(i<sz(b))
		e.pb(b[i]),i++;
	while(j<sz(c))
		e.pb(c[j]),j++;

	rep(k,l,r+1)
		a[k]=e[k-l];
}

void mergesort(ll l,ll r)
{
	if(l<r)
	{
		ll mid = l+(r-l)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,r);
	}
}

int solve()
{
	ll n;cin>>n;
	vi b;
	rep(i,0,n)
	{
		ll x;cin>>x;
		a.pb(x);
		b.pb(x);
	}
	
	mergesort(0,n-1);
	double ans2=0;
	double ans4=0;
	for(ll i=n-1;i>=0;i--)
	{
		ans2+=(double)prefix_sum(b[i]-1);
		ans4+=ans2;
		add(b[i],n-i);
	}

	double sum = (double)(n*(n+1))/2;
	double ans3=0;
	rep(l,1,n+1)
		ans3+=((double)(l*(l-1)*(n-l+1)))/4;
	double ansf = (sum*(double)ans+ans3-ans4)/(sum);
	cout<<setprecision(20)<<ansf<<"\n";

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