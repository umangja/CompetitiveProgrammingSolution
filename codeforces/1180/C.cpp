/*input
5 10
1 2 3 4 5
1
2
3
4
5
6
7
8
9
10


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
	ll n,m;cin>>n>>m;
	vi a(n+1);
	a[0]=-1;
	vi maxi1(n+1,-1),maxi2(n+1,-1);
	rep(i,1,n+1)
	{
		cin>>a[i];
		if(i==1)
		{
			maxi1[i]=a[i];
			maxi2[i]=a[i];
			continue;
		}
		maxi1[i]=maxi1[i-1];
		maxi2[i]=maxi2[i-1];
		if(a[i]>maxi1[i])
		{
			maxi2[i]=maxi1[i];
			maxi1[i]=a[i];
		}
		else if(a[i]>maxi2[i])
		{
			maxi2[i]=a[i];
		}
	}

	deque< ll > d;
	rep(i,1,n+1)
		d.push_back(a[i]);
	ll index = max_element(a.begin(), a.end())-a.begin();
	// cout<<index<<"\n";
	vector< pair< ll,ll > > ans;
	rep(o,1,index)
	{
		ll a1 = d.front();
		d.pop_front();
		ll a2 = d.front();
		d.pop_front();

		ans.pb(mp(a1,a2));
		d.push_front(max(a1,a2));
		d.push_back(min(a1,a2));		
	}	

	// rep(i,0,sz(d))
	// {
		// cout<<d.at(i)<<" ";
	// }


	ll el = *max_element(a.begin(), a.end());
	while(m--)
	{
		ll x;cin>>x;
		if(x>(index-1))
		{
			ll mo = x-(index-1);
			ll g = mo%(n-1);
			if(g==0)
				g=n-1;
			cout<<el<<" "<<d.at(g);
		}
		else
		{
			cout<<ans[x-1].F<<" "<<ans[x-1].S;
		}

		cout<<"\n";
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