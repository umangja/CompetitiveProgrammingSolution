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
const ll N  = 5e5+5;
vi bit(N,0);

void add(ll idx,ll val)
{
	for(ll i=idx+1;i<N;i+=(i&-i)) bit[i]+=val;
	return ;
}

ll prefix_sum(ll idx)
{
	ll ans=0;
	for(ll i=idx+1;i>0;i-=(i&-i)) ans+=bit[i];
	return ans;
}

ll sum(ll l,ll r)
{
	if(l>r) return 0;
	return prefix_sum(r) - prefix_sum(l-1);
}

int solve()
{
	ll n,k,d;cin>>n>>k>>d;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	sort(a.begin(), a.end());

	if(k==1) 
	{
		cout<<"YES\n";
		return 0;
	}

	vi dp(n,0);
	vpii pos;
	rep(i,0,n)
	{
		if(i==0) dp[i] = (k==1);
		else
		{	
			ll val = a[i]-d;
			ll idx = lower_bound(pos.begin(), pos.end(),mp(val,-inf))-pos.begin();

			if(idx==sz(pos)) dp[i]=0;
			else
			{
				ll l = pos[idx].S-1;
				ll r = i-k;

				// whatis(l);
				// rep(j,0,n) cout<<sum(j,j)<<" ";
				// cout<<"\n";

				ll s = sum(l,r);
				if(l!=-1 && s!=0) dp[i]=1;
				else if(l==-1 && i+1>=k) dp[i]=1; 
				else dp[i]=0;
			}
		}
		pos.pb(mp(a[i],i));
		if(dp[i]==1) add(i,1);
		// cout<<dp[i]<<"\n";
	}
	cout<<(dp[n-1]==1?"YES":"NO");
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
