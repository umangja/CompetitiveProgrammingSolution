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
	ll n;cin>>n;
	string s = "";

	ll dup=n;
	while(dup) s+=(char)((dup%10)+'0'),dup/=10;
	reverse(s.begin(), s.end());

	ll nn=sz(s);
	ll ans=50;
	rep(i,0,(1<<nn))
	{
		string r = "";
		rep(j,0,nn) if(((i>>j)&1)==1) r+=s[j];

		if(sz(r)!=0 && r[0]=='0') continue;

		ll num = 0;
		rep(j,0,sz(r)) num+=(ll)pow(10,sz(r)-1-j)*(char)(r[j]-'0');
		ll sq = (ll)sqrt(num);
		if(sq*sq==num)
		{
			// whatis(num);
			ll cnt=0;
			rep(j,0,nn) if(((i>>j)&1)==0) cnt++;
			ans=min(ans,cnt);
		}
	}

	if(ans==nn) ans=-1;
	cout<<ans<<"\n";


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