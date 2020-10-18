/*input
1
0 -9
16 7 12 26 25 30
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
#define inf			(ll)3e18
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

vi dirx = {0,1,0,-1,-1, 0,1};
vi diry = {0,1,1, 0,-1,-1,0};
vi cost(7,0);

ll fun(ll fx,ll fy,ll sx=0,ll sy=0)
{
	ll ans = inf;
	ll dx = fx-sx;
	ll dy = fy-sy;

	if(dx>=0 && dy>=0)
	{
		ans=dx*cost[2]+dy*cost[6];
		ll mn = min(dx,dy);
		ll mx = max(dx,dy); 


		if(dx==mn) ans=min(ans,mn*cost[1]+(dy-mn)*cost[6]);
		if(dy==mn) ans=min(ans,mn*cost[1]+(dx-mn)*cost[2]);

		if(dx==mx) ans=min(ans,mx*cost[1]+(mx-dy)*cost[3]);
		if(dy==mx) ans=min(ans,mx*cost[1]+(mx-dx)*cost[5]);

	} 

	else if(dx<=0 && dy<=0)
	{
		dx=abs(dx);dy=abs(dy);
		ans=dx*cost[5]+dy*cost[3];
		ll mn = min(dx,dy);
		ll mx = max(dx,dy); 

		if(dx==mn) ans=min(ans,mn*cost[4]+(dy-mn)*cost[3]);
		if(dy==mn) ans=min(ans,mn*cost[4]+(dx-mn)*cost[5]);

		if(dx==mx) ans=min(ans,mx*cost[4]+(mx-dy)*cost[6]);
		if(dy==mx) ans=min(ans,mx*cost[4]+(mx-dx)*cost[2]);
	}


	else if(dx>=0 && dy<=0)
	{
		dx=abs(dx);dy=abs(dy);
		// cout<<"Yes\n";
		ans=min(ans,dx*cost[2]+dy*cost[3]);
		ans=min(ans,dx*cost[1]+(dy+dx)*cost[3]);
		ans=min(ans,dy*cost[4]+(dy+dx)*cost[2]);
	}


	else if(dx<=0 && dy>=0)
	{
		dx=abs(dx);dy=abs(dy);
		// cout<<"Yes\n";
		ans=min(ans,dx*cost[5]+dy*cost[6]);
		ans=min(ans,dx*cost[4]+(dy+dx)*cost[6]);
		ans=min(ans,dy*cost[1]+(dy+dx)*cost[5]);
	}



	return ans;
}

int solve()
{
	ll fx,fy;
	cin>>fx>>fy;
		
	rep(i,1,7) cin>>cost[i];
	cout<<fun(fy,fx)<<"\n";



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