/*input
2
50 49
2321 2298 1227 3465 748 4678 4564 4927 3070 1180 4855 1136 3238 1941 4668 4807 1115 1400 4836 1525 4004 3071 3839 1565 3408 912 1824 2191 4670 1821 3623 3881 1015 3677 350 2937 1527 1057 4277 1132 759 3399 4175 4507 3102 1571 3626 2105 3251 257
6 1
0 5 6 6 6 6
*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define is_empty(v) v.empty()
#define vs			vector< string >
#define vvi			vector< vector< ll,ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define reprr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define sum(v)      accumulate(v.begin(),v.end(),(ll)0)
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;


const ll N = 5005;
int solve()
{
	ll n,k;cin>>n>>k;
	vi a(n);
	rep(i,0,n)
		cin>>a[i];

	sort(a.begin(), a.end());
	// cout<<"YES";

	vector< vector< ll > > dp(N,vector< ll > (N,0));
	vi f(N,0);

	f[0]=-1;
	ll j=0;
	rep(i,1,n)
	{
		while(a[i]-a[j]>5)
			j++;

		if(a[i]-a[j]<=5)
		{
			f[i]=j-1;
		}

	}



	rep(i,0,n)
	{
		rep(j,0,k+1)
		{
			if(j==0)
				dp[i][j]=0;
			else if(i==0)
				dp[i][j]=1;
			else
			{
				dp[i][j] = dp[i-1][j];
				if(f[i]!=-1)
					dp[i][j] = max(dp[f[i]][j-1]+i-f[i],dp[i][j]);
				else
					dp[i][j] = max(dp[i][j],dp[i-1][j]+1);
			}
		}
	}

	cout<<dp[n-1][k];
	// cout<<"\n";
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	// cin>>t;
	while(t--)
		solve();
}