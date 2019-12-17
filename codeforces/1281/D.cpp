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
	vvi mat(n,vi (m));
	ll f=0;
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m) if(s[j]=='A') mat[i][j]=1; else mat[i][j]=0,f++;
	}

	ll ans=-1;
	if(f==0) ans=0;
	else if(f==n*m) ans=-1;
	else
	{
		ll g=0;
		rep(i,0,n)
		{
			ll cnt=0;
			rep(j,0,m) if(mat[i][j]==1) cnt++;
			if(cnt==m)
			{
				ll cnt0=0;
				rep(i1,0,i) rep(j1,0,m) if(mat[i1][j1]==0) cnt0++;
				if(cnt0==0) { cout<<1<<"\n"; return 0; }
				cnt0=0;
				rep(i1,i+1,n) rep(j1,0,m)  if(mat[i1][j1]==0) cnt0++;
				if(cnt0==0) { cout<<1<<"\n"; return 0; }
				g=1;
			}
		}

		rep(j,0,m)
		{
			ll cnt=0;
			rep(i,0,n) if(mat[i][j]==1) cnt++;
			if(cnt==n)
			{
				ll cnt0=0;
				rep(j1,0,j) rep(i1,0,n) if(mat[i1][j1]==0) cnt0++;
				if(cnt0==0) { cout<<1<<"\n"; return 0; }
				cnt0=0;
				rep(j1,j+1,m) rep(i1,0,n)  if(mat[i1][j1]==0) cnt0++;
				if(cnt0==0) { cout<<1<<"\n"; return 0; }		
				g=1;
			}
		}

		if(g==1 || mat[0][0]==1 || mat[0][m-1]==1  || mat[n-1][0]==1  || mat[n-1][m-1]==1 )
		{
			cout<<"2\n";
			return 0;
		}

		rep(i,0,n)
		{
			ll cnt=0;
			rep(j,0,m) if(mat[i][j]==1) cnt++;
			if(cnt>0)
			{
				if(mat[i][0]==1 || mat[i][m-1]==1 || i==0 || i==n-1) {cout<<"3\n"; return 0;}
			}
		}

		cout<<"4\n";
		return 0;

	}

	if(ans==-1) cout<<"MORTAL\n";
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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}