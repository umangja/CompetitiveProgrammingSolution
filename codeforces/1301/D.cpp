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
	ll n,m;cin>>n>>m;
	ll k;cin>>k;
	vector< pair< string ,ll > > ans;

	if(k>4*n*m-2*n-2*m) cout<<"NO\n";
	else
	{
		ll cur = 0;
		while(k)
		{
			ll f = min(m-1,k);
			if(f>0) ans.pb(mp("R",f));
			k-=f;

			if(cur==0)
			{
				f=min(m-1,k);
				if(f>0) ans.pb(mp("L",f));
				k-=f;
			} 
			else
			{
				f=min(m-1,k/3);
				if(f>0) ans.pb(mp("UDL",f));

				if(f!=m-1 && k%3==1) ans.pb(mp("U",1));
				if(f!=m-1 && k%3==2) ans.pb(mp("UD",1));

				if(f!=m-1) k-=k%3;
				k-=3*f;
			}

			if(k>0 && cur!=n-1) ans.pb(mp("D",1)),k--,cur++;
			else if(cur==n-1 && k>0)
			{
				ans.pb(mp("U",k));
				k-=k;
			}

		}
		cout<<"YES\n";
		cout<<sz(ans)<<"\n";
		rep(i,0,sz(ans)) cout<<ans[i].S<<" "<<ans[i].F<<"\n";
	}

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