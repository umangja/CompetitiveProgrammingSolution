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

const ll N=11,M=1001;
ll n,m,k;
vvi mat(N,vi (M,0));
ll ans_mn;

ll fun(ll mask)
{
	vi pos1;
	ll f=0;
	rep(i,0,10) if(((mask>>i)&1)==1)
	{
		pos1.pb(i);
		if(i==n-1) f=1;
	} 

	ll temp_ans=sz(pos1);
	if(f==0) pos1.pb(n-1);
	ll last=0;

	vvi no1s;
	rep(ii,0,sz(pos1))
	{
		vvi mat1;
		rep(j,last,pos1[ii]+1)
		{
			vi temp(m);
			rep(kk,0,m) temp[kk]=mat[j][kk];
			mat1.pb(temp);
		}

		vi no1(m,0);
		rep(j,0,m) rep(i,0,sz(mat1)) no1[j]+=mat1[i][j];

		no1s.pb(no1);
		last = pos1[ii]+1;
	}

	vi cnt(sz(no1s),0);

	// if(mask==7)
	// {
	// 	rep(i,0,sz(no1s))
	// 	{
	// 		rep(j,0,m) cout<<no1s[i][j]<<" ";
	// 		cout<<"\n";
	// 	}
	// }

	rep(j,0,m)
	{	
		f=0;
		rep(i,0,sz(no1s)) if(cnt[i]+no1s[i][j]>k) f=1;
		if(f==0) rep(i,0,sz(no1s)) cnt[i]+=no1s[i][j];
		else
		{
			temp_ans++;
			rep(i,0,sz(no1s)) cnt[i]=no1s[i][j];
			rep(i,0,sz(no1s)) if(cnt[i]>k) return inf;

		}
		// 	if(mask==7)
		// 	{
		// 		whatis(j);
		// 		rep(i,0,sz(no1s)) cout<<cnt[i]<<" ";
		// 	}
		// cout<<"\n";
	}
	// whatis(sz(no1s));
	// whatis(sz(no1s[0]));



	// whatis(mask);
	// whatis(temp_ans);
	return temp_ans;

}

int solve()
{
	cin>>n>>m>>k;
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m) mat[i][j] = s[j]-'0';
	} 

	ans_mn = (n-1) + (m-1);
	for(ll i=0;i<(1<<(n-1));i++) ans_mn = min(ans_mn,fun(i));
	cout<<ans_mn<<"\n";
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