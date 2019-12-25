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

const ll N = 3e5+5;
vector< vector< pii > > adj(N,vpii ());
map<pii,ll> idx;
vi dis(N,inf);
vi parent(N,-1);
ll n,m,k;
vi ans;

void dikstra()
{
	set< pii > st;
	dis[0]=0;
	st.insert(mp(0,0));

	while(sz(st)>0 && k)
	{
		pii cur = *st.begin();
		st.erase(st.begin());

		// whatis(cur.S);
		if(parent[cur.S]!=-1)
		{
			ans.pb(idx[mp(cur.S,parent[cur.S])]);
			k--;
		}

		rep(i,0,sz(adj[cur.S]))
		{
			pii ch = adj[cur.S][i];
			// whatis(dis[cur.S]+ch.S);
			if(dis[cur.S]+ch.S<dis[ch.F])
			{
				st.erase(mp(dis[ch.F],ch.F));
				dis[ch.F]=dis[cur.S]+ch.S;
				parent[ch.F]=cur.S;
				// if(ch.F==2) whatis(parent[ch.F]);
				st.insert(mp(dis[ch.F],ch.F));
			}
		}
	}
}

int solve()
{
	cin>>n>>m>>k;
	rep(i,0,m)
	{
		ll x,y,w;cin>>x>>y>>w;
		x--,y--;
		adj[x].pb(mp(y,w));
		adj[y].pb(mp(x,w));

		idx[mp(x,y)]=i+1;
		idx[mp(y,x)]=i+1;

	}

	dikstra();

	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i]<<" ";
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