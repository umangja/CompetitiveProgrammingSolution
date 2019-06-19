/*input
4
hello
hello
hello
helloo
hello
hlllloo
hello
helo


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
	while(n--)
	{
		string s,t;cin>>s>>t;
		ll f=1;
		ll j=0;

		if(sz(t)<sz(s))
		{
			cout<<"NO\n";
			continue;
		}
		ll i=0;
		for(;i<sz(t);i++)
		{
			if(j<sz(s) && t[i]==s[j])
			{
				j++;
				continue;
			}
			else
			{
				if(i>=1 && t[i]==t[i-1])
					continue;
				else
				{
					cout<<"NO\n";
					f=0;
					break;
				}
			}
		}

		if(f && j==sz(s))
			cout<<"YES\n";
		else if(f)
			cout<<"NO\n";
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