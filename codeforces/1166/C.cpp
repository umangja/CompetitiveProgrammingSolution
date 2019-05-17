/*input
2 3 6

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
ll n;

int solve()
{
	cin>>n;
	vi a(n);
	rep(i,0,n)
	{
		cin>>a[i];
	}

	sort(a.begin(), a.end());
	ll ans=0;

	rep(i,0,n)
	{
		ll x = a[i];
		ll ymax = (abs(x)+1)/2;

		if(x<0)
		{

			ll j = lbnd(a.begin(), a.end(),-1*ymax)-a.begin();
			ll j2 = lbnd(a.begin(), a.end(),ymax)-a.begin();
			ll j3 = lbnd(a.begin(), a.end(),2*abs(x))-a.begin();

			if(j2<n)
			{
				if(j3==n || a[j3]>2*abs(x))
					j3--;

				ans+=j3-j2+1;
			}


			// cout<<j<<" "<<j2<<"\n";

			if(j>=n || a[j]>-1*ymax)
				j--;

			if(j>=i)
			{
				// cout<<j-i<<" ";
				ans+=j-i;
			}

			// cout<<j2<<"\n";
			// ans+=j2;
		}
		else
		{
			ll ymax = 2*x;
			ll j = lbnd(a.begin(), a.end(),ymax)-a.begin();
			if(j>=n || a[j]>ymax)
				j--;

			if(j>=i)
				ans+=j-i;
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