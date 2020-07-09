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

	vpii fd,sd;
	rep(i,0,n)
	{
		ll j = i;
		while(j<n && a[j]==a[i]) j++;
		fd.pb(mp(a[i],j-i));
		i = j-1;
	}

	rep(i,0,m)
	{
		ll j = i;
		while(j<m && b[j]==b[i]) j++;
		sd.pb(mp(b[i],j-i));
		i=j-1;
	}


	vi ans;
	vpii fid;
	ll cur1=0,cur2=n;
	if(fd[0].F==sd[0].F)
	{
		ll idx = 0;
		while(idx<sz(fd) && idx<sz(sd))
		{
			rep(cnt,0,fd[idx].S) ans.pb(cur1++);
			rep(cnt,0,sd[idx].S) ans.pb(cur2++);
			fid.pb(mp(fd[idx].F,fd[idx].S+sd[idx].S));
			idx++;
		}

		while(idx<sz(fd))
		{
			rep(cnt,0,fd[idx].S) ans.pb(cur1++);
			fid.pb(fd[idx++]);
		} 
		while(idx<sz(sd))
		{
			rep(cnt,0,sd[idx].S) ans.pb(cur2++);
			fid.pb(sd[idx++]);
		} 
	}
	else
	{
		if(sz(fd)==sz(sd) && fd[0].F==1) swap(fd,sd),swap(cur1,cur2);
		if(sz(fd)!=sz(sd) && sz(fd)<sz(sd)) swap(fd,sd),swap(cur1,cur2);
		ll idx1 = 0,idx2=0;
		
		rep(cnt,0,fd[idx1].S) ans.pb(cur1++);
		fid.pb(fd[idx1++]);

		while(idx1<sz(fd) && idx2<sz(sd))
		{
			rep(cnt,0,fd[idx1].S) ans.pb(cur1++);
			rep(cnt,0,sd[idx2].S) ans.pb(cur2++);
			fid.pb(mp(fd[idx1].F,fd[idx1].S+sd[idx2].S));
			idx1++;
			idx2++;
		}

		while(idx1<sz(fd))
		{
			rep(cnt,0,fd[idx1].S) ans.pb(cur1++);
			fid.pb(fd[idx1++]);
		} 
		while(idx2<sz(sd))
		{
			rep(cnt,0,sd[idx2].S) ans.pb(cur2++);
			fid.pb(sd[idx2++]);
		} 
	}

	assert(sz(ans)==n+m);

	vi ans2;
	vi pf(sz(fid));

	rep(i,0,sz(fid)) pf[i] = (i-1>=0?pf[i-1]:0) + fid[i].S;

	ll mn = (fid[0].F==sz(fid)%2?sz(fid):sz(fid)-1);
	rep(i,0,n+m) cout<<ans[i]+1<<" ";
	cout<<"\n"<<mn<<"\n";
	rep(i,0,mn) cout<<pf[i]<<" ";
	cout<<"\n";


	return 0;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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