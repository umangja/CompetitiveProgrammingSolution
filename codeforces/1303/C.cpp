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

ll n;
const ll N = 205;
vector< set<ll> > adj(N);
ll is_cycle =0 ;
vi vis(N,0);
string ans;

void dfs(ll u,ll p)
{
	vis[u]=1;
	ans+=(char)(u+'a');
	all(it,adj[u])
	{
		ll ch = *it;
		if(ch!=p && vis[ch]==1) is_cycle=1;
		if(vis[ch]==0) dfs(ch,u);
	}
	return ;
}

int solve()
{
	rep(i,0,26) adj[i].clear();
	rep(i,0,26) vis[i]=0;
	ans="";
	is_cycle = 0;
	string s;cin>>s;
	n=sz(s);

	ll st=s[0]-'a';
	rep(i,0,n-1) 
	{
		adj[s[i]-'a'].insert(s[i+1]-'a');
		adj[s[i+1]-'a'].insert(s[i]-'a');
	}

	rep(i,0,26) if(sz(adj[i])>=3) is_cycle=1;

	rep(i,0,26) if(sz(adj[i])==1) st = i;
	dfs(st,-1);
	rep(i,0,26) if(!vis[i]) ans+=(char)(i+'a');
	if(is_cycle) cout<<"NO\n";
	else cout<<"YES\n"<<ans<<"\n";
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