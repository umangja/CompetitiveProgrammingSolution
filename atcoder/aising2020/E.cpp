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

struct node
{
	ll dif,K,B;
	node(ll KK,ll LL,ll RR):dif(KK),K(LL),B(RR) {};
};

vector<node> camel1,camel2;

bool cmp(const node &n1,const node &n2)
{
	if(n1.dif==n2.dif) return n1.K>n2.K;
	return n1.dif>n2.dif;
}

bool cmp2(const node &n1,const node &n2)
{
	if(n1.dif==n2.dif) return n1.K<n2.K;
	return n1.dif>n2.dif;
}

int solve()
{

	camel1.clear();
	camel2.clear();

	ll n;cin>>n;
	ll ans=0;
	set<ll> st;
	rep(i,0,n)
	{
		st.insert(i+1);	
		ll k,l,r;cin>>k>>l>>r;

		if(l>r) camel1.pb(node(l-r,k,l));
		else if(r>l) camel2.pb(node(r-l,k,r));
		else ans+=l;
	}

	sort(camel1.begin(), camel1.end(),cmp);
	sort(camel2.begin(), camel2.end(),cmp2);

	ll cnt=0;
	rep(i,0,sz(camel1))
	{
		// whatis(camel1[i].dif);
		auto it = st.upper_bound(camel1[i].K);
		if(it==st.begin()) ans+=camel1[i].B-camel1[i].dif;
		else
		{
			it--;
			cnt++;
			ans+=camel1[i].B;
			st.erase(it);
		}
	}

	rep(i,1,n+1) st.insert(i);
	rep(i,1,cnt+1) st.erase(i); 



	rep(i,0,sz(camel2))
	{
		// whatis(camel2[i].dif);
		auto it = st.upper_bound(camel2[i].K);
		if(it==st.end()) ans+=camel2[i].B-camel2[i].dif;
		else
		{
			ans+=camel2[i].B;
			st.erase(it);
		}
	}

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
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}