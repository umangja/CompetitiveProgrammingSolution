/*input
25
1
2
1
3
1
2
1
4
2
4 2
1
5
1
2
1
3
2
2 3
1
6
2
6 2
2
3 6
3
6 2 3
1
7
1
2
1
4
2
2 4
1
8
2
8 2
2
4 8
3
2 4 8
1
3
1
9
2
3 9
1
2
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

vi ad; 

void ok(ll x)
{
	cout<<x<<"\n";
	exit;
}
void Divisors(ll n)
{
	ad.clear();
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ad.pb(i);
			if(n/i!=i)
				ad.pb(n/i);
		}
	}
}

int solve()
{
	ll n;cin>>n;
	vi d(n);
	rep(i,0,n)
		cin>>d[i];

	sort(d.begin(), d.end());
	ll x = d[0]*d[n-1];
	Divisors(x);
	sort(ad.begin(), ad.end());
	// rep(i,0,sz(ad))
	// cout<<ad[i]<<" ";
	if(sz(ad)==n)
	{
		ll f=0;
		rep(i,0,n)
		{
			if(d[i]!=ad[i])
			{
				f=1;
				ok(-1);
				break;
			}
		}
		if(!f)
			ok(x);
	}
	else
		ok(-1);	

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	cin>>t;
	while(t--)
		solve();
}