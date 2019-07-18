/*input
3 4 2 1
1 2 3 59

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
const ll N = 3005;
ll mat[N][N];
ll n,m,a,b,x,y,z,G0;
vvi ans;

void preprocess()
{
	ll last=G0;
	rep(i,0,n) rep(j,0,m) mat[i][j]=last,last = (x*last+y)%z;
}


void build()
{
	vvi col_min(n,vi ());
	ans.assign(n-a+1,vi(m-b+1,0));
	rep(i,0,n)
	{
		deque< ll > q;
		for(ll j=0;j<b;j++)
		{
			while(!q.empty() && mat[i][j]<=mat[i][q.back()])
				q.pop_back();
			q.push_back(j);
		}

		for(ll j=b;j<m;j++)
		{
			col_min[i].pb(mat[i][q.front()]);
			while(!q.empty() && q.front()<j-b+1)
				q.pop_front();
			while(!q.empty() && mat[i][j]<=mat[i][q.back()])
				q.pop_back();
			q.push_back(j);
		}
		col_min[i].pb(mat[i][q.front()]);
	}

	rep(j,0,m-b+1)
	{
		deque< ll > q;
		rep(i,0,a)
		{
			while(!q.empty() && col_min[i][j]<=col_min[q.back()][j])
				q.pop_back();
			q.push_back(i);
		}

		ans[a-1-a+1][j]=col_min[q.front()][j];
		rep(i,a,n)
		{
			while(!q.empty() && q.front()<i-a+1)
				q.pop_front();
			while(!q.empty() && col_min[i][j]<=col_min[q.back()][j])
				q.pop_back();
			q.push_back(i);
			ans[i-a+1][j]=col_min[q.front()][j];
		}
	}

}

int solve()
{
	cin>>n>>m>>a>>b>>G0>>x>>y>>z;
	preprocess();
	build();

	ll ansf=0;
	rep(i,0,n-a+1)
		rep(j,0,m-b+1)
			ansf+=ans[i][j];
	cout<<ansf<<"\n";
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