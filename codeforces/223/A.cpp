/*input
 
*/
 
 
//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
int solve()
{
	string s;cin>>s;
	ll n=sz(s);
	stack<pair<char,ll> > st;
 
	string r="";
	vs pans;
	ll pos=0;
	rep(i,0,n)
	{
		if(s[i]=='(') st.push(mp(s[i],pos++)),r+=s[i];
		else if(s[i]=='[') st.push(mp(s[i],pos++)),r+=s[i];
		else
		{
			if(sz(st)==0)
			{
				pans.pb(r);
				r="";
				pos=0;
				continue;
			}
 
			char c = st.top().F;
			if( (s[i]==')' && c=='(' ) || ( s[i]==']' && c=='[' ) ) st.pop(),r+=s[i],pos++;
			else 
			{
				// cout<<r<<"\n";
				while(sz(st)>0)
				{
					ll p = (st.top()).S;
					r[p]='.';
					// cout<<p<<"\n";
					st.pop();
				} 
 
				string rr = "";
				rep(j,0,sz(r))
				{
					if(r[j]=='.')
					{
						if(sz(rr))
						{
							pans.pb(rr);
							rr="";
						}
					}
					else rr+=r[j];
				}
 
				if(sz(rr))
				{
					pans.pb(rr);
					rr="";
				}
 
				r="";
				pos=0;
			}
		}
	}
 
	if(sz(st))
	{
		while(sz(st)>0)
		{
			ll p = (st.top()).S;
			r[p]='.';
			st.pop();
		} 
 
		string rr = "";
		rep(j,0,sz(r))
		{
			if(r[j]=='.')
			{
				if(sz(rr))
				{
					pans.pb(rr);
					rr="";
				}
			}
			else rr+=r[j];
		}

		if(sz(rr))
		{
			pans.pb(rr);
			rr="";
		}
 
	}
	else pans.pb(r);
 
 
	ll ansc=0;
	string ans="";
	rep(i,0,sz(pans))
	{
		string cur=pans[i];
		// whatis(cur);
		ll cnt=0;
		rep(j,0,sz(cur)) if(cur[j]=='[') cnt++;
		if(cnt>ansc) ansc=cnt,ans=cur; 
	}
 
	cout<<ansc<<"\n"<<ans<<"\n";
	return 0;
}
 
int main()
{
	auto start = chrono::high_resolution_clock::now();
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();
 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}	