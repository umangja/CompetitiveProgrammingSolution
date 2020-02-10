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


int solve()
{
	ll n,m,k;cin>>n>>m>>k;
	vi bl(n,0);
	vi b;
	rep(i,0,m) {
		ll x;cin>>x;
		// b[i]=x;
		bl[x]=1;
	}

	rep(i,0,n) if(bl[i]==0) b.pb(i);

	vi cost(k);
	rep(i,0,k) cin>>cost[i];

	ll mn = inf;
	ll last=-1;
	rep(i,1,k+1)
	{
		ll ans = 0;
		ll f=0;
		for(ll j=0;j<n;j+=i)
		{
			if(bl[j]==1)
			{
				ll idx = lower_bound(b.begin(), b.end(),j) - b.begin();
				idx--;
				if(idx==-1)
				{
					ans=inf;
					f=1;
					break;
				}
				else j=b[idx];

				if(j==last)
				{
					f=1;
					break;
				}
			}
			// whatis(j);
			last=j;
			if(f) break;
			ans++;
		}
		// whatis(ans);
		// whatis(f);
		if(ans<inf && f==0) mn=min(mn,ans*cost[i-1]);
	}

	if(mn>=inf) mn=-1;
	cout<<mn<<"\n";
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