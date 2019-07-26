/*input
3 2
2 5



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
	ll n,k;cin>>n>>k;
	vi a(k);rep(i,0,k) cin>>a[i];
	vi b(n,0),c(n,0);

	rep(i,0,n) b[i]=i+1;

	ll count=n;
	ll cp = 0;
	ll j=0;
	while(j<k)
	{
		ll left = b[cp];
		ll tot_move = (left+a[j])%(count);
		if(tot_move==0) tot_move=count;
		ll st=-1;
		while(tot_move>0)
		{
			st=(st+1)%n;
			if(c[st]==0)
				tot_move--;
		
		}
		cp=st;
		cout<<cp+1<<" ";
		rep(i,cp,n) b[i]--;
		c[cp]=1;
		while(c[cp]!=0) cp=(cp+1)%n;
		count--;
		j++;
	}
	// cout<<"\n";
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