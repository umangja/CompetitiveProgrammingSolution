/*input
4
abcd
gg
codeforces
abaca

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
		string s;cin>>s;
		ll m = sz(s);
		vi f(26,0);

		rep(i,0,sz(s))
			f[s[i]-'a']++;
		
		string e = "",o = "";	
		for(ll i=0;i<26;i+=2)
		{
			while(f[i])
			{
				e+=('a'+i);
				f[i]--;
			}
		}
		for(ll i=1;i<26;i+=2)
		{
			while(f[i])
			{
				o+=('a'+i);
				f[i]--;
			}
		}
		string r;
		if(sz(o)>0 && sz(e)>0 && abs(e[sz(e)-1]-o[0])==1 && abs(o[sz(o)-1]-e[0])==1 )
			r = "No answer";
		else if(sz(o)==0 || sz(e)==0 || (abs(e[sz(e)-1]-o[0])==1) )
			r = o+e;
		else
			r = e+o;	

		cout<<r<<"\n";
		return 0;

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