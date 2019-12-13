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
const ll  N = 1e5+5,M=1e7+7;
vi spf(M);
map<ll,ll> tot;
vi a(N,1),b(N,1);
vvi ans(2,vi ());
void seive()
{
	spf[0]=spf[1]=1;
	rep(i,0,M) spf[i]=i;
	rep(i,2,M) if(spf[i]==i) for(ll j=i*i;j<M;j+=i) if(spf[j]==j) spf[j]=i;
	return ;
}

void fact(ll n,ll w,ll t)
{
	map<ll,ll> pf;
	while(n>1)
	{
		pf[spf[n]]++;
		if(t) tot[spf[n]]+=w;
		n/=spf[n];
	}

	if(t) return ;

	ll temp_ans=1;
	all(it,pf)
	{
		ll p = it->F;
		ll f = it->S;

		ll cnt=max((ll)0,min(tot[p]*w,f));
		temp_ans*=(ll)pow(p,cnt),tot[p]-=cnt*w;
	}

	if(!t)
	{
		if(w==1) ans[0].pb(temp_ans);
		else ans[1].pb(temp_ans);
	}

	return ;
}

int solve()
{
	seive();
	ll n,m;
	cin>>n>>m;
	
	rep(i,0,n) cin>>a[i];
	rep(i,0,m) cin>>b[i];
	rep(i,0,n) fact(a[i],1,1);
	rep(i,0,m) fact(b[i],-1,1);

	rep(i,0,n) fact(a[i],1,0);
	rep(i,0,m) fact(b[i],-1,0);

	cout<<sz(ans[0])<<" "<<sz(ans[1])<<"\n";
	rep(i,0,sz(ans[0])) cout<<ans[0][i]<<" ";
	cout<<"\n";
	rep(i,0,sz(ans[1])) cout<<ans[1][i]<<" ";
	cout<<"\n";
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