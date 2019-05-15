/*input
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7

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

struct subset
{
	ll parent;
	ll rank;
};
const ll N =5e5+5;
struct subset subsets[N];

ll find(ll x)
{
	if(subsets[x].parent!=x)
	{
		subsets[x].parent =  find(subsets[x].parent);	
	}

	return subsets[x].parent;
}

void unio(ll x,ll y)
{
	ll xr = find(x);
	ll yr = find(y);

	if(subsets[xr].rank<subsets[yr].rank)
		subsets[xr].parent = yr;
	else if(subsets[xr].rank>subsets[yr].rank)
		subsets[yr].parent = xr;
	else
	{
		subsets[yr].parent = xr;
		subsets[xr].rank++;
	}

}


int solve()
{
	rep(i,0,N)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0; 
	}

	ll n,m;cin>>n>>m;
	rep(i,0,m)
	{
		ll k;cin>>k;
		ll bs;
		if(k>=1)
		{
			cin>>bs;bs--;
		}

		rep(i,0,k-1)
		{
			ll b;cin>>b;b--;
			unio(bs,b);
		}
	}

	set< ll > p;
	rep(i,0,n)
	{
		ll pp = find(i);
		p.insert(pp);
	}

	ll ds = sz(p);
	vector< ll > v(n);
	rep(i,0,n)
		v[i]=0;
	rep(i,0,n)
	{
		ll pt = find(i);
		v[pt]++;
	}

	rep(i,0,n)
	{
		ll pt = find(i);
		cout<<v[pt]<<" ";
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