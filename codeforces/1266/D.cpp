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
const ll N = 1e5+5,M=3e5+5;
ll n,m;

int solve()
{
	cin>>n>>m;
	vpii a(n);
	rep(i,0,n) a[i]=mp(0,i);
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		ll d;cin>>d;
		a[x].F+=d;
		a[y].F-=d;
	}

	sort(a.begin(), a.end());
	// rep(i,0,n) cout<<a[i].F<<" "<<a[i].S<<"\n";


	vector< pair< pii,ll > > ans;
	ll i=0,j=n-1;
	while(i<j)
	{
		if(a[i].F<0)
		{
			while(a[i].F<0)
			{
				if(j<=i) break;
				ll t = min(a[j].F,abs(a[i].F));
				a[j].F-=t;
				a[i].F+=t;
				ans.pb(mp(mp(a[j].S+1,a[i].S+1),t));
				if(a[j].F==0) j--;
			}
		}
		i++;	
	}

	cout<<sz(ans)<<"\n";
	for(i=0;i<sz(ans);i++) cout<<ans[i].F.F<<" "<<ans[i].F.S<<" "<<ans[i].S<<"\n";

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