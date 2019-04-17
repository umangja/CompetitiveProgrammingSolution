/*input
5 1
2 4 5 3 1




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
	ll n,k;cin>>n>>k;
	vi a(n),b(n+1);
	rep(i,0,n)
	{
		cin>>a[i];
		b[a[i]]=i+1;
	}

	vi next(n+5),prev(n+5);

	rep(i,0,n+5)
	{
		next[i]=i+1;
		prev[i]=i-1;
	}

	prev[0]=0;

	vi ans(n+1,-1);
	ll t=1,count=0;

	for(ll i=n;i>=1;i--)
	{
		ll p = b[i];
		if(ans[p]!=-1)
			continue;

		ans[p]=t;

		count=0;
		ll j1;
		for(j1=next[p];j1<=n && count<k;)
		{
			ans[j1]=t;
			j1=next[j1];
			count++;
		}

		// cout<<j1;

		count=0;
		ll j2;
		for(j2=prev[p];j2>=0 && count<k;)
		{
			ans[j2]=t;
			j2=prev[j2];
			count++;
		}

		if(j1!=n+1)
			prev[j1]=j2;
		else
			prev[j1-1]=j2;

		if(j2!=-1)
			next[j2]=j1;
		else
			next[j2+1]=j1;

		t=3-t;
	}

	rep(i,1,n+1)
		cout<<ans[i];
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