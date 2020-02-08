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
vi tot(N);
ll mx=0;
void fun(ll nn)
{
	nn++;
	tot[1]=1;
	rep(j,2,nn)
	{
		map<ll,ll> pf;
		ll n=j;
		for(ll i=2;i*i<=n;i++) while(n%i==0) pf[i]++,n/=i;
		if(n>1) pf[n]++;
		tot[j] = j;
		all(it,pf) tot[j] = (tot[j]*(it->F-1))/it->F;
		mx+=tot[j];
	}
	return ;
}

vvi adj(N,vi ());
int solve()
{
	ll n,m;cin>>n>>m;
	fun(n);
	if(m<(n-1) || m>mx) {cout<<"Impossible\n"; return 0;}
	cout<<"Possible\n";
	rep(i,2,n+1) adj[1].pb(i),m--;
	ll cur = 3;
	while(m)
	{
		rep(i,2,cur) if(__gcd(i,cur)==1 && m) { m--; adj[cur].pb(i); } 
		cur++;
	} 

	rep(i,1,n+1) rep(j,0,sz(adj[i])) cout<<i<<" "<<adj[i][j]<<"\n"; 


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