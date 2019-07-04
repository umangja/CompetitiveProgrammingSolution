/*input
6 20
9 10
0 1
7 9
3 7
8 10
5 8
5 9
4 5
7 8
8 9
0 8
1 4
4 6
6 9
4 7
6 7
7 9
7 10
4 8
7 9
3 4
7 10
7 9
5 8
4 10
4 6
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
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N  =5e5+5;
ll n,m,L;
vpii v,q;
vi idx(N);

int solve()
{
	cin>>n>>m;
	L=(ll)ceil(log2(N));
	ll x,y;

	vvi up(N,vector< ll > (L,-1));

	rep(i,0,n)
	{
		cin>>x>>y;
		v.pb(mp(x,y));
	}

	rep(i,0,m)
	{
		cin>>x>>y;
		q.pb(mp(x,y));
	}

	sort(v.begin(), v.end());

	ll las=0;
	pii mx(0,-1);
	rep(i,0,N)
	{
		while(las<n && v[las].F==i)
		{
			mx=max(mx,mp(v[las].S,las));
			las++;
		}

		idx[i]=(mx.F<=i?-1:mx.S);
	}

	rep(i,0,N)
		up[i][0]=(idx[i]==-1?i:v[idx[i]].S);


	rep(j,1,L)
		rep(i,0,N)
			up[i][j]=up[up[i][j-1]][j-1];

	rep(k,0,m)
	{
		ll l=q[k].F,r=q[k].S;
		ll ans=0;
		if(up[l][0]==-1)
		{
			cout<<"-1\n";
			continue;
		}
		// cout<<up[l][0]<<" ";
		for(ll i=L-1;i>=0;i--)
		{
			if( up[l][i]!=-1 && up[l][i]<r)
			{
				ans+=(1<<i);
				l=up[l][i];
			}
		}

		if(l<r)
		{
			if(up[l][0]!=-1 && up[l][0]>=r)
				ans++;
			else
				ans=-1;
		}
		cout<<ans<<"\n";
	}

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}