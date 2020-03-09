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

const ll N = 2e5+5;
vvi graph(N);
vi col(N,-1);
void dfs(ll u,ll p)
{
	rep(i,0,sz(adj[u]))
	{
		ll ch = adj[u][i];
		if(ch==p) continue;
		col[ch]=col[u]^1;
		dfs(ch,u);
	}
	return ;
}

int solve()
{
	ll n;cin>>n;
	rep(i,0,n-1)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	col[0]=0;
	dfs(0,-1);

	// rep(i,0,n) cout<<col[i]<<" ";
	// cout<<"\n";

	ll a=0,b=0;
	rep(i,0,n) if(col[i]==0) a++; else b++;

	ll f=0;
	if(a>b)
	{
		swap(a,b);
		f=1;
	}
	vi ans(n,-1);
	set<ll> nu;
	rep(i,1,n+1) nu.insert(i);
	if(a<=n/3)
	{
		ll cnt=1;
		rep(i,0,n) if(col[i]==f) ans[i]=3*(cnt++),nu.erase(ans[i]);
		rep(i,0,n) if(ans[i]==-1) ans[i] = *nu.begin() , nu.erase(ans[i]);
	}
	else
	{
		// cout<<1<<"\n";
		ll cnt1=0,cnt2=0,cnt=1;
		rep(i,0,n)
		{
			if(col[i]==f)
			{
				if(3*(cnt1)+1<=n) ans[i]=3*(cnt1++)+1;
				else ans[i] = 3*cnt++;

			} 
			else
			{
				if(3*(cnt2)+2<=n) ans[i]=3*(cnt2++)+2;
				else ans[i] = 3*cnt++;	
			} 
			nu.erase(ans[i]);
		} 
	}

	rep(i,0,n) cout<<ans[i]<<" ";





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