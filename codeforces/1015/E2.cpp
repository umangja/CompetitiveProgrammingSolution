/*input
6 8
....*...
...**...
..*****.
...**...
....*...
........

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
const ll N = 1005;
ll up[N][N],down[N][N],righ[N][N],lef[N][N],h[N][N],v[N][N];
vvi mat(N,vector<ll>(N,0)),ans(N,vector<ll>(N,0));
int solve()
{
	ll n,m;cin>>n>>m;
	rep(i,0,n) rep(j,0,m) {char c;cin>>c;if(c=='*') mat[i][j]=1;}

	rep(j,0,m) rep(i,0,n) if(mat[i][j]==1) up[i][j]=mat[i][j]+(i-1>=0?up[i-1][j]:0);
	rep(j,0,m) for(ll i=n-1;i>=0;i--) if(mat[i][j]==1) down[i][j]=mat[i][j]+down[i+1][j];
	rep(i,0,n) rep(j,0,m) if(mat[i][j]==1) lef[i][j]=mat[i][j]+(j-1>=0?lef[i][j-1]:0);
	rep(i,0,n) for(ll j=m-1;j>=0;j--) if(mat[i][j]==1) righ[i][j]=mat[i][j]+righ[i][j+1];

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(mat[i][j]==1)
			{
				ll siz = min(min(up[i][j],down[i][j]),min(righ[i][j],lef[i][j]))-1;
				if(siz>0)	ans[i][j]=siz;
			}
		}
	}

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(ans[i][j])
			{
				h[i-ans[i][j]][j]++;
				h[i+ans[i][j]+1][j]--;
				v[i][j-ans[i][j]]++;
				v[i][j+ans[i][j]+1]--;
			}
		}
	}
	rep(i,0,n) rep(j,1,m) v[i][j]+=v[i][j-1];
	rep(j,0,m) rep(i,1,n) h[i][j]+=h[i-1][j];
	
	ll mat2[N][N];
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll f=(mat[i][j]!=(mat2[i][j]=(v[i][j]>0 || h[i][j]>0)));
			if(f)
			{
				cout<<"-1";
				return 0; 
			}
		}
	}			
	ll count=0;
	rep(i,0,n) rep(j,0,m) count+=(ans[i][j]>0);
	cout<<count<<"\n";
	rep(i,0,n) rep(j,0,m) if(ans[i][j]) cout<<i+1<<" "<<j+1<<" "<<ans[i][j]<<"\n";
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