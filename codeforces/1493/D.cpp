/*input
4 3
1 6 8 12
1 12
2 3
3 3

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
const ll N = 2e5+5,mod = 1e9+7;
vi spd(N,-1);
void init(){

	for(ll i = 2;i<N;i++){
		if(spd[i]==-1){
			spd[i] = i;
			for(ll j = i*i;j<N;j+=i) if(spd[j]==-1) spd[j] = i;
		}
	}
}

vpii findPrimeDiv(ll x){
	vpii ans;
	while(x>1){
		ll p = spd[x];
		ll cnt=0;
		while(x%p==0){
			x/=p;
			cnt++;
		}
		ans.pb(mp(p,cnt));
	}
	return ans;
}

ll power(ll x,ll y)
{
	x%=mod;
	if(x<0) x+=mod;
	x%=mod;

	// y%=(mod-1) //valid only if mod is prime number; 

	ll ans=1;
	while(y)
	{
		if(y&1)
		{
			ans = (ans*x)%mod;
		} 
		y>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

ll inv(ll x){
	return power(x,mod-2);
}
		
ll n,q;
vi a;


int solve()
{
	cin>>n>>q;
	a.resize(n);
	rep(i,0,n) cin>>a[i];

	vector<map<ll,ll>> pd(n);
	rep(i,0,n){
		if(a[i]>1){
			vpii b = findPrimeDiv(a[i]);
			for(pii cur : b){
				pd[i][cur.F] = cur.S;
			}
		}
	}

	vpii query(q);
	rep(i,0,q){
		cin>>query[i].F>>query[i].S;
		query[i].F--;

		if(query[i].S>1){
			vpii b = findPrimeDiv(query[i].S);
			for(pii cur : b){
				pd[query[i].F][cur.F] += cur.S;
			}
		}
	}

	map<ll,ll> mn;
	rep(i,0,n){
		if(i==0) mn = pd[i];
		else{
			for(auto cur : pd[i]){
				if(mn.find(cur.F)!=mn.end()) mn[cur.F]=min(mn[cur.F],cur.S);
			}
			for(auto cur : mn){
				if(pd[i].find(cur.F)==pd[i].end()) mn[cur.F]= 0;
			} 
		}
	}
	ll g = 1;
	for(auto cur : mn) g = (g * power(cur.F,cur.S))%mod;

	vi ans(q);
	repr(i,q-1,-1){
		ans[i] = g;
		ll idx = query[i].F;
		ll x   = query[i].S;

		vpii b = findPrimeDiv(x);
		for(pii cur : b){
			pd[idx][cur.F] -= cur.S;
			if(pd[idx][cur.F] < mn[cur.F]){
				ll dif = mn[cur.F] - pd[idx][cur.F];

				ll divi =  power(cur.F,dif);
				g = (g * inv(divi))%mod;
				mn[cur.F] = pd[idx][cur.F];
			}
		}
	}

	rep(i,0,q) cout<<ans[i]<<"\n";
	return 0;
}

int main()
{

	init();

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