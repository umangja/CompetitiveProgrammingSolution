/*input
4
1 1 1 1



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


int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n)
		cin>>a[i];

	vi fq(2e5+5,0);
	rep(i,0,n)
	{
		fq[a[i]]++;
	}

	ll m=a[0];
	ll ind =0;
	rep(i,0,n)
	{
		if(fq[a[i]]>fq[m])
		{
			m=a[i];
			ind=i;
		}
	}
	vector< pair< ll,pair< ll,ll > > > ans;
	rep(i,ind+1,n)
	{
		if(a[i]<m)
		{
			ans.pb(mp(1,mp(i,i-1)));
		}
		else if(a[i]>m)
		{
			ans.pb(mp(2,mp(i,i-1)));
		}

	}

	repr(i,ind-1,-1)
	{
		if(a[i]<m)
		{
			ans.pb(mp(1,mp(i,i+1)));
		}
		else if(a[i]>m)
		{
			ans.pb(mp(2,mp(i,i+1)));
		}
	}
	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans))
		cout<<ans[i].F<<" "<<ans[i].S.F+1<<" "<<ans[i].S.S+1<<"\n";
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