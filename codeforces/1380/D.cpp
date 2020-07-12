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

bool win(char a,char b)
{
	if(a=='S' && b=='P') return 1;
	if(a=='P' && b=='R') return 1;
	if(a=='R' && b=='S') return 1;
	return  0;
}

char win2(char a)
{
	if(a=='S') return 'R';
	if(a=='P') return 'S';
	if(a=='R') return 'P';
	return 'a';
}

int solve()
{
	ll n,m,x,k,y,d;
	cin>>n>>m>>x>>k>>y;
	d=n-m;
	
	vi a(n+2,0),b(m+1,0);
	vi pos(n+1,0);
	rep(i,1,n+1) cin>>a[i],pos[a[i]]=i;
	rep(i,1,m+1) cin>>b[i];

	ll last = 0,possible=1;
	rep(i,1,m+1)
	{
		if(pos[b[i]]<=last) possible=0; 
		else last = pos[b[i]];
	} 
	if(d<0 || possible==0)
	{
		cout<<"-1\n";
		return 0;
	}

	if(d==0)
	{
		cout<<"0\n";
		return 0;
	}


	vpii del;
	rep(i,1,m+1)
	{
		ll R = pos[b[i]]-1;
		ll L = (i==1?1:pos[b[i-1]]+1);
		if(R>=L && R!=0) del.pb(mp(L,R));
	}

	if(pos[b[m]]!=n) del.pb(mp(pos[b[m]]+1,n));

	// debug_vp(del);

	ll ans=0;
	rep(i,0,sz(del))
	{
		ll L = del[i].F;
		ll R = del[i].S;

		ll mx = max(a[L-1],a[R+1]),idx = -1,len = R-L+1;
		rep(j,L,R+1) if(a[j]>mx) mx=a[j],idx=j;
		if(idx==-1)
		{
			ll t1 = len/k;
			ll t2 = len%k;

			ans+=min(k*y,x)*t1 + y*t2;
		}
		else
		{
			if(len<k)
			{
				cout<<"-1\n";
				return 0;
			}

			len-=k;
			ans+=x;
			ans += (len/k)*min(k*y,x) + (len%k)*y;

			// ll len1 = idx-L;
			// ll len2 = R-idx;

			// ans += (len1/k)*min(k*y,x);
			// ans += (len2/k)*min(k*y,x);

			// ll t1 = len1%k;
			// ll t2 = len2%k;
			// ll t3 = t1+t2+1;
			// ans += x + (t3-k)*y;
		}

	}

	cout<<ans<<"\n";
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
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}