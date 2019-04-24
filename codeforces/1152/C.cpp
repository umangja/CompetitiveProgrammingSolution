/*input

6 10

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

vi p;
void pf(ll n)
{
	// if(n%2==0)
	// {
	// 	p.pb(2);
	// 	n/=2;
	// }

	// while(n%2==0)
	// {
	// 	n/=2;
	// }

	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
				p.pb(i);
			else
			{
				p.pb(i);
				p.pb(n/i);
			}
		}

	}
}

ll lcmi(ll a,ll b)
{
	return (a*b)/(__gcd(a,b));
}

int solve()
{
	ll a,b;cin>>a>>b;
	if(b<a)
		swap(a,b);

	ll d=b-a;
	pf(d);
	ll ans=0;
	ll lcm=1e18;

	// p.pb(4);
	rep(i,0,sz(p))
	{
		ll A;
		if(a%p[i]==0)
		{
			A = a;
		}
		else
		{
			A = ((a/p[i])+1)*p[i];
		}

		ll a1 = A;
		ll b1 = a1-a+b;


		ll temp = lcmi(a1,b1);
		if(temp<lcm)
		{
			lcm=temp;
			// cout<<p[i]<<" "<<a1<<"\n";
			ans = b1-b;
		}
	}

	cout<<ans;
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