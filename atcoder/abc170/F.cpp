/*input
1 6 4
1 1 1 6
......
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

ll h,w,k;
ll stx,sty,fix,fiy;
vector<vector<char>> mat;
ll dx[] = {0,0,-1,1};
ll dy[] = {1,-1,0,0};

ll check(ll x,ll y)
{
	if(x>=0 && x<h && y>=0 && y<w && mat[x][y]!='@')return 1;
	return 0;
}

int solve()
{
	cin>>h>>w>>k;
	cin>>stx>>sty>>fix>>fiy;
	stx--,sty--,fix--,fiy--;

	// h=1000,w=1000,k=2000;
	// stx=0,sty=0,fix=999,fiy=999;

	mat.resize(h,vector<char> (w,'.'));
	rep(i,0,h)
	{
		string s;cin>>s;
		rep(j,0,w) mat[i][j]=s[j];
	}

	if(mat[stx][sty]=='@' || mat[fix][fiy]=='@') {
		cout<<"-1\n"; return 0;
	}

	priority_queue< pair<ll,pii> , vector< pair<ll,pii> > ,greater<pair<ll,pii>> > q;
	vvi dist(h,vi (w,inf));
	vvi vis (h,vi (w,0));


	dist[stx][sty]=0;
	q.push(mp(0,mp(stx,sty)));

	while(!q.empty())
	{
		ll d = q.top().F;
		pii cur = q.top().S;		
		q.pop();

		if(vis[cur.F][cur.S]==1) continue;
		vis[cur.F][cur.S]=1;
		// cout<<d<<" ";
		// debug_p(cur);
		
		rep(j,0,4)
		{
			rep(i,1,k+1)
			{
				ll nx = cur.F+i*dx[j];
				ll ny = cur.S+i*dy[j];

				if(check(nx,ny)==0) break;
				if(d+1<dist[nx][ny] && vis[nx][ny]==0)
				{
					dist[nx][ny]=d+1;
					q.push(mp(d+1,mp(nx,ny)));
				}
				else if(d+1>dist[nx][ny]) break;
			}
		}

	}

	if(dist[fix][fiy]>=inf) cout<<"-1";
	else cout<<dist[fix][fiy];
 
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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}