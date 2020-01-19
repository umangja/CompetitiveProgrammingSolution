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

bool cmp(pii a,pii b)
{
	if(a.F==b.F) return a.S>b.S;
	return  a.F<b.F;
}

int solve()
{
	ll n;cin>>n;
	vpii a(n),b(n);
	rep(i,0,n)
	{
		ll x,l;cin>>x>>l;
		a[i].F = x-l;
		a[i].S = x+l;
		b[i].F = a[i].S;
		b[i].S = a[i].F;
	} 
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(),cmp);

	vi larg_l(n);
	rep(i,0,n)
	{
		if(i==0) larg_l[0]=0;
		else 
		{
			if(b[i].S>=b[larg_l[i-1]].S) larg_l[i] = i;
			else larg_l[i] = larg_l[i-1];
		}
	}

	// rep(i,0,n) cout<<b[i].F<<" "<<b[i].S<<"\n";
	// rep(i,0,n) cout<<a[i].F<<" "<<a[i].S<<"\n";


	vvi dp(n,vi (2,-1));
	rep(i,0,n)
	{
		rep(j,0,2)
		{
			if(i==0) dp[i][j]=j;
			else
			{
				if(j==0) dp[i][j] = max(dp[i-1][0],dp[i-1][1]);
				else 
				{
					ll val = a[i].F;
					ll idx = upper_bound(b.begin(), b.end(),mp(val,inf))-b.begin();
					idx--;
					if(idx!=-1)
					{
						idx  = larg_l[idx]; 
						// whatis(i);
						// whatis(idx);
						idx = lower_bound(a.begin(), a.end(),mp(b[idx].S,b[idx].F))-a.begin();
						dp[i][j] = max(dp[idx][1],dp[idx][0])+1;
					} 
					else dp[i][j]=1;
				}
			}

		}
	}

	// rep(i,0,n) cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	cout<<max(dp[n-1][0],dp[n-1][1]);

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
