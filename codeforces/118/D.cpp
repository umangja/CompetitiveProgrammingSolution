/*input
2 4 1 1
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

ll n1,n2,k1,k2;
ll mod=1e8;
ll dp[101][101][2];

void init()
{
	rep(i,0,101)
	{
		rep(j,0,101)
		{
			rep(k,0,2)
			{
				dp[i][j][k]=-1;
			}
		}
	}
}

ll fun(ll i,ll j,ll k)
{
	// cout<<i<<" "<<j<<" "<<k<<"\n";
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];

	if((i+j)==0)
	{
		dp[i][j][k]=1%mod;
		// cout<<"YES";
		return 1%mod;
	}

	ll ans=0;
	if(k)
	{
		rep(c,1,min(k2,j)+1)
		{
			ans=(ans+fun(i,j-c,1-k)%mod)%mod;
		}
	}
	else
	{
		rep(c,1,min(k1,i)+1)
		{
			ans=(ans+fun(i-c,j,1-k)%mod)%mod;
			
		}
	}

	dp[i][j][k]=ans%mod;
	// cout<<ans;
	return ans%mod;

}

int solve()
{
	init();
	cin>>n1>>n2>>k1>>k2;
	cout<<(fun(n1,n2,0)+fun(n1,n2,1))%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}