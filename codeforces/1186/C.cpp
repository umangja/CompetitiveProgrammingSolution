/*input
1010111110
0110


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
	string s1,s2;
	cin>>s1>>s2;
	ll n = sz(s1),m = sz(s2);

	vi a(n),b(m);
	rep(i,0,n)
		a[i]=s1[i]-'0';
	rep(i,0,m)
		b[i]=s2[i]-'0';

	vi pf(n);
	pf[0] = a[0];
	rep(i,1,n)
		pf[i] = pf[i-1]^a[i];

	ll c =0;
	rep(i,0,m)
		c^=b[i];
	
	// rep(i,0,n)
		// cout<<pf[i]<<" ";
	// cout<<"\n"<<c<<"\n";

	ll ans=0;
	rep(i,0,n-m+1)
	{
		ll last=0;
		if(i!=0)
			last=pf[i-1];

		ll t = c^(last^pf[i+m-1]);
		// cout<<c<<" "<<last<<" "<<pf[i+m-1]<<" "<<i<<" "<<t<<"\n";
		if(t==0)
		{
			// cout<<i<<"\n";
			ans++;
		}
	}

	cout<<ans;
	
	return 0;
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