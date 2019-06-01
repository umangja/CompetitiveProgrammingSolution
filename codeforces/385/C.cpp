/*input
7
2 3 5 7 11 4 8
2
8 10
2 123


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
const ll N = 1e6+5,n1=1e7+5;
ll n;
vector< ll > a(N);
map< ll,ll > m;
set< ll > s;
vector< ll > v;
ll spf[n1];
void seive()
{	
	rep(i,1,n1)
		spf[i]=i;

	for(ll i=2;i<=n1;i+=2)
		spf[i]=2;

	for(ll i=3;i*i<=n1;i+=2)
	{
		if(spf[i]==i)
		{
			for(ll j=i*i;j<=n1;j+=i)
			{
				if(spf[j]==j)
					spf[j]=i;
			}
		}
	}
}

void pf(ll no)
{
	set< ll > s1;
	while(no!=1)
	{
		s1.insert(spf[no]);
		no/=spf[no];
	}

	all(it,s1)
	{
		s.insert(*it);
		m[*it]++;
	}
}

ll f(ll r)
{
	ll idx = lbnd(v.begin(), v.end(),r)-v.begin();
	if(idx==sz(v) ||  v[idx]!=r)
		idx--;

	if(idx>=0)
	{
		// cout<<v[idx]<<" "<<idx<<"\n";
		return m[v[idx]];
	}

	// cout<<"0\n";
	return 0;

}

int solve()
{
	ll l,r;
	// cin>>l>>r;
	scanf("%lld %lld",&l,&r);
	cout<<f(r)-f(l-1)<<"\n";
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	cin>>n;
	seive();
	rep(i,0,n)
	{
		// cin>>a[i];
		scanf("%lld",&a[i]);
		// cout<<a[i];
		pf(a[i]);
	}

	all(it,s)
	{
		v.pb(*it);
		// cout<<*it;
	}

	rep(i,1,sz(v))
	{
		m[v[i]]+=m[v[i-1]];
	}

	ll t=1;
	cin>>t;

	// all(it,m)
	// cout<<it->F<<" "<<it->S<<"\n";
	// seive();
	while(t--)
		solve();
}