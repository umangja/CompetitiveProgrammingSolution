/*input
6
2 5 3 1 4 6


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
	vi a(n+1),b(n+1);
	rep(i,1,n+1)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	b[0]=-1;

	vector< pair< ll,ll > > ans;
	ll t = n/2;
	rep(i,1,n+1)
	{
		ll p = b[i];
		if(p!=i)
		{
			if(abs(p-i)>=t)
			{
				ans.pb(mp(i,p));
				b[a[i]]=p;
				b[i]=i;
				swap(a[i],a[p]);
			}
			else
			{
				ll f;
				if(abs(p-n)>=t)
					f=n;
				else
					f=1;

				ans.pb(mp(p,f));
				b[a[f]]=p;
				b[a[p]]=f;
				swap(a[f],a[p]);

				//i = n or 1

				if(abs(f-i)>=t)
				{
					i--;
					continue;
				}

				if((i+t)<=n)
					f=i+t;
				else
					f=i-t;

				p = b[i];
				b[a[f]]=p;
				b[a[p]]=f;
				ans.pb(mp(p,f));

				swap(a[f],a[p]);
				i--;

			}
		}
	}

	// rep(i,0,n)
	// cout<<a[i]<<" ";
	// cout<<"\n";
	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans))
		cout<<ans[i].F<<" "<<ans[i].S<<"\n";

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