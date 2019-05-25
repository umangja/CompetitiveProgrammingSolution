/*input
1
SoMeStRaNgEgUe reposted PoLyCaRp



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

// vector< vector< string > > adj(201,vector< string >() );
// map< string,vector< string > () > adj;
// map< string,ll > m;
// ll ans=-1;

// void DFS(string cn,ll val)
// {
// 	ans=max(ans,val);
// 	m[cn]=1;
// 	rep(i,0,sz(adj[cn]))
// 	{
// 		if(m.find(adj[cn][i])==m.end())
// 		{
// 			DFS(adj[cn][i],val+1);
// 		}
// 	}
// }

int solve()
{
	ll n;cin>>n;
	map< string,ll > m;
	m["polycarp"]=1;
	rep(i,0,n)
	{
		string s[3];
		rep(j,0,3)
		{
			cin>>s[j];
			if(j%2==0)
			{
				rep(k,0,sz(s[j]))
				{
					if(s[j][k]>=65 && s[j][k]<=90)
						s[j][k]=s[j][k]+32;
				}
			}
		}

		m[s[0]]=m[s[2]]+1;

	}

	ll ans=-1;
	all(it,m)
	{
		ans=max(ans,it->S);
	}

	cout<<ans;

	

	// DFS("Polycarp",0);
	// cout<<ans;
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