/*input
4
5
1 2 3 4 5
2 4 7 11 3
3
13 37 39
1 2 3
4
0 0 0 0
1 2 3 4
3
1 2 -1
-6 -12 6

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
	vi a(n),b(n),c(n);
	rep(i,0,n)
		cin>>a[i];
	rep(i,0,n)
		cin>>b[i];

	ll ans=0;
	map< pair< ll,ll >,ll > m;
	ll d=0;
	rep(i,0,n)
	{

		if(a[i]==0 && b[i]!=0)
			continue;
		else if(a[i]==0 && b[i]==0)
			ans++;
		else if(a[i]!=0 && b[i]==0)
			d++;
		else
		{
			ll g = __gcd(a[i],b[i]);
			a[i]/=g;
			b[i]/=g;
			m[mp(-1*b[i],a[i])]++;
		}
	}

	ll maxi = d;
	all(it,m)
	{
		maxi = max(maxi,it->S);
	}

	ans+=maxi;
	cout<<ans;
	// cout<<"\n";


	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	// cin>>t;
	while(t--)
		solve();
}