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

const ll mod = 1e9+7;
ll dp[65][2][2][2][2][2];
vi num1,num2;

ll fun(ll pos,ll f1,ll f2,ll l1,ll l2,ll nz)
{

	if(pos==sz(num1)) return 1;

	if(dp[pos][f1][f2][l1][l2][nz]!=-1) return dp[pos][f1][f2][l1][l2][nz];

	ll ans=0;
	ll lim1=1,lim2=0;
	if(f1==1) lim1 = num1[pos];
	if(f2==1) lim2 = num2[pos];

	rep(x,lim2,2) rep(y,0,lim1+1)
	{
		if(x==1 && y==0) continue;
		ll nnz=1;
		if(nz==0)
		{
			if((y==1 && x==0)||(y==0 && x==1)) continue; 
			else if(y==0) nnz=0;
			else nnz=1;
		}

		ll nf1 = 0,nf2=0;
		if(f1==1 && y==lim1 ) nf1=1;
		if(f2==1 && x==lim2 ) nf2=1;

		ans = (ans+fun(pos+1,nf1,nf2,x,y,nnz))%mod;
	}
	return dp[pos][f1][f2][l1][l2][nz]=ans;
}

int solve()
{

	memset(dp,-1,sizeof dp);

	ll l,r;cin>>l>>r;
	while(r) num1.pb(r%2),r/=2;
	while(l) num2.pb(l%2),l/=2;


	// while(sz(num1)<64) num1.pb(0);
	while(sz(num2)<sz(num1)) num2.pb(0);

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	// ll ans=0;
	// rep(st,0,65)
	// {
	// 	ans=ans+fun(st,)
	// }

	cout<<fun(0,1,1,0,0,0);

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