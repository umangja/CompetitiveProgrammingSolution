/*input
10 10
itttrrrnnn
bbbbpppkdv
bbbbpppkzv
bbbbpppkzv
bbbbpppbbv
ippeerrsss
ippeerrsss
ibbeeeesss
iiieeeeeef
llorrrrvzz
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

ll n,m;
char v[1001][1001];
ll dp2[1001][1001];
ll dp3[1001][1001];

void init()
{
	rep(i,0,1001)
	{
		rep(j,0,1001)
		{
			dp2[i][j]=1;
			dp3[i][j]=1;
		}
	}
}


int solve()
{
	init();
	cin>>n>>m;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			cin>>v[i][j];
		}	
	}

	ll ans=0;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(j-1>=0 && v[i][j]==v[i][j-1])
				dp2[i][j] = dp2[i][j-1]+1; 
			else
				dp2[i][j]=1;	

		}
	}

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(i-1>=0 && v[i][j]==v[i-1][j])
				dp3[i][j] = dp3[i-1][j]+1;
			else
				dp3[i][j]=1; 
		}
	}

	// rep(i,0,n)
	// {
	// 	rep(j,0,m)
	// 	{
	// 		cout<<i<<" "<<j<<" "<<dp2[i][j]<<"\n";
	// 		cout<<i<<" "<<j<<" "<<dp3[i][j]<<"\n";
			

	// 	}
	// }

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll s = dp3[i][j];
			// if(i==8 && j==5)
				// cout<<s<<" "<<dp3[i-s][j]<<" "<<dp3[i-2*s][j]<<"\n";
			// cout<<s<<" "<<i<<"\n";
			if(i-s<0 || dp3[i-s][j]!=s) continue;
			if(i-2*s<0 || dp3[i-2*s][j]<s) continue;

			ll mini = inf;
			ll l = max(i-3*s,(ll)-1);
			// ll l = i-3*s;
			for(ll b = i;b>l;b--)
				mini = min(mini,dp2[b][j]);

			// cout<<i<<" "<<j<<" "<<s<<" "<<mini<<"\n";

			ans+=mini;

		}
	}

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