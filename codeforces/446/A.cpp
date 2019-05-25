/*input
6
7 2 3 1 4 5

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

const ll N = 1e5+5;
ll n;
vi a(N),l(N),r(N);

void f()
{
	l[0]=1;
	ll ans = a[0];
	rep(i,1,n)
	{
		if(a[i]>ans)
			l[i]=l[i-1]+1;
		else
			l[i]=1;
		ans=a[i];
	}

	// rep(i,0,n)
	// 	cout<<l[i]<<" ";
	// cout<<"\n";
}

ll g()
{
	ll ans=a[n-1];
	r[n-1]=1;
	for(ll i=n-2;i>=0;i--)
	{
		if(a[i]<ans)
			r[i]=r[i+1]+1;
		else
			r[i]=1;

		ans = a[i];
	}

	// rep(i,0,n)
	// 	cout<<r[i]<<" ";
	// cout<<"\n";
}

int solve()
{
	cin>>n;
	rep(i,0,n)
		cin>>a[i];

	f();g();

	ll ans=2;
	rep(i,0,n-1)
	{
		ans=max(ans,l[i]+1);
		ans=max(ans,r[i]+1);
	}
	rep(i,0,n)
	{
		if(i!=0 && i!=n-1 && a[i-1]+1<a[i+1])
			ans=max(ans,(l[i-1]+r[i+1]+1));
		else if(i!=0)
			ans=max(ans,l[i-1]+1);
		else if(i!=n-1)
			ans=max(ans,r[i+1]+1);
	}

	cout<<min(ans,n);
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