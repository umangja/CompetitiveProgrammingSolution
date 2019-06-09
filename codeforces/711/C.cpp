/*input
3 2 2
2 0 0
1 3
2 4
3 5


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

ll n,m,k;
vi t(101);
ll p[101][101];
const ll N = 102;
ll dp[N][N][N];

void init()
{
	rep(i,0,N)
	{
		rep(j,0,N)
		{
			rep(k,0,N)
			{
				dp[i][j][k]=1e16;
			}
		}
	}
}


int solve()
{
	init();
	cin>>n>>m>>k;
	ll f1=0;
	rep(i,0,n)
	{
		cin>>t[i];
		if(t[i]==0)
			f1=1;
	}

	rep(i,0,n)
	{
		rep(j,1,m+1)
		{
			cin>>p[i][j];
		}
	}

	if(f1==0)
	{
		ll ts=0;
		ll lc=m+2;
		rep(i,0,n)
		{
			if(t[i]!=lc)
			{
				lc=t[i];
				ts++;
			}
		}
		if(ts==k)
			cout<<"0";
		else
			cout<<"-1";
		return 0;
	}

	if(t[0]==0)
	{
		rep(i,1,m+1)
		{
			dp[0][1][i]=p[0][i];
		}
	}
	else
	{
		dp[0][1][t[0]]=0;
	}


	rep(i,1,n)
	{
		rep(s,1,k+1)
		{
			if(t[i]==0)
			{
				rep(c,1,m+1)
				{
					dp[i][s][c] = min(dp[i][s][c],dp[i-1][s][c]+p[i][c]);
					rep(c1,1,m+1)
					{
						if(c1!=c)
						{
							dp[i][s][c] = min(dp[i][s][c],dp[i-1][s-1][c1]+p[i][c]);
						}
					}
					// cout<<i<<" "<<s<<" "<<c<<" "<<dp[i][s][c]<<"\n";
				}
			}
			else
			{
				ll c = t[i];
				dp[i][s][c] = min(dp[i][s][c],dp[i-1][s][c]);
				rep(c1,1,m+1)
				{
					if(c1!=t[i])
						dp[i][s][c] = min(dp[i][s][c],dp[i-1][s-1][c1]);
				}

			}
		}
	}

	ll ans=1e16;
	rep(i,1,m+1)
		ans=min(ans,dp[n-1][k][i]);

	if(ans==1e16)
		ans=-1;
	cout<<ans;
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