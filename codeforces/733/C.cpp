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

int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];

	ll m;cin>>m;
	vi b(m);
	rep(i,0,m) cin>>b[i];
		

	ll pos=1;
	vector<pair<ll,char>> ans;

	rep(i,0,m)
	{
		ll j = i;
		ll sum =a[j];
		while(j+1<sz(a) && sum<b[i]) j++,sum+=a[j];

		// whatis(sum);

		if(sum!=b[i])
		{
			pos = 0;
			break;
		}
		else
		{
			ll turn = j-i;
			while(turn)
			{
				ll mx=-1,idx=-1;
				rep(k,i,j+1)
				{
					if(mx<a[k]) mx=a[k],idx=k;
					else if(mx==a[k])
					{
						if((k-1>=i && a[k-1]<mx) || (k+1<=j && a[k+1]<mx) ) idx=k;
					}
				} 
				char c;
				ll nt;

				ll nx = idx+1;
				while(nx<=j && a[nx]==-1 ) nx++;

				ll pv = idx-1;
				while(pv>=i && a[pv]==-1 ) pv--;

				// whatis(idx);
				// whatis(nx);
				// whatis(pv);

				if(nx<=j && a[nx]<mx) c = 'R',nt=nx;
				else if(pv>=i && a[pv]<mx) c='L',nt=pv;
				else pos=0;

				if(pos==0) break;
				else
				{
					// whatis(nt);
					// whatis(idx);
					// debug_v(a);
					ll cnt=0;
					rep(k,i,idx+1) if(a[k]==-1) cnt++;
					a[idx]+=a[nt];
					a[nt]=-1;
					ans.pb(mp(idx-cnt,c));
				}

				turn--;
			}

			a[i]=b[i];
			rep(k,i+1,j+1) a[k]=-1;
			vi temp;
			rep(k,0,sz(a)) if(a[k]!=-1) temp.pb(a[k]);
			// debug_v(temp);
			a=temp;

		}
	}

	if(!pos || a!=b ) cout<<"NO\n";
	else
	{
		assert(a==b);
		cout<<"YES\n";
		rep(i,0,sz(ans)) cout<<ans[i].F+1<<" "<<ans[i].S<<"\n";
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