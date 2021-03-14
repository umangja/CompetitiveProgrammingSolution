/*input
10 10 10
2 7 10 4 1 5 9 8 6 3
9 7 6 2 4 10 1 3 5 8



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
const ll Nmax = 1e6+5;
vpii cnt(Nmax,mp(-1ll,-1ll));
ll N,M,Z; 
ll G,L;
vector< pair<pii,ll> > pp;

ll gcdExtended(ll a, ll b, ll &x, ll &y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        x = 0; 
        y = 1; 
        return b; 
    } 
 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, x1, y1); 
 
    x = y1 - (b/a) * x1; 
    y = x1; 
    return gcd; 
} 

// number of different is >= k
ll check(ll T){
	ll eq = 0;

	for(auto it  = pp.begin(); it!=pp.end(); it++){
		ll p1 = (it->F).F;
		ll p2 = (it->F).S;

		if(p1!=-1 && p2!=-1 && abs(p1-p2)%G==0){
			ll t = it->S;
			eq += (T/L) * 1 + ((T%L)>=t);
		}
	}

	return ((T - eq) >= Z);
}


int solve()
{
	cin>>N>>M>>Z;
	vi a(N),b(M);
	rep(i,0,N) cin>>a[i],cnt[a[i]].F = i;
	rep(i,0,M) cin>>b[i],cnt[b[i]].S = i;

	G = __gcd(N,M);
	L = (N*M)/G;


	for(int i=0;i<sz(cnt);i++){
		ll p1 = (cnt[i].F);
		ll p2 = (cnt[i].S);

		if(p1==-1 || p2==-1 || abs(p2-p1)%G!=0){
			continue;
		} 

		ll swaped = 0;
		if(p1 < p2) {
			swap(p1,p2);
			swap(N,M);
			swaped=1;
		}

		ll x,y;
		ll lambda = (p1 - p2)/G;
		gcdExtended(N,M,x,y);

		x*=lambda;
		y*=lambda;

		ll t = (p1 - N*x)%L;
		if(t<0) t+=L;

		t++;
		if(swaped) {
			swap(p1,p2);
			swap(N,M);
		}

		pp.pb(mp(mp(p1,p2),t));
	}


	ll Low = 0,high = inf;
	ll ans = -1;
	while(Low<high) {
		ll mid = Low + (high - Low)/2;
		ll temp = check(mid);
		if(temp==1){
			ans = mid;
			high = mid-1;
		} 
		else Low = mid + 1;
	}

	if(check(Low)==1) ans = Low;
	cout<<ans<<"\n";
	// cout<<ChineseRemainderTheorem(6,7,2,5);


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