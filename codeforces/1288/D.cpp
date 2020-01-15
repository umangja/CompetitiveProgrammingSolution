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

const ll N = 3e5+5;
vvi a(N,vi (8));
vvi mn(N,vi (2,1e10));
ll n,m;
ll tot_mask=0;
ll ansi=-1,ansj=-1,gmx=-1;

void fun(ll mask)
{

	ll mxi=-1,mxj=-1,mx1=-1,mx2=-1;
	rep(i,0,n) rep(j,0,2) mn[i][j]=inf;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll cur = (mask&(1<<j))>>j;
			mn[i][cur] = min(mn[i][cur],a[i][j]); 
			// if(mask==5 && cur==1 && i==0){ whatis(j);whatis(mn[i][cur]); whatis(a[i][j]);}
		}

		if(mn[i][0]>mx1) mx1=mn[i][0],mxi=i+1;
		if(mn[i][1]>mx2) mx2=mn[i][1],mxj=i+1;
	}

	ll ans = min(mx1,mx2);
	// cout<<ans<<"\n";
	if(ans>gmx) ansi=mxi,ansj=mxj,gmx=ans;
	return ;
}

int solve()
{
	cin>>n>>m;
	rep(i,0,n) rep(j,0,m) cin>>a[i][j];
	tot_mask = (1<<m)-1;
	vi vis(tot_mask+1,0);
	rep(i,0,tot_mask+1)
	{
		if(vis[i]==0)
		{
			vis[i]=vis[tot_mask-i]=1;
			fun(i);
		}
	} 
 	cout<<ansi<<" "<<ansj<<"\n";
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