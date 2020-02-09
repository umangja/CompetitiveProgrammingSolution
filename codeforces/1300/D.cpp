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
const ll N = 1e5+5;
vpii p(N);

ll dist(ll i,ll j)
{
	return (p[i].F-p[j].F)*(p[i].F-p[j].F) + (p[i].S-p[j].S)*(p[i].S-p[j].S);
}

int solve()
{
	ll n;cin>>n;
	rep(i,0,n) cin>>p[i].F>>p[i].S;
	rep(i,1,n) p[i].F-=p[0].F,p[i].S-=p[0].S;
	p[0] = mp(0,0);
	if(n%2==0)
	{
		rep(i,0,n)
		{
			ll j = (i+n/2)%n;
			pair<ll,ll> m1 = mp(p[(i+1)%n].S - p[i].S,p[(i+1)%n].F - p[i].F);
			pair<ll,ll> m2 = mp(p[(j+1)%n].S - p[j].S,p[(j+1)%n].F - p[j].F);

			ll d1 = dist(i,(i+1)%n);
			ll d2 = dist(j,(j+1)%n);


			ll g = __gcd(m1.F,m1.S);
			m1.F/=g,m1.S/=g;

			g =  __gcd(m2.F,m2.S);
			m2.F/=g,m2.S/=g;

			if(m1!=m2 || d1!=d2)
			{
				cout<<"NO\n";
				return 0;
			}
		}

		cout<<"YES\n";

	} 
	else cout<<"NO\n";

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