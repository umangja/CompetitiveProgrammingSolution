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

ll dp[101][2][51][51];

int solve()
{
	ll n;cin>>n;
	set<ll> left;
	vi a(n);
	rep(i,0,n)
	{
		left.insert(i+1);
		cin>>a[i];
	}

	rep(i,0,n) left.erase(a[i]);
	ll e=0,o=0;
	all(it,left) 
	{
		if((*it)%2==0) e++;
		else o++;
	}

	rep(i,0,101) rep(j,0,2) rep(k,0,51) rep(k2,0,51) dp[i][j][k][k2]=inf;

	// whatis(o);
	// whatis(e);

	// memset(dp,-1,sizeof dp);
	rep(i,0,n)
	{
		rep(j,0,2)
		{
			rep(oc,0,o+1)
			{
				rep(ec,0,e+1)
				{

					if(oc+ec>(i+1)) break;

					if(i==0)
					{
						if(a[i]!=0) dp[i][j][oc][ec]=((a[i]%2)!=j?inf:0);
						else
						{
							if(j==0 && ec==0) dp[i][j][oc][ec]=inf;
							else dp[i][j][oc][ec]=0;

							if(j==1 && oc==0) dp[i][j][oc][ec]=inf;
							else dp[i][j][oc][ec]=0;
						} 
						continue;
					}

					if(a[i]!=0)
					{
						if(j!=(a[i]%2)) dp[i][j][oc][ec]=inf;
						else dp[i][j][oc][ec]=min(dp[i-1][0][oc][ec]+(j!=0),dp[i-1][1][oc][ec]+(j!=1));
						continue;
					}

					// dp[i][j][oc][ec]=min((ec>=1?dp[i-1][0][oc][ec]:inf),(oc>=1?dp[i-1][1][oc][ec]:inf));

					if(j==0 && ec==0) dp[i][j][oc][ec]=inf;
					else if(j==0) dp[i][j][oc][ec]=min(dp[i-1][0][oc][ec-1],dp[i-1][1][oc][ec-1]+1);
					else if(j==1 && oc==0) dp[i][j][oc][ec]=inf;
					else dp[i][j][oc][ec]=min(dp[i-1][0][oc-1][ec]+1,dp[i-1][1][oc-1][ec]);
					
					// cout<<i+1<<" "<<j<<" "<<oc<<" "<<ec<<" "<<dp[i][j][oc][ec]<<"\n";
				}

			}
		}
	}
	// whatis(min(dp[n-1][0][o][e],dp[n-1][1][o][e]));
	cout<<min(dp[n-1][0][o][e],dp[n-1][1][o][e]);

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