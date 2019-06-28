/*input
5
-6.32509
4.30066
-0.93878
2.00000
2.96321

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
	vi ans(n);
	vector< double > v(n);
	ll sump=0,fp=0,sumn=0,fn=0;
	rep(i,0,n)
	{
		double x;cin>>x;
		v[i]=x;
		if(x==(ll)x)
		{
			if(x>0)
			{
				sump+=x;
			}
			else
			{
				x*=(-1);
				sumn+=x;
			}
		}
		else
		{
			if(x>0)
			{
				fp++;
				sump+=(ll)x;
			}
			else
			{
				fn++;
				x*=-1;
				sumn+=(ll)x;
			}
		}
	}

	// cout<<sump<<sumn<<"\n";

	ll s = max(sump,sumn);

	rep(i,0,n)
	{
		if(v[i]==(ll)v[i])
		{
			ans[i]=v[i];
			continue;
		}
		if(sump==s && sumn==s)
			ans[i] = (ll)v[i];

		if(sump<s && v[i]>0)
		{
			ans[i] = (ll)v[i] +1;
			sump++;
		}
		else if(sumn<s && v[i]<0)
		{
			ans[i] = (ll)v[i]-1;
			sumn++;
		}
		else
		{
			ans[i] = (ll)v[i];
		}
	}

	rep(i,0,n)
		cout<<ans[i]<<"\n";
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