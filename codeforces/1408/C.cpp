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
const double EPS = 1e-9;
ll n;
double l;
vector<double> a,t1,t2;



int solve()
{
	cin>>n>>l;
	a.assign(n+2,0.0);
	t1.assign(n+2,0.0);
	t2.assign(n+2,0.0);
	rep(i,1,n+1) cin>>a[i];
	a[n+1] = (double)l;
	
	t1[0] = 0;
	double s=1;
	rep(i,1,n+2)
	{
		double d = a[i]-a[i-1];
		t1[i] =  t1[i-1] + d/s;
		s++;
	}

	t2[n+1] =0;
	s =1;
	repr(i,n,-1)
	{
		double d = a[i+1] - a[i];
		t2[i] = t2[i+1] + d/s;
		s++;
	}

	// rep(i,1,n+1) cout<<t1[i]<<" ";cout<<"\n";
	// rep(i,1,n+1) cout<<t2[i]<<" ";cout<<"\n";

	double ans = -1;
	rep(i,0,n+1)
	{
		if(abs(t1[i]-t2[i])<=EPS)
		{
			ans = t1[i];
			break;
		}
		else if( (i+1<n+2 && t1[i+1]<t2[i+1]) )
		{
			continue;
		}
		else
		{
			ans = t1[i];
			
			double s1 = (double)i+1;
			double s2 = (double)n+2 - s1;

			double low = t1[i],high = t1[i+1];
			ll cnt=0;
			while(cnt++<2000)
			{
				double mid = low+(high-low)/2;
				// whatis(mid);
				double d1 = a[i] + (mid-t1[i])*s1;
				double d2 = (mid - t2[i+1])*s2 + l-a[i+1];
				if(d1+d2>=l) high = mid;
				else low = mid;
			}
			ans=low;
			break;
		}
	}

	cout<<setprecision(20)<<ans<<"\n";
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