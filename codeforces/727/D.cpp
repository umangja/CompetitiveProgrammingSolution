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
const ll N = 6;
int solve()
{
	map<string,ll> m;
	map<ll,string> mr;
	m["S"]=0;
	m["M"]=1;
	m["L"]=2;
	m["XL"]=3;
	m["XXL"]=4;
	m["XXXL"]=5;


	all(it,m) mr[it->S]=it->F;

	vi a(N);
	rep(i,0,N)	 cin>>a[i];

	ll n;cin>>n;
	vector<pair<pii,ll>> req;
	vi ans(n,-1);
	ll pos=1;

	rep(i,0,n)
	{
		string s;cin>>s;
		ll dob=0;
		rep(j,0,sz(s)) if(s[j]==',') 
		{
			string s1 = s.substr(0,j);
			string s2 = s.substr(j+1,sz(s)-j-1);
			req.pb(mp(mp(m[s1],m[s2]),i));
			dob=1;
			break;
		}

		if(!dob)
		{
			if(a[m[s]]>0) a[m[s]]--,ans[i]=m[s];
			else pos=0;
		}
	}


	if(pos)
	{
		// debug_v(a);
		// rep(i,0,sz(req)) cout<<req[i].F.F<<" "<<req[i].F.S<<"\n";
		vi vis(sz(req),0);

		rep(i,0,N)
		{
			if(i-1>=0)
			{
				rep(j,0,sz(req)) 
				{
					// cout<<req[j].F.F<<" "<<req[j].F.S<<" "<<a[i-1]<<"\n";
					if(req[j].F.F==i-1 && req[j].F.S==i && vis[j]==0 && a[i]>0)
					{
						vis[j]=1;
						ans[req[j].S]=i;
						a[i]--;
					}
				}
			}

			if(i+1<N)
			{
				rep(j,0,sz(req)) 
				{
					if(req[j].F.F==i && req[j].F.S==i+1 && vis[j]==0 && a[i]>0)
					{
						vis[j]=1;
						ans[req[j].S]=i;
						a[i]--;
					}
				}	
			}
		}


		rep(i,0,sz(req)) if(vis[i]==0) 
		{
			// whatis(i);
			pos=0;
		}


		if(pos)
		{
			cout<<"YES\n";
			rep(i,0,n) cout<<mr[ans[i]]<<"\n";
		}
		else cout<<"NO\n";
	}
	else cout<<"NO\n";



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