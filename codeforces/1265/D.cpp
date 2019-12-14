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

void loss()
{
	cout<<"NO\n";
	exit(0);
}
int solve()
{
	vi n(4);
	rep(i,0,4) cin>>n[i];
	vi dup(4);
	rep(i,0,4) dup[i]=n[i];
	ll tot = n[0]+n[1]+n[2]+n[3];

	for(ll lstt=0;lstt<4;lstt++)
	{
		ll lst=lstt;
		rep(i,0,4) n[i]=dup[i];
		// cout<<dup[0]<<"\n";
		vi ans(tot,-1);
		if(n[lst]) ans[0]=lst,n[lst]--;
		rep(i,1,tot)
		{
			if(lst-1>=0 && n[lst-1])
			{
				ans[i]=lst-1;
				lst--;
				n[lst]--;
			}
			else if(lst+1<=3 && n[lst+1])
			{
				ans[i]=lst+1;
				lst++;
				n[lst]--;
			}
		}
		ll f=0;
		rep(i,0,tot) if(ans[i]==-1) f=1;
		if(f==0)
		{
			cout<<"YES\n";
			rep(i,0,tot) cout<<ans[i]<<" ";
			return 0;
		}
	}

	cout<<"NO\n";
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