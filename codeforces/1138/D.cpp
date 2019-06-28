/*input
10101000
101

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
string s;
string t;

vector< ll > prefix_function()
{
	ll n = sz(t);
	vi ans(n);
	ans[0]=0;

	rep(i,1,n)
	{
		ll j = ans[i-1];
		while(j>0 && t[j]!=t[i])
			j=ans[j-1];
		
		if(j==0 && t[j]!=t[i])
			ans[i]=0;
		else
			ans[i]=j+1;
	}

	return ans;
}

int solve()
{
	cin>>s>>t;
	vi pf = prefix_function();

	ll s0=0,s1=0,t0=0,t1=0;
	rep(i,0,sz(s))
	{
		s0+=(s[i]=='0');
		s1+=(s[i]=='1');
	}

	rep(i,0,sz(t))
	{
		t0+=(t[i]=='0');
		t1+=(t[i]=='1');
	}

	if(t0==0 || t1==0)
	{
		sort(s.begin(), s.end());
		cout<<s;
		return 0;
	}

	if(s0>=t0 && s1>=t1)
	{
		s0-=t0;s1-=t1;
		ll re = pf[sz(t)-1];
		ll m0=0,m1=0;
		rep(i,0,re)
		{
			m0+=(t[i]=='0');
			m1+=(t[i]=='1');
		}

		t0-=m0;t1-=m1;
		// cout<<t1<<"\n";
		ll ans=min(s0/t0,s1/t1);
		s0-=ans*t0;s1-=ans*t1;

		ans++;
		string r=t;
		string add="";
		rep(i,re,sz(t))
			add+=t[i];
		rep(i,0,ans-1)
			r+=add;
		rep(i,0,s0)
			r+='0';

		rep(i,0,s1)
			r+='1';

		cout<<r;
		return 0;
	}
	cout<<s;
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