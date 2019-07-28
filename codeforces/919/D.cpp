/*input
10 14
xzyzyzyzqx
1 2
2 4
3 5
4 5
2 6
6 8
6 5
2 10
3 9
10 9
4 6
1 10
2 8
3 7

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
const ll N = 3e5+5;
ll in_deg[N];
ll dp[N][26];
ll vis[N];
vvi graph(N);
set<pii> alr;

int solve()
{
ll n,m;cin>>n>>m;
string s;cin>>s;

rep(i,0,m)
{
	ll x,y;cin>>x>>y;
	x--,y--;
	if(alr.find(mp(x,y))==alr.end())
	{
		adj[x].pb(y);
		in_deg[y]++;
	}
}

queue<ll> q;
rep(i,0,n) if(in_deg[i]==0) q.push(i),vis[i]=1,dp[i][s[i]-'a']++;

vi ans;
while(!q.empty())
{
	ll v = q.front();q.pop();
	ans.pb(v);
	rep(i,0,sz(adj[v])) if(vis[adj[v][i]]==0) {
	rep(j,0,26) dp[adj[v][i]][j]=max(dp[v][j]+((s[adj[v][i]]-'a')==j),dp[adj[v][i]][j]);
	if(--in_deg[adj[v][i]]==0) vis[adj[v][i]]=1,q.push(adj[v][i]);
	}
}

ll cnt=0;
if(sz(ans)==n)
{
	rep(i,0,n)
	rep(j,0,26)
	cnt=max(cnt,dp[i][j]);
}
else cnt=-1;
cout<<cnt;


return 0;
}

int main()
{
auto start = chrono::high_resolution_clock::now();

// ios_base::sync_with_stdio(false);
// cin.tie(0);
// cout.tie(0);

ll test_cases=1;
//cin>>test_cases;
while(test_cases--)
	solve();

auto stop = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}