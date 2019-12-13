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
const ll N  =201;
ll n;
vi comp(N);
vvi previ(N,vi ());
set<ll> completed;
ll temp_ans=0;
vvi pending(3,vi ());
void  dfs(ll cur)
{
	// whatis(cur);
	// rep(i,0,3) cout<<i<<" "<<sz(pending[i])<<"\n";

	if(sz(completed)==n) return;

	rep(i,0,sz(pending[cur])) completed.insert(pending[cur][i]);
	pending[cur].clear();
	rep(j,0,n)
	{
		ll f=1;
		rep(k,0,sz(previ[j])) if(completed.find(previ[j][k])==completed.end()) {f=0; break;}
		if(f && find(pending[comp[j]].begin(),pending[comp[j]].end(),j)==pending[comp[j]].end() && completed.find(j)==completed.end()) pending[comp[j]].pb(j);
	}
	// rep(i,0,3) cout<<i<<" "<<sz(pending[i])<<"\n";

	if(sz(completed)==n) return;

	if(sz(pending[cur])!=0) dfs(cur);
	else temp_ans++,dfs((cur+1)%3);
	return ;
}

int solve()
{
	cin>>n;
	rep(i,0,n) cin>>comp[i],comp[i]--;
	rep(i,0,n)
	{
		ll k;cin>>k;
		while(k--)
		{
			ll x;cin>>x;
			x--;
			previ[i].pb(x);
		}
	}

	ll ans=inf;
	rep(i,0,3)
	{
		temp_ans=0;
		completed.clear();
		rep(j,0,n)
		{
			ll f=1;
			rep(k,0,sz(previ[j])) if(completed.find(previ[j][k])==completed.end()) {f=0; break;}
			if(f && find(pending[comp[j]].begin(),pending[comp[j]].end(),j)==pending[comp[j]].end() ) pending[comp[j]].pb(j);
		}
		dfs(i);
		ans=min(ans,temp_ans);
	}

	cout<<ans+n<<"\n";
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