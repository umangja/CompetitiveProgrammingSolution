/*input
2
aa
a
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
const ll N = 30;
ll in_deg[N];
ll vis[N];
vvi graph(N);

int solve()
{
	ll n;cin>>n;
	set<ll> ver;
	string last;cin>>last;
	rep(i,0,n-1)
	{
		string cur;cin>>cur;
		ll j=0;
		while(j<min(sz(last),sz(cur)) && last[j]==cur[j]) j++;
		if(j<min(sz(last),sz(cur))) adj[last[j]-'a'].pb(cur[j]-'a'),in_deg[cur[j]-'a']++,ver.insert(cur[j]-'a'),ver.insert(last[j]-'a');
		else if(sz(cur)<sz(last))
		{
			cout<<"Impossible\n";
			return 0;
		}
		last=cur;
	}

	priority_queue<ll,vi,greater<ll> > q;
	rep(i,0,26) if( ver.find(i)!=ver.end() && in_deg[i]==0) q.push(i),vis[i]=1;

	vi ans;
	while(!q.empty())
	{
		ll v = q.top();q.pop();
		ans.pb(v);
		rep(i,0,sz(adj[v])) if(vis[adj[v][i]]==0) if(--in_deg[adj[v][i]]==0) vis[adj[v][i]]=1,q.push(adj[v][i]);
	}

	string r="";
	if(sz(ans)==sz(ver))
	{
		rep(i,0,26) ver.insert(i);
		rep(i,0,sz(ans)) r+=(char)(ans[i]+'a'),ver.erase(ans[i]);
		all(it,ver) r+=(char)(*it+'a');
	}
	else r = "Impossible\n";
	cout<<r;


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