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

ll n,m;
vector<string> mat;

ll dx[] = {0,1,0,-1};
ll dy[] = {1,0,-1,0};
// right down left up;

ll check(ll x,ll y)
{
	if(x>=0 && y>=0 && x<n && y<m && mat[x][y]=='.') return 1;
	return 0;
}


int solve()
{
	cin>>n>>m;
	queue<pair<pii,ll>> q;
	mat.resize(n);
	rep(i,0,n)
	{
		string s;cin>>s;
		mat[i]=s;
	}

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(mat[i][j]=='.')
			{
				vi st;
				rep(k,0,4) if(check(i+dx[k],j+dy[k])==1) st.pb(k);
				if(sz(st)==1)
				{
					q.push(mp(mp(i,j),st[0]));

					pii p = mp(i,j);
					ll di = st[0];
					pii f = mp(p.F+dx[di],p.S+dy[di]);

					if(di==0) mat[p.F][p.S]='<',mat[f.F][f.S]='>';
					if(di==2) mat[p.F][p.S]='>',mat[f.F][f.S]='<';
					if(di==1) mat[p.F][p.S]='^',mat[f.F][f.S]='v';
					if(di==3) mat[p.F][p.S]='v',mat[f.F][f.S]='^';

				} 
			}
		}
	}


	while(!q.empty())
	{
		pii p = q.front().F;
		ll di = q.front().S;
		pii f = mp(p.F+dx[di],p.S+dy[di]);
		q.pop();

		rep(k1,0,4)
		{
		 	ll i = f.F+dx[k1];
		 	ll j = f.S+dy[k1];

		 	if(check(i,j)==1) 
		 	{
				vi st;
				rep(k,0,4) if(check(i+dx[k],j+dy[k])==1) st.pb(k);
				if(sz(st)==1)
				{
					q.push(mp(mp(i,j),st[0]));

					pii p1 = mp(i,j);
					ll di1 = st[0];
					pii f1 = mp(p1.F+dx[di1],p1.S+dy[di1]);
					if(di1==0) mat[p1.F][p1.S]='<',mat[f1.F][f1.S]='>';
					if(di1==2) mat[p1.F][p1.S]='>',mat[f1.F][f1.S]='<';
					if(di1==1) mat[p1.F][p1.S]='^',mat[f1.F][f1.S]='v';
					if(di1==3) mat[p1.F][p1.S]='v',mat[f1.F][f1.S]='^';

				} 

		 	}

		}
	}	

	rep(i,0,n) rep(j,0,m) if(mat[i][j]=='.') {cout<<"Not unique\n"; return 0;}
	rep(i,0,n) cout<<mat[i]<<"\n";
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