/*input
30 20 10




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
	ll a,b,c;cin>>a>>b>>c;
	ll w = min(min(a/3,b/2),c/2);
	ll ans=0;
	ans+=w*7;
	a-=w*3;b-=2*w;c-=2*w;

	// cout<<ans;
	ll t_ans=0;
	repr(l,7,-1)
	{
		rep(s,0,7)
		{
			ll ta=a;
			ll tb=b;
			ll tc=c;

			ll j=s;
			ll count=0;
			for(;count<l;j=(j+1)%7)
			{
				if(j==0 || j==3 || j==6)
				{
					if(ta==0)
					{
						break;
					}
					ta--;
				}
				else if(j==1 || j==5)
				{
					if(tb==0)
						break;
					tb--;
				}
				else
				{
					if(tc==0)
						break;
					tc--;
				} 

				count++;

			}

			// t_ans = max(t_ans,count-1);

			if(count==l)
			{
				ans+=l;cout<<ans;return 0;
			}

		}
	}

	// cout<<t_ans;
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