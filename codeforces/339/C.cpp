/*input
1000000000
2

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

vi a(11);
ll m;

ll dp[12][11][5002];
ll b[5002];
void init()
{
	rep(i,0,12)
	{
		rep(j,0,11)
		{
			rep(k,0,5002)
			{
				dp[i][j][k]=-1;
			}
		}
	}
}

ll f(ll diff,ll last,ll count)
{
	// cout<<diff<<" "<<last<<" "<<count<<"\n";
	// cout<<dp[diff][last][count];
	if(count==m+1)
		return 1;

	if(diff>10)
		return 0;

	if(dp[diff][last][count]!=-1)
	{
		return dp[diff][last][count];
	}

	ll poss=0;
	rep(i,1,11)
	{
		if(a[i]==1 && i!=last)
		{
			if(count%2==1 && (-1*diff+i)>0)
			{
				poss = f(abs(-1*diff+i),i,count+1);
				if(poss==1)
				{
					b[count]=i;
					return poss;
				}
			}
			else if(count%2==0 && (diff-i)<0)
			{
				poss = f(abs(diff-i),i,count+1);
				if(poss==1)
				{
					b[count]=i;
					return poss;
				}
			}	

		}
	}

	dp[diff][last][count]=poss;
	return poss;
}

int solve()
{	
	init();
	string s;cin>>s;
	rep(i,0,10)
	{
		a[i+1]=s[i]-'0';
	}

	cin>>m;
	ll ans = f(0,0,1);

	// cout<<ans;
	if(ans==0)
	{
		cout<<"NO\n";
	}
	else if(ans==1)
	{
		cout<<"YES\n";
		rep(i,1,m+1)
			cout<<b[i]<<" ";
	}

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