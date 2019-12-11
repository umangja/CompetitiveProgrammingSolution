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

const ll N = 1004;
vector< vector<char> > tab(N,vector< char > (N));
map<char,char> m;

vi dx = {-1,0,1,0};
vi dy = {0,1,0,-1};

ll fuck=0;
ll dp[N][N];
ll n,mm;

void dfs(ll i,ll j)
{
	if(dp[i][j]) return ;

	dp[i][j] = inf;
	ll l=1;
	rep(k,0,4)
	{
		if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<mm && m[tab[i][j]]==tab[i+dx[k]][j+dy[k]])
		{
			dfs(i+dx[k],j+dy[k]);
			l=max(l,dp[i+dx[k]][j+dy[k]]+1);
		}
	}
	dp[i][j]=min(dp[i][j],l);
	return ;
}

int solve()
{
	m['D'] = 'I';
	m['I'] = 'M';
	m['M'] = 'A';
	m['A'] = 'D';

	cin>>n>>mm;
	rep(i,0,n) rep(j,0,mm) cin>>tab[i][j];


	ll ans=0;
	rep(i,0,n) rep(j,0,mm) if(tab[i][j]=='D' && dp[i][j]==0)
	{
		dfs(i,j);
		ans=max(ans,dp[i][j]);
	} 

	ans/=4;
	if(ans*4>=inf) cout<<"Poor Inna!\n";
	else if(ans==0) cout<<"Poor Dima!\n";
	else cout<<ans<<"\n";
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