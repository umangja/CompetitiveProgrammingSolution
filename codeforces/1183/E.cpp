/*input
5 7
aaaaa
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

ll n,k;string s;
ll dp[102][102],f[102][27];

int solve()
{
	cin>>n>>k>>s;

	rep(j,0,26)
		f[0][j]=-1;

	f[0][s[0]-'a']=0;	

	rep(i,1,n)
	{
		rep(j,0,26)
			f[i][j] = f[i-1][j];
		
		ll e = s[i]-'a';
		f[i][e]=i;
	}

	// cout<<f[n-1][0]<<" ";

	rep(l,1,n+1)
	{
		rep(j,0,n)
		{
			if(l==1)
			{
				dp[l][j] = 1;
			}
			else if(l>j+1)
			{
				dp[l][j]=0;
			}
			else
			{
				dp[l][j]=0;
				rep(k,0,26)
				{
					if(f[j-1][k]!=-1)
						dp[l][j]+=dp[l-1][f[j-1][k]];
				}
				
			}

		}	
	}

	vi ss(n+1,0);
	ss[0]=1;
	rep(l,1,n+1)
	{
		rep(i,0,26)
		{
			ss[l]+=dp[l][f[n-1][i]];
			// cout<<dp[l][f[n-1][i]]<<" ";
		}
		// cout<<"\n";
		// cout<<ss[l]<<" ";
	}

	ll cost=0;
	repr(l,n,-1)
	{
		if(ss[l]<k)
		{
			cost+=ss[l]*(n-l);
			k-=ss[l];
		}
		else
		{
			cost+=k*(n-l);
			cout<<cost;
			return 0;
		}
	}

	cout<<"-1";
	return 0;

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