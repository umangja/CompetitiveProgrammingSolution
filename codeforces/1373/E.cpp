/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll          long long int
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

const ll N = 151,L = 21,F = 11,F2=2;
vector< vector< vector<vector<string>> > > dp(N,vector<vector<vector<string>>> (L,vector<vs> (F,vs (F2,"-2"))));
vvi dp2(10,vi (10,0));
ll k;
// ll cnt=0;
string fun(ll n,ll l,ll c,ll last)
{
	if(dp[n][l][c][last]!="-2") return dp[n][l][c][last];
	string ans = "9999999999999999999999999999999999999999";

	if(n==0)
	{
		if(last==1) return dp[n][l][c][last]="";
		else
		{
			if(n==c) return dp[n][l][c][last]="";
			else return dp[n][l][c][last]="-1";
		}
	}

	if(l==0)
	{
		if(c==n) return dp[n][l][c][last]="";
		else return dp[n][l][c][last]="-1";
	} 

	// cout<<n<<" "<<l<<" "<<c<<" "<<last<<"\n";

	for(ll x=0;x<=9;x++)
	{
		ll s = 0;
		if(last==1) s+=dp2[x][k];
		else  s+= c*((x+1<10?x+1:0)) + (k+1-c)*x;

		if(s>n) continue;


		ll nc = 0;

		if(last==1) nc=max(0ll,k+1+x-10);
		else 
		{
			if(c!=0 && x==9) nc=c;
			else nc=0;
		}
		// if(x==4) whatis(nc);

		string temp = fun(n-s,l-1,nc,0);
		if(temp=="-1") continue;
		temp+=(char)('0'+x);
		ll j=0;
		rep(i,0,sz(temp)) if(temp[i]=='0') j++; else break;
		temp=temp.substr(j,n-j);
		if(sz(temp)<sz(ans) || (sz(temp)==sz(ans) && temp<ans) ) ans=temp;
		// if(l==7)
		// {
		// 	whatis(temp);
		// 	whatis(ans);
		// } 
	}

	if(sz(ans)>=20) ans="-1";
	return dp[n][l][c][last]=ans;
}

int solve()
{
	ll n;
	cin>>n>>k;

	rep(i1,0,N) rep(i2,0,L) rep(i3,0,F) rep(i4,0,F2) dp[i1][i2][i3][i4]="-2";

	if(k==0)
	{
		string ans = "";
		while(n)
		{
			ll t = min(n,9ll);
			ans+=(char)(t+'0');
			n-=t;
		}
		sort(ans.begin(), ans.end());
		cout<<ans<<"\n";
		return 0;
	}

	fun(n,20,0,1);
	string ans = dp[n][20][0][1];
	if(ans=="") ans="0";
	cout<<ans<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	rep(x,0,10)
	{
		rep(k1,0,10)
		{
			ll cur = x;
			rep(cnt,0,k1+1) dp2[x][k1]+=cur,cur+=1,cur%=10;
		}
	}

	// whatis(dp2[4][7]);



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