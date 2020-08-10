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

vvi fun(vvi mat)
{
	ll n = mat.size();
	ll m = mat[0].size();
	vvi ans(m,vi (n));
	rep(i,0,m) rep(j,0,n) ans[i][j] = mat[j][i];
	return ans;
}

inline ll getBit(ll x,ll j)
{
	return (x>>j)&1;
}

int solve()
{
	ll n,m;cin>>n>>m;
	vvi mat1(n,vi (m));
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m) mat1[i][j]=(s[j]-'0');
	}

	if(min(n,m)>3) 
	{
		cout<<"-1\n";
		return 0;
	}

	vvi mat;
	if(n>m)
	{
		mat = fun(mat1);
		swap(n,m);
	} 
	else mat = mat1;

	if(n==1)
	{
		cout<<"0\n";
		return 0;
	}

	// debug_v_v(mat);

	ll totMask = (1<<n);
	vvi dp(m,vi (totMask,INT_MAX));
	vvi pos(totMask,vi (totMask,0));

	rep(lastMask,0,totMask)
	{
		rep(curMask,0,totMask)
		{
			ll cnt1 = getBit(lastMask,0) + getBit(lastMask,1) + getBit(curMask,0)+getBit(curMask,1);
			pos[lastMask][curMask]=(cnt1%2);

			if(n==3)
			{
				cnt1 = getBit(lastMask,1) + getBit(lastMask,2) + getBit(curMask,1)+getBit(curMask,2);
				pos[lastMask][curMask]&=(cnt1%2);
			}

		}
	}

	// debug_v_v(pos);


	rep(j,0,m)
	{
		rep(mask,0,totMask)
		{
			ll cost = 0;
			rep(i,0,n) cost+=(mat[i][j]!=getBit(mask,i));
			if(j==0) dp[j][mask] = cost;
			else rep(lastMask,0,totMask) if(pos[lastMask][mask]) dp[j][mask]=min(dp[j][mask],dp[j-1][lastMask]+cost);
			// cout<<j<<" "<<mask<<" "<<dp[j][mask]<<"\n";
		}
	}
	ll ans = dp[m-1][0];
	rep(j,0,totMask) ans=min(ans,dp[m-1][j]); 
	cout<<ans<<"\n";



	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}