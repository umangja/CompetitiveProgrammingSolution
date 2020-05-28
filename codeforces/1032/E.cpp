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

#define ll          int
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

int solve()
{
	ll n;cin>>n;
	vi a(n);
	map<ll,ll> cnt;
	rep(i,0,n) cin>>a[i],cnt[a[i]]++;
	sort(a.begin(), a.end());


	if(sz(cnt)<=2)
	{
		cout<<n<<"\n";
		return 0;
	}


	vpii b;
	all(it,cnt) b.pb(mp(it->F,it->S));
	vi pf(sz(b),0);
	rep(i,0,sz(b)) pf[i]=b[i].S+(i-1>=0?pf[i-1]:0);

	ll nd=n;
	n=sz(b);

	vvi  dp1(nd+1,vi (1e4+1,0));
	vvi  dp2(nd+1,vi (1e4+1,0));
	
	ll ans = 1;
	dp1[0][0]=1;
	rep(i,0,n)
	{
		rep(k,1,nd+1) rep(s,1,(ll)1e4+1)
		{
			if(i==0)
			{
				if(k>pf[i]) dp1[k][s]=0;
				else dp1[k][s]=(((b[i].F)*k)==s);
			}
			else
			{
				if(k>pf[i]) dp2[k][s]=0;
				else
				{
					dp2[k][s] = dp1[k][s];
					rep(j,1,b[i].S+1)
					{
						if(dp2[k][s]>=2) break;
						dp2[k][s]+=(s-j*b[i].F>=0 && k-j>=0 ?dp1[k-j][s-j*b[i].F]:0);
					}
				}
				dp2[k][s] = min(2,dp2[k][s]);
			}
		}

		if(i!=0)
		{
			dp1=dp2;
			dp1[0][0]=1;
		}

		// whatis(dp1[1][1]);
		

	}
	rep(k,1,nd+1) rep(s,1,1e4+1) if(s%k==0 && cnt[s/k]>=k && dp1[k][s]==1) { ans=max(ans,k);}
	cout<<ans<<"\n";

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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}