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

vpii pnts;
ll x,y,ax,ay,bx,by,xs,ys,n;

ll dist(pii a,pii b)
{
	return abs(a.F-b.F)+abs(a.S-b.S);
} 

ll fun(ll i,ll j)
{
	if(pnts[i].F>pnts[j].F) swap(i,j);
	ll temp_ans=0;
	rep(k,0,n)
	{
		if(pnts[k].F>=pnts[i].F && pnts[k].F<=pnts[j].F)
		{
			if(pnts[i].S<pnts[j].S)
			{
				if(pnts[k].S>=pnts[i].S && pnts[k].S<=pnts[j].S) temp_ans++;
			}
			else
			{
				if(pnts[k].S>=pnts[j].S && pnts[k].S<=pnts[i].S) temp_ans++;
			}
		}
	}

	return temp_ans;
}

int solve()
{
	cin>>x>>y>>ax>>ay>>bx>>by;
	cin>>xs>>ys;
	ll t;cin>>t;
	pnts.pb(mp(x,y));
	n = (ll)((log(1e17) - log(x))/log(ax));
	n = min(n,(ll)((log(1e17) - log(y))/log(ay)));
	// whatis(n);
	rep(i,0,n)
	{
		x*=ax;
		x+=bx;
		y*=ay;
		y+=by;
		pnts.pb(mp(x,y));
	}
	n++;
	ll ans = 0;
	rep(i,0,n)
	{
		ll t_left = t - dist(mp(xs,ys),pnts[i]);
		if(t_left<0) continue;
		// whatis(t_left);
		// whatis(dist(mp(xs,ys),pnts[i]));
		rep(j,0,n)
		{
			if(dist(pnts[i],pnts[j])<=t_left)
			{
				// cout<<"ok";
				ans=max(ans,fun(i,j));
			} 
		}
	}

	cout<<ans<<"\n";
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