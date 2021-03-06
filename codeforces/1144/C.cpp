/*input
7
7 2 7 3 3 1 4

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
	vi a(n),inc,dec;
	map< ll,ll > m;

	rep(i,0,n)
	{
		cin>>a[i];
		if(m[a[i]]==0)
			inc.pb(a[i]);
		else if(m[a[i]]==1)
			dec.pb(a[i]);
		else
		{
			cout<<"NO";
			return 0;
		}
		m[a[i]]++;
	}

	sort(inc.begin(), inc.end());
	sort(dec.begin(), dec.end(),greater<> () );
	cout<<"YES\n";
	cout<<sz(inc)<<"\n";
	rep(i,0,sz(inc))
		cout<<inc[i]<<" ";
	cout<<"\n"<<sz(dec)<<"\n";
	rep(i,0,sz(dec))
		cout<<dec[i]<<" ";
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