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
const ll N = 1e3+5;
vvi bit(N,vi (N,0));
void add(ll x,ll y,ll val)
{
	for(ll i = x+1;i<N;i+=(i&-i))
		for(ll j = y+1;j<N;j+=(j&-j)) 
			bit[i][j]+=val;
	return ;
}

void range_add(ll x1,ll y1,ll x2,ll y2,ll val)
{
	add(x1,y1,val);
	add(x2+1,y2+1,val);
	add(x2+1,y1,-val);
	add(x1,y2+1,-val);
}

ll query(ll x,ll y)
{
	ll ans=0;
	for(ll i = x+1;i>0;i-=(i&-i))
		for(ll j = y+1;j>0;j-=(j&-j)) ans+=bit[i][j];
	return ans;
}

int solve()
{

	ll n,m;cin>>n>>m;
	vvi mat(n,vi (m,0));
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,m) mat[i][j] = (s[j]=='*');
	}

	vvi up(n,vi (m,0)),down(n,vi (m,0)),right(n,vi (m,0)),left(n,vi (m,0));
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(mat[i][j]==0) continue;
			else
			{
				ll k = j;
				while(k<m && mat[i][k]==mat[i][j]) k++;
				rep(k1,j,k) right[i][k1] = k-k1;
				j=k;
			}
		}

		repr(j,m-1,-1)
		{
			if(mat[i][j]==0) continue;
			else
			{
				ll k = j;
				while(k>=0 && mat[i][k]==mat[i][j]) k--;
				repr(k1,j,k) left[i][k1]=k1-k;
				j=k;
			}
		}
	}


	rep(j,0,m)
	{
		rep(i,0,n)
		{
			if(mat[i][j]==0) continue;
			else
			{
				ll k = i;
				while(k<n &&  mat[k][j]==mat[i][j]) k++;
				rep(k1,i,k) down[k1][j]=k-k1;
				// down[i][j] = k-i;
				i=k;
			}
		}

		repr(i,n-1,-1)
		{
			if(mat[i][j]==0) continue;
			else
			{
				ll k = i;
				while(k>=0 &&  mat[k][j]==mat[i][j]) k--;
				repr(k1,i,k) up[k1][j]=k1-k;
				// up[i][j] = abs(k-i);
				i=k;
			}
		}
	}

	// debug_v_v(left);

	vector< pair< pii,ll > > ans;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll len = min({up[i][j],down[i][j],right[i][j],left[i][j]});
			if(len>=2)
			{
				ans.pb(mp(mp(i,j),len-1));
				range_add(i,j,i+len-1,j,1);
				range_add(i-len+1,j,i,j,1);
				range_add(i,j,i,j+len-1,1);
				range_add(i,j-len+1,i,j,1);
			}
		}
	}

	ll ok=1;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			ll t = query(i,j);
			if(!((mat[i][j]==0 && t==0 )|| (mat[i][j]!=0 && t>0) ) ) ok=0;
		}

	}

	if(!ok) cout<<"-1\n";
	else 
	{
		cout<<sz(ans)<<"\n";
		rep(i,0,sz(ans)) cout<<ans[i].F.F+1<<" "<<ans[i].F.S+1<<" "<<ans[i].S<<"\n";
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