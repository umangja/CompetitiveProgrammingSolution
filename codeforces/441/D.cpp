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

vvi cycles;
vpii ans;
ll n;
vi a;
vi b;
void add(ll k)
{

	ll idx=-1;
	rep(i,0,sz(cycles)) rep(j,0,sz(cycles[i])) if(cycles[i][j]==0) idx=i;

	set<ll> combined;
	combined.insert(idx);
	while(k--)
	{
		ll mn=inf;
		idx=-1;
		rep(i,0,sz(cycles)) if(combined.find(i)==combined.end()) rep(j,0,sz(cycles[i])) if(cycles[i][j]<mn) mn=cycles[i][j],idx=i;
		assert(mn!=inf);
		ans.pb(mp(0,mn));
		combined.insert(idx);
	}
}

void rem(ll k)
{
	ll mn = 0;
	// whatis(k);
	while(k)
	{
		ll idx = -1;
		rep(i,0,sz(cycles)) rep(j,0,sz(cycles[i])) if(cycles[i][j]==mn) idx=i;
		assert(idx!=-1);


		ll m=sz(cycles[idx]);
		if(m==1)
		{
			mn++;
			continue;
		}
		else
		{
			ll idx2 = -1;
			rep(i,0,sz(cycles[idx])) if(cycles[idx][i]==mn) idx2=i;

			ll mn2 = inf;
			ll idx3 = -1;
			rep(i,0,sz(cycles[idx])) if(i!=idx2 && cycles[idx][i]<mn2) mn2=cycles[idx][i],idx3=i;

			vi temp = cycles[idx];
			cycles.erase(cycles.begin()+idx);

			// whatis(idx2);
			// whatis(idx3);

			vi c1;
			ll cur = (idx2+1)%m;
			while(1)
			{
				c1.pb(temp[cur]);
				if(cur==idx3) break;
				else cur = (cur+1)%m;
			}

			// debug_v(c1);

			vi c2;
			cur = (idx3+1)%m;
			while(1)
			{
				c2.pb(temp[cur]);
				if(cur==idx2) break;
				else cur = (cur+1)%m;
			}

			cycles.pb(c1);
			cycles.pb(c2);


			ans.pb(mp(temp[idx2],temp[idx3]));
			k--;
			// debug_v_v(cycles);
		}

		
	}
}


int solve()
{
	cin>>n;
	a.resize(n);
	b.resize(n);
	rep(i,0,n)
	{
		cin>>a[i];
		a[i]--;
		b[a[i]]=i;
	} 

	ll m;cin>>m;
	vi vis(n,0);
	ll cur=0;
	rep(i,0,n)
	{
		if(vis[i]==0)
		{
			ll el = i;
			vi cycle;
			ll cnt=-1;
			while(vis[el]==0)
			{
				cnt++;
				vis[el]=1;
				cycle.pb(el);
				el = a[el];
			}
			cur+=cnt;
			cycles.pb(cycle);
		}
	}


	// debug_v_v(cycles);
	if(cur==m) 
	{
		cout<<"0\n";
		return 0;
	}
	else if(cur>m) rem(cur-m);
	else add(m-cur);
	// debug_vp(ans);

	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i].F+1<<" "<<ans[i].S+1<<" ";

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