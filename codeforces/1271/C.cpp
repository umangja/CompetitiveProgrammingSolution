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
pii s;
const ll N = 2e5+5;
vpii houses(N);

int solve()
{
	cin>>n>>s.F>>s.S;
	rep(i,0,n)
	{
		ll x,y;
		cin>>x>>y;
		x-=s.F;
		y-=s.S;
		houses[i]=mp(x,y);
	}

	ll dx[] = {-1,0,1,0};
	ll dy[] = {0,-1,0,1};
	ll ansf=-1;
	pii p=mp(0,0);
	rep(j,0,4)
	{
		ll x = dx[j];
		ll y = dy[j];

		ll ans=0;
		rep(i,0,n)
		{
			if(j==0 && houses[i].F<=x) ans++;
			else if(j==1 && houses[i].S<=y) ans++;
			else if(j==2 && houses[i].F>=x) ans++;
			else if(j==3 && houses[i].S>=y) ans++;

		} 
		if(ans>ansf)
		{
			ansf=ans;
			p = mp(x+s.F,y+s.S);
		} 
	}

	cout<<ansf<<"\n";
	cout<<p.F<<" "<<p.S<<"\n";


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