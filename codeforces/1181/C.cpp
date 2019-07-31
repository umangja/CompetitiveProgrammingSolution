/*input
10 10
itttrrrnnn
bbbbpppkdv
bbbbpppkzv
bbbbpppkzv
bbbbpppbbv
ippeerrsss
ippeerrsss
ibbeeeesss
iiieeeeeef
llorrrrvzz
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

const ll N = 1005;
vector<vector<char> > mat(N,vector<char> (N,'#'));
ll height_up[N][N];
ll height_down[N][N];
ll rgt[N][N];

int solve()
{
	ll n,m;cin>>n>>m;
	rep(i,1,n+1) rep(j,1,m+1){
		cin>>mat[i][j];
		if(mat[i][j]==mat[i][j-1]) rgt[i][j]=rgt[i][j-1]+1;
		else rgt[i][j]=1;
	}

	rep(j,1,m+1) rep(i,1,n+1){
		if(mat[i][j]==mat[i-1][j]) height_up[i][j]=height_up[i-1][j]+1;
		else height_up[i][j]=1;
	}


	rep(j,1,m+1) for(ll i=n;i>=1;i--) {
		if(mat[i][j]==mat[i+1][j]) height_down[i][j]=height_down[i+1][j]+1;
		else height_down[i][j]=1;
	}

	// rep(i,1,n+1) {rep(j,1,m+1) cout<<height_up[i][j]<<" ";cout<<"\n";}
	ll ans=0;
	rep(i,1,n)
	{
		rep(j,1,m+1)
		{
			if(mat[i][j]!=mat[i+1][j])
			{
				ll h1 = height_up[i][j];
				if(height_up[i-h1][j]>=h1 && height_down[i+1][j]>=h1)
				{
					ll mn=inf;
					for(ll k = max(i-2*h1+1,(ll)1);k<=min(i+h1,n);k++) mn=min(mn,rgt[k][j]);
					ans+=mn; 
				}

			}
		}
	}

	cout<<ans;

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