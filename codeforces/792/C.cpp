/*input
20000111
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
#define inf			1e18
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
	string s,ans="";cin>>s;
	string r="";
	ll n = sz(s),pre=0;

	ll sum=0;
	rep(i,0,n) sum+=(s[i]-'0');

	vvi pos(3,vi () );
	for(ll i=n-1;i>=0;i--) pos[(s[i]-'0')%3].pb(i);
	rep(i,0,n) if(s[i]=='0') pre=1;
	vi el_pos;
	string ansf;
	if(sum%3==0) ansf=s;
	else if(sum%3==1)
	{
		if(sz(pos[1])==0 && sz(pos[2])<2) ansf="-1";
		else
		{
			if(sz(pos[1])!=0) 
			{
				el_pos.clear();
				el_pos.pb(pos[1][0]);

				r="";
				ll f=0;
				rep(i,0,n) {
				ll g=0;
				rep(j,0,sz(el_pos)) if(i==el_pos[j])  g=1;
				if(g==0) r+=s[i];
				}
				ans="";

				rep(i,0,sz(r)) if(r[i]=='0' && f==0) continue; else f=1,ans+=r[i]; 
				if(sz(ans)>sz(ansf)) ansf=ans;	


			}
			if (sz(pos[2])>=2)
			{
				el_pos.clear();
				el_pos.pb(pos[2][0]),el_pos.pb(pos[2][1]);

				r="";
				ll f=0;
				rep(i,0,n) {
				ll g=0;
				rep(j,0,sz(el_pos)) if(i==el_pos[j])  g=1;
				if(g==0) r+=s[i];
				}
				ans="";

				rep(i,0,sz(r)) if(r[i]=='0' && f==0) continue; else f=1,ans+=r[i]; 
				if(sz(ans)>sz(ansf)) ansf=ans;	

			}
		}
	}
	else 
	{
		if(sz(pos[2])==0 && sz(pos[1])<2) ansf="-1";
		else
		{
			if(sz(pos[2])!=0) 
			{
				el_pos.clear();
				el_pos.pb(pos[2][0]);

				r="";
				ll f=0;
				rep(i,0,n) {
				ll g=0;
				rep(j,0,sz(el_pos)) if(i==el_pos[j])  g=1;
				if(g==0) r+=s[i];
				}

				ans="";
				rep(i,0,sz(r)) if(r[i]=='0' && f==0) continue; else f=1,ans+=r[i]; 
				if(sz(ans)>sz(ansf)) ansf=ans;	


			}
			if (sz(pos[1])>=2)
			{
				el_pos.clear();
				el_pos.pb(pos[1][0]),el_pos.pb(pos[1][1]);

				r="";
				ll f=0;
				rep(i,0,n) {
				ll g=0;
				rep(j,0,sz(el_pos)) if(i==el_pos[j])  g=1;
				if(g==0) r+=s[i];
				}
				ans="";

				rep(i,0,sz(r)) if(r[i]=='0' && f==0) continue; else f=1,ans+=r[i]; 
				// cout<<ans<<"\n";
				if(sz(ans)>sz(ansf)) ansf=ans;	

			}
		}
	}

	if(sz(ansf)==0 && pre==1) ansf="0";
	else if(sz(ansf)==0) ansf="-1";
	cout<<ansf;
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}