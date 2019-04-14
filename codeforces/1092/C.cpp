/*input
2
a
c



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
	ll ts = 2*n-2;
	vector<string > a(ts);
	string b[2];
	ll st=0;

	rep(i,0,ts)
	{
		cin>>a[i];
		if(sz(a[i])==n-1)
		{
			b[st]=a[i];
			st++;
			// cout<<b[st-1]<<" ";
		}
	}

	ll j=2;
	while(j>0)
	{
		j--;
		vector< char > ans(ts);
		vi p(n,0),suf(n,0);
		string r;
		r =b[j]+b[(j^1)][n-2];
		// cout<<r<<"\n";
		
		ll fg=0;
		rep(i,0,ts)
		{
			string cr = a[i];
			ll l=sz(cr);
			// cout<<l<<" ";
			string test = "";
			rep(k,0,l)
			{
				test+=r[k];
			}

			if(test==cr && p[l]==0)
			{
				ans[i]='P';
				p[l]=1;
				continue;
			}
			test="";
			for(ll k=n-1;k>=n-l;k--)
				test+=r[k];

			reverse(test.begin(), test.end());
			if(test==cr && suf[l]==0)
			{
				suf[l]=1;
				ans[i]='S';
				continue;
			}

			// cout<<i<<" ";
			fg=1;
			break;
		}

		if(!fg)
		{	
			rep(i,0,ts)
			{
				cout<<ans[i];
			}
			break;
		}
		// else
			// cout<<"Hello";

	}


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