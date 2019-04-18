/*input
5 1 4
2 5 7 4 6
2 2









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

const ll N = 2e5+5;
ll n,m,k;
vi a,b,su;
vector< pair<ll,ll> > o;
ll so;
ll dp[N];

void init()
{
	rep(i,0,N)
	{
		dp[i]=-1;
	}
}

bool cmp(const pair< ll,ll > &a,const pair< ll,ll > &b)
{
	return abs(a.F-a.S) < abs(b.F-b.S);
}

ll f(ll tp)
{
	if(tp==0)
		return 0;
	if(tp<=0)
		return inf;

	ll ans=inf;
	rep(i,0,so)
	{
		ll x =o[i].F,y = o[i].S;
		// cout<<x<<" "<<y<<"\n";
		if(tp>=x)
		{
			ll p = x-y;	
			ll cost;

			if(dp[tp-x]==-1)
			{
				dp[tp-x] = f(tp-x);
			}
			
			if(tp<sz(su) && p!=0)
			{
				cost = min(dp[tp-x]+ su[tp-p]-su[tp],su[0]-su[tp]);
				// cout<<cost<<"\n";
			}
			else if(p!=0)
				cost = min(dp[tp-x]+ su[tp-p],su[0]);
			else 
			{
				// cout<<tp-x<<"\n";
				cost = dp[tp-x];
				// cout<<cost<<"\n";
			}

			// cout<<cost<<" ";

			ans = min(cost,ans);
		}
	}
	// cout<<ans<<" ";
	if(tp<sz(su))
		ans = min(ans,su[0]-su[tp]);
	else
		ans = min(ans,su[0]);

	// cout<<ans<<"\n";
	dp[tp]=ans;
	return ans;

}

int solve()
{
	init();
	cin>>n>>m>>k;
	rep(i,0,n)
	{
		ll x;cin>>x;
		a.pb(x);
	}

	sort(a.begin(), a.end());

	ll s = 0;
	rep(i,0,k)
	{
		b.pb(a[i]);
		s+=a[i];
	}

	// cout<<s;
	rep(i,0,k)
	{
		if(i==0)
			su.pb(s);
		else
			su.pb(su[i-1]-b[i-1]);

		// cout<<su[i]<<" ";
	}

	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		if(k%x==0 && y==x)
		{
			cout<<"0";
			return 0;
		}
		if(x<=k)
			o.pb(mp(x,y));
	}

	so = sz(o);
	sort(o.begin(), o.end(),cmp);

	// if(k==sz(su))
	// 	cout<<"hel";

	cout<<f(k);

	// cout<<o[0].F<<o[0].S;
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