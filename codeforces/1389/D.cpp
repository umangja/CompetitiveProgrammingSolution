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

ll Intersection(ll l1,ll r1,ll l2,ll r2)
{
	assert(r1>=l1);
	assert(r2>=l2);

	if(l2>r1 || l1>r2) return 0;
	if(l2>=l1 && r2<=r1) return r2-l2;
	if(l1>=l2 && r1<=r2) return r1-l1;
	return min(r1,r2) - max(l1,l2);
}


int solve()
{
	ll n,k;cin>>n>>k;
	ll l1,r1;cin>>l1>>r1;
	ll l2,r2;cin>>l2>>r2;

	if( l1>l2  ) swap(l1,l2),swap(r1,r2);
	ll ans=0;
	vi cost(3);
	// not intersecting 
	if(r1<l2) cost[0] = l2-r1+1;
	else cost[0] = inf;
	// 1 intersecting
	cost[1] =  1;
	// 2 same
	cost[2] = 2;

	ll len = Intersection(l1,r1,l2,r2);
	k-=n*len;
	if(k<=0)
	{
		cout<<"0\n";
		return 0;
	}
	
	if(l1==l2 && r1==r2)
	{
		ans = 2*k;
		cout<<ans<<"\n";
		return 0;
	}


	// cost, { type, opdone  };
	priority_queue< pair<ll, pii > ,vector< pair<ll,pii> > ,greater<pair<ll,pii>> > pq;

	rep(i,0,n)
	{
		if(cost[0]!=inf) pq.push(mp(cost[0],mp(0,0)));
		else if(l1==l2 && r1==r2) pq.push(mp(cost[2],mp(2,0)));
		else pq.push(mp(cost[1],mp(1,0)));
	}

	ll reqToMakeSame = abs(l1-l2) + abs(r1-r2);

	// cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";

	// whatis(k);
	// whatis(cost[0]);





	ll ansf = inf;
	while( k>0 && !pq.empty() )
	{
		pair<ll,pii> p = pq.top();
		pq.pop();

		// whatis(p.S.F);

		if(p.S.F==2)
		{
			ansf = min(ansf,ans+2*k);
		} 
		else if(p.S.F==1)
		{
			ll mn = min(k,reqToMakeSame-p.S.S);
			ans+=mn;
			k-=mn;
			// whatis(mn);
			// whatis(ans);
			// whatis(k);
			ll opDone = p.S.S + mn;
			if(opDone==reqToMakeSame) pq.push(mp(cost[2],mp(2,opDone)));
			else pq.push(mp(cost[1],mp(1,opDone)));
		}
		else
		{
			ans+=p.F;
			k--;
			ll opDone = p.S.S + p.F;

			if(opDone==reqToMakeSame) pq.push(mp(cost[2],mp(2,opDone)));
			else pq.push(mp(cost[1],mp(1,opDone)));
		}
	}

	if(k>0) ans+=2*k;
	ansf=min(ansf,ans);
	cout<<ansf<<"\n";




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