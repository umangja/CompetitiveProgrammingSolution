/*input
2
6 7 4
10 7 12
12 30 7
1 1 1
3247834 10298779 625324


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

ll fun(ll R,ll P)
{
	if(R==0) return 0;
	ll ans=0;
	// rep(x,0,R+1) ans+=x/P;
	
	ll num = (R)/P-1;
	// whatis(num);
	ans+=(((num)*(num+1))/2)*P;
	ans+=(R%P+1)*(R/P);
	return ans; 
}

int solve()
{
	ll d,m,w;cin>>m>>d>>w;
	// x,y belong to [1,min(m,d)] ans y>x

	ll R = min(m,d);
	ll L = 1;
	ll ans=0;
	ll P = w;
	ll Q = d-1;

	ll g = __gcd(P,Q);
	P/=g;
	Q/=g;

	ll V = P;

	ll D = R-V;

	ll ans2=0;
	// rep(x,L,R+1) if(D-x>=0) ans2+=(D-x)/P+1;
	// x going from [max(D-R,0ll),D-L] for each x find 
	ll NL = max(D-R,0ll);
	ll NR = D-L;

	if(NR<0)
	{
		cout<<"0\n";
		return 0;
	}

	// whatis(NL);
	// whatis(NR);
	// whatis(P);

	ans2 += fun(NR,P) - (NL-1>=0?fun(NL-1,P):0);
	cout<<ans2+NR-NL+1<<"\n";
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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}