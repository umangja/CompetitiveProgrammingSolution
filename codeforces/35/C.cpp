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
ll n,m,k;
const ll N = 2005;

vvi tree(N,vi (N,0));
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

int solve()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	cin>>n>>m>>k;
	queue< pair<ll,ll> > q;
	rep(i,0,k)
	{
		ll x,y;cin>>x>>y;
		tree[x][y]=1;
		q.push(mp(x,y));
	}

	pii ans = mp(-1,-1);
	while(sz(q))
	{
		pii p = q.front();
		ans=p;
		q.pop();
		rep(i,0,4)
		{
			if(p.F+dx[i]>=1 && p.F+dx[i]<=n && p.S+dy[i]>=1 && p.S+dy[i]<=m && tree[p.F+dx[i]][p.S+dy[i]]==0)
			{
				tree[p.F+dx[i]][p.S+dy[i]]=1;
				q.push(mp(p.F+dx[i],p.S+dy[i]));
			}
		}

	}	
	cout<<ans.F<<" "<<ans.S<<"\n";
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