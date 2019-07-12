/*input
9m 7m 1m
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


ll v[3][10];
int solve()
{

	rep(i,0,3)
		rep(j,0,10)
			v[i][j]=0;

	string s1,s2,s3;cin>>s1>>s2>>s3;
	map< char,ll > m;
	m['m']=0;
	m['p']=1;
	m['s']=2;

	v[m[s1[1]]][s1[0]-'0']++;
	v[m[s2[1]]][s2[0]-'0']++;
	v[m[s3[1]]][s3[0]-'0']++;

	ll ans=2;
	rep(i,0,3)
	{
		rep(j,0,10)
		{
			if(v[i][j]==3)
				ans = 0;
			if(v[i][j]==2)
				ans=min(ans,(ll)1);
			if(v[i][j]==1)
				ans=min(ans,(ll)2);
		}
	}

	rep(i,0,3)
	{
		rep(j,0,8)
		{
			if(v[i][j]==1 && v[i][j+1]==1 &&v[i][j+2]==1)
				ans=0;
		}
		rep(j,0,9)
		{
			if(v[i][j]==1 && v[i][j+1]==1)
				ans=min(ans,(ll)1);
		}
		rep(j,0,8)
		{
			if(v[i][j]==1 && v[i][j+2]==1)
				ans=min(ans,(ll)1);
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

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}