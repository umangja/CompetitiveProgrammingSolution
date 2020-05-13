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
#define inf			(long long int)1e18
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
const ll N = 1e3+3;
vvi mat;
vvi dist;
ll n,m;
ll dx[] = {-1,0,1,0};
ll dy[] = {0,-1,0,1};

void bfs()
{
	set<pair<ll,pii>> st;
	rep(i,0,n) rep(j,0,m) rep(k,0,4)
	{
		ll x = i+dx[k];
		ll y = j+dy[k];

		if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==mat[i][j])
		{
			dist[i][j]=0;
			dist[x][y]=0;
			st.insert(mp(0,mp(x,y)));
			st.insert(mp(0,mp(i,j)));
			break;
		} 
	}

	while(!st.empty())
	{
		auto it = st.begin();
		pii cur = it->S;
		ll  d   = it->F;

		st.erase(it);


		rep(i,0,4)
		{
			ll x = cur.F+dx[i];
			ll y = cur.S+dy[i];

			if(!(x>=0 && x<n && y>=0 && y<m)) continue;

			ll nd = d+1;
			if(nd<dist[x][y])
			{
				st.erase(mp(dist[x][y],mp(x,y)));
				dist[x][y] = nd;
				st.insert(mp(dist[x][y],mp(x,y)));
			}
		}
	}

	return ;

}

int solve()
{
	ll t;
	cin>>n>>m>>t;
	mat.assign(n,vi (m,0));
	dist.assign(n,vi (m,10000));
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m) mat[i][j] = s[j]-'0';
	}

	bfs();
	while(t--)
	{
		long long int x,y;
		long long int p;
		cin>>x>>y>>p;
		x--,y--;
		long long int d = (dist[x][y]==10000?inf+6:(long long int)dist[x][y]); 
		// whatis(d);
		if(p<=d) cout<<mat[x][y]<<"\n";
		else
		{
			long long int ch = (p - d)%2;
			if(ch) cout<<(mat[x][y]^1)<<"\n";
			else cout<<mat[x][y]<<"\n";
		}
	}
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