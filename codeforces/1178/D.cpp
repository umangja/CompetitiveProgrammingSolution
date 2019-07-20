/*input
1000

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
const ll N = 3005;
vi prime(N,1);

void preprocess()
{
	prime[0]=prime[1]=0;
	prime[2]=1;
	for(ll i=2;i*i<N;i++)
	{
		if(prime[i])
		{
			for(ll j = i*i;j<N;j+=i)
				prime[j]=0;
		}
	}
}

int solve()
{
	preprocess();
	ll n;cin>>n;
	ll ne = n;
	while(prime[ne]==0) ne++;
	vpii ans;
	rep(i,0,n-1) ans.pb(mp(i,i+1)),ne--;
	ans.pb(mp(0,n-1)),ne--;
	ll st=0;
	set< ll > s;
	while(ne)
	{
		ll next = (st+2)%n;
		if(s.find(st)==s.end() && s.find(next)==s.end() )
			ans.pb(mp(st,next)),ne--,s.insert(st),s.insert(next);

		st=(st+1)%n;
	}
	cout<<sz(ans);
	cout<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i].F+1<<" "<<ans[i].S+1<<"\n";

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