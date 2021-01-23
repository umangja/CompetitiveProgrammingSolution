/*input
1
1 2
4
1
3 3
2
4 2
5
0 1
1 1
2 1
3 1
4 1

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

inline ll fun(ll x)
{
	if(x==-1) return 1;
	return -1;
}

int solve()
{
	ll n;cin>>n;
	vpii p(n);
	rep(i,0,n) cin>>p[i].F>>p[i].S;

	ll m;cin>>m;
	vi Mx(m+1,1),My(m+1,1),Ax(m+1,0),Ay(m+1,0),s(m+1,0);
	rep(i,1,m+1)
	{
		ll t;cin>>t;


		if(t==1){
			// x,y --> y,-x
			s[i]=s[i-1]^1;

			Mx[i] = My[i-1];
			Ax[i] = Ay[i-1];

			My[i] = -1*Mx[i-1];
			Ay[i] = -1*Ax[i-1];				
		}
		else if(t==2)
		{
			// x,y --> -1*y,x 
			s[i]=s[i-1]^1;
			

			Mx[i] = -1*My[i-1];
			Ax[i] = -1*Ay[i-1];

			My[i] = Mx[i-1];
			Ay[i] = Ax[i-1];	
		}
		else
		{
			ll p;cin>>p;
			s[i]=s[i-1];
			if(t==3)
			{
				// x,y ---> 2*p - x , y

				Mx[i] = -1*Mx[i-1];
				Ax[i] = -1*Ax[i-1] + 2*p;

				My[i] = My[i-1];
				Ay[i] = Ay[i-1];	
			}
			else
			{
				// x,y ---> x,2*p-y

				Mx[i] = Mx[i-1];
				Ax[i] =  Ax[i-1];

				My[i] = -1*My[i-1];
				Ay[i] = -1*Ay[i-1]+2*p;
			}
		}

		// cout<<Mx[i]<<" "<<

	}

	ll q;cin>>q;
	rep(i,0,q)
	{
		ll op,x;cin>>op>>x; x--;
		if(s[op]) swap(p[x].F,p[x].S);
		cout<<Mx[op]*p[x].F+Ax[op]<<" "<<My[op]*p[x].S+Ay[op]<<"\n";
		if(s[op]) swap(p[x].F,p[x].S);
	}

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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}